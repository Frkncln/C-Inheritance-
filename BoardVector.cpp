#include<iostream>
#include<fstream>
#include "BoardVector.h"
#include "AbstractBoard.h"
//implementation of the  boardvector class


namespace frknboards{


	BoardVector::BoardVector():AbstractBoard(){
		mtrx.resize(9); //size of matrix is 9x9
		for (int i = 0; i < mtrx.size(); i++)
  		mtrx[i].resize(9);
		
		goalmtrx.resize(9);
		for (int i = 0; i < goalmtrx.size( ); i++)
 		goalmtrx[i].resize(9);
		boardnum++;
		}
			
	BoardVector::BoardVector(vector<vector<int>> &mtrx,const int height,const int width,char lastmove,int  movenum)
			:AbstractBoard(height,width,lastmove,movenum){
		
		mtrx.resize(9); //size of matrix is 9x9
		for (int i = 0; i < mtrx.size(); i++)
  		mtrx[i].resize(9);
		
		goalmtrx.resize(9);
		for (int i = 0; i < goalmtrx.size( ); i++)
 		goalmtrx[i].resize(9);
		boardnum++;
	
	}


	void BoardVector::print(){ //printing matrix
	    int i,j;
	    for (i= 0; i < height; i++) 
		{	 
			for (j = 0; j < width; j++){

				if(mtrx[i][j]== -2){//if it is -2 this means bb
					cout <<"bb"<<" ";
						y=i;
						x=j;
					}
				else{
	     		         	if((mtrx[i][j]/10)==0)
						cout<<"0"<< mtrx[i][j] << " ";
					else 
						cout<< mtrx[i][j] << " ";
				}
			} 
		cout <<"\n"; 
	    	} 	
	} 
	
	void BoardVector::readFromFile(string fname){
				int i,j;
				string line,temp;
				filename = fname;
				ifstream rfile;
				rfile.open(filename);
					
				if(rfile.is_open()){
					cout << "file is opened succesfully"<<endl;
					for(i=0;i<10;i++){
						for(j=0;j<10;j++){
							if(rfile.peek() != EOF){
									if(rfile.peek() == '\n'){ //if line is end,then go next line
										width=j;
										i++;
										j=0;
										rfile >> smtrx[i][j];	
									}						
									else {	rfile >> smtrx[i][j];
										}
												
							}
							else {	 
									height=i;
									cout<< "height of file is=" << height <<" width of file= "<<width<<endl<<endl;
									rfile.close();
									for(i=0;i<height;i++){//converting string array to mtx2d
										for(j=0;j<width;j++){
											if(smtrx[i][j] == "bb"){ 
													mtrx[i][j]= -2;	//we assign for bb option 
														}
											else   mtrx[i][j]=stoi(smtrx[i][j]);//string to int
										}
									}
									return ; 
								}
							}        
						}
									
					

						
				}
					
				else { cout<< "wrong file name try it again later"<<endl;// if file name is wrong
						return ;	}
			}


	void BoardVector::writeToFile() {
		ofstream wfile;
		int i,j;
		cout << "enter the name of the file : ";
			cin >> filename;
		wfile.open(filename);

		if(wfile.is_open()){
			cout << "file is opened succesfully"<<endl;
			for(i=0;i<height;i++){
		            for(j=0;j<width;j++){
				if(i==y && j==x){
				 wfile<<"bb";
					if(j!=width-1){wfile << " ";}//we dont want to put space end of line
				}
				else{
	     		         	if((mtrx[i][j]/10)==0){
						wfile <<"0"<< mtrx[i][j]; 
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
					else {
						wfile <<mtrx[i][j];
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
				   }
			    }
			   wfile <<'\n';						
			}
			wfile.close();
		}
	}

	void BoardVector::reset(int resetcheck)  {//finding the final board ascending 
		int i,j,k,l,m,n;
		int temp;
		//filling goal array with initial array,we dont change initial; 
		for (k = 0; k < height; k++){
			for (m = 0; m < width; m++){
				goalmtrx[k][m]=mtrx[k][m];
			}
		}
			
			for (k = 0; k < height; k++){//sorting array
				for (m = 0; m < width; m++){
				    n = m+1;
				    for ( i = k; i < height ; i++){
					for ( j = n; j < width; j++){
					    if(goalmtrx [k][m]!= 0 && goalmtrx [i][j]!= 0  ){//we dont change 00 's
						if (goalmtrx [k][m] > goalmtrx [i][j]){
						temp=goalmtrx [k][m]; 
						goalmtrx [k][m]=goalmtrx [i][j];
						goalmtrx [i][j]=temp;     
						}
					    }
					}
					n=0;
				    } 
				}
			}
	     if(resetcheck==1){//if we use this function just for finding goalmatrix we dont use this section
		for (k = 0; k < height; k++){//if we want reset mtrx then this resetting main matrix to goal
			for (m = 0; m < width; m++){
				mtrx[k][m]=goalmtrx[k][m];
			}
		}
	     }
	}

	void BoardVector::setSize() {//if user didnt use comman line, we use this function
		int i,j,num=1;
		cout<< "Enter height: "<<endl;
		cin >> height;
		cout<< "Enter width: "<<endl;
		cin >> width;
		
		mtrx.resize(height); //size of matrix is 9x9
		for (int i = 0; i < mtrx.size(); i++)
  		mtrx[i].resize(width);

		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(i == height-1 && j == width-1 ){ mtrx[i][j]= -2;//we declare -2 for bb 
					  }			
				else	{mtrx[i][j]=num;}
					num=num+1;		
			}
		}
		print();

	}

	void BoardVector::move(int printcheck) {
			
		
		int resetcheck=0,temp;
		char secim;
			cout << "Please enter the move direction : ";
			cin >> secim;
			reset(resetcheck);//for getting goalmatrix
		if( secim == 'L'  || secim == 'l' ){

				if(x>0 && y< height && mtrx[y][x-1] != 0){
					temp=mtrx[y][x];
					mtrx[y][x]=mtrx[y][x-1];
					mtrx[y][x-1]=temp;				
					x=x-1;				
					movenum=movenum+1;			
					if(isSolved()== true ){
						cout <<"Problem solved"<<endl<<"Total number of moves: "<< movenum<<endl;
						}
				if(printcheck==1){			
					print();}
					}
					
				else{ cout <<"\n you CAN'T use this move,NOT VALID\n";   }
			}
			else if(secim=='R' || secim=='r' ){
				if(x<width-1 && y<height && mtrx[y][x+1] != 0){
					temp=mtrx[y][x];
					mtrx[y][x]=mtrx[y][x+1];
					mtrx[y][x+1]=temp;
					x=x+1;				
					movenum=movenum+1;			
					if(isSolved()== true){
						cout <<"Problem solved"<<endl<<"Total number of moves: "<< movenum <<endl;	
						}				
					if(printcheck==1){			
					print();}
					}

				 else{ cout <<"\n you CAN'T use this move,NOT VALID\n";   }

			}
			else if(secim=='U' || secim=='u' ){

				if(x>=0 && y>0 && mtrx[y-1][x] != 0){
					temp=mtrx[y][x];
					mtrx[y][x]=mtrx[y-1][x];
					mtrx[y-1][x]=temp;
					y=y-1;				
					movenum=movenum+1;				
					if(isSolved()== true){
						cout <<"Problem solved"<<endl<<"Total number of moves: " << movenum <<endl;
						}
					if(printcheck==1){			
					print();}				
					}
				
				else{ cout <<"\n you CAN'T use this move,NOT VALID\n";   }

			}

			else if(secim=='D' || secim=='d' ){
				if(x>=0 && y<height-1 && mtrx[y+1][x] != 0){
					temp=mtrx[y][x];
					mtrx[y][x]=mtrx[y+1][x];
					mtrx[y+1][x]=temp;
					y=y+1;				
					movenum=movenum+1;			
				if(isSolved()== true){
					cout <<"Problem solved"<<endl<<"Total number of moves: " << movenum<<endl;
				}			
					if(printcheck==1){			
					print();}			
				}
			else{ cout <<"\n you CAN'T use this move,NOT VALID\n";   }

			}
	}

    	bool BoardVector::isSolved() {//comparing current matrix with goal
		int i,j,k,counter=0;
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if( goalmtrx[i][j]==mtrx[i][j]){
					counter++;		
				}		
			}
		}
		if(counter== height * width) return true;

		else 	return false;

	}
	
	int  BoardVector::operator () (const int index1,const int index2) { //we use this operator for get mtrx[index1][index2] 's value  
		
		int x,y,index1d;
			
		if (index1 >= height || index2 >= width ){
			cout << "wrong index for boardarray1d ,try it again later"<<endl;
		}
			
		else {
			return mtrx[index1][index2];		
		}
	

	}
		

		
	bool operator == (const BoardVector &b1,const BoardVector &b2){
		int flag ;	
		if(b1.height == b2.height && b1.width == b2.width){
			for(int i=0 ;i< b1.height ;i++){
				for(int j=0 ;j< b1.width ;j++){
					
					if(b1.mtrx[i][j] == b2.mtrx[i][j])
						flag=1;
					
					else 
						flag = 0;
				}

			}

			if(flag == 1)
				return true;
			else 
				return false;
		}

		else
			return false;			
		}


	}


