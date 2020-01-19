#include<iostream>
#include "BoardArray2D.h"
#include "AbstractBoard.h"
#include<fstream>

//implementation of the abstract board class
namespace frknboards{


	BoardArray2D::BoardArray2D(){//default constructor	
		height = 9;
		width = 9;
		mtrx2d = new int * [height];
			for(int i=0;i<height;i++){
					mtrx2d[i] = new int [width];
				}

			goalmtrx2d = new int * [height];
			for(int i=0;i<height;i++){
					goalmtrx2d[i] = new int [width];

			boardnum++;
		
			}
	}
		
	BoardArray2D::BoardArray2D (int h,int w,char lmove,int nummove){
			height = h; width = w; lastmove=lmove; movenum =nummove;
			mtrx2d = new int * [height];
			for(int i=0;i<height;i++){
					mtrx2d[i] = new int [width];
				}

			goalmtrx2d = new int * [height];
			for(int i=0;i<height;i++){
					goalmtrx2d[i] = new int [width];
				}
			boardnum++;
						
			}

	BoardArray2D::BoardArray2D(const BoardArray2D& obj2d)
		:AbstractBoard(obj2d.height,obj2d.width ,obj2d	.lastmove,obj2d. movenum)
			 {
			 	mtrx2d = new int *[height];
				for(int i=0;i<height;i++){
					mtrx2d[i] = new int [width];
				}

				for (int i = 0; i < height; i++){
					for (int j = 0; j < height; j++){
				 	mtrx2d[i][j] = obj2d.mtrx2d[i][j];
				 		}
				}
			}

	
	BoardArray2D& BoardArray2D::operator =(const BoardArray2D& right){//overloaded assignment operator
	
		 if (height != right.height && width != right.width ){//we check for sending same,and prevent loss of data
			
			for(int i=0;i<height;i++){
					delete [] mtrx2d[i];
				}		 
			delete [] mtrx2d;

			mtrx2d = new int * [height];
			for(int i=0;i<height;i++){
					mtrx2d[i] = new int [width];
				}
		 }
			 height = right.height;
			width = right.width;
		
		 for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
			 mtrx2d[i][j] = right.mtrx2d[i][j];
			}
		 }	
			return *this;
	}

	BoardArray2D::~BoardArray2D() {//destructor for 2d dynamic matrix
				for(int i=0;i<height;i++){
					delete [] mtrx2d[i];
				}	
				delete [] mtrx2d;
	}
		
	void BoardArray2D::print(){ //printing matrix
	   	 int i,j,k=0;
				   
		for (i = 0; i < height; i++){		
			for (j = 0; j < width; j++){

				if(mtrx2d[i][j]== -2){//if it is 99 this means bb
					cout <<"bb"<<" ";
					x=j;
					y=i;
					}
				else{
	     				if((mtrx2d[i][j]/10)==0)
						cout<<"0"<< mtrx2d[i][j] << " ";
					else 
				cout<<mtrx2d[i][j] << " ";
				}
							
			}
		cout <<"\n"; 
	   	} 
	} 
	
	void BoardArray2D::readFromFile(string fname){
				int i,j;
				filename = fname;
				string line,temp;
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
								for(i=0;i<height;i++){//converting string array to mtrx2d
									for(j=0;j<width;j++){
										if(smtrx[i][j] == "bb"){ 
												mtrx2d[i][j]= -2;	//we assign for bb option 
													}
										else   mtrx2d[i][j]=stoi(smtrx[i][j]);//string to int
									}
								}
									return;
							}
						}   
					}
									
				}
					
				else { cout<< "wrong file name try it again later"<<endl;// if file name is wrong
						return ;	}
	}

	void BoardArray2D::writeToFile() {
		ofstream wfile;
		int i,j;
		cout << "enter the name of the file : ";
			cin >> filename;
		wfile.open(filename);

		if(wfile.is_open()){
			cout << "file is opened succesfully"<<endl;
			for(i=0;i<height;i++){
		            for (j = 0; j < width; j++){
				if(i==y && j==x){
				 wfile<<"bb";
					if(j!=width-1){wfile << " ";}//we dont want to put space end of line
				}
				else{
	     		         	if((mtrx2d[i][j]/10)==0){
						wfile <<"0"<< mtrx2d[i][j]; 
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
					else {
						wfile <<mtrx2d[i][j];
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
				   }
			    }
			   wfile <<'\n';						
			}
			wfile.close();
		}
	}

	void BoardArray2D::reset(int resetcheck)  {//finding the final board ascending 
		int i,j,k,l,m,n,b=0,a=0;
		int temp;
		//filling goal array with initial array,we dont change initial; 
		for (k = 0; k < height; k++){
			for (m = 0; m < width; m++){
				goalmtrx2d[k][m]=mtrx2d[k][m];
			}
		}
		
		for (k = 0; k < height; k++){//sorting array
			for (m = 0; m < width; m++){
			    n = m+1;
			    for ( i = k; i < height ; i++){
				for ( j = n; j < width; j++){
				    if(goalmtrx2d [k][m]!= 0 && goalmtrx2d [i][j]!= 0  ){//we dont change 00 's
					if (goalmtrx2d [k][m] > goalmtrx2d [i][j]){
					temp=goalmtrx2d [k][m]; 
					goalmtrx2d [k][m]=goalmtrx2d [i][j];
					goalmtrx2d [i][j]=temp;     
					}
				    }
				}
				n=0;
			    } 
			}
		}
	     if(resetcheck==1){//if we use this function just for finding goalmatrix we must know that
		for (k = 0; k < height; k++){//if we want reset mtrx then this resetting main matrix to goal
			for (m = 0; m < width; m++){
				mtrx2d[k][m]=goalmtrx2d[k][m];
			}
		}
	     }


	}

	void BoardArray2D::setSize(){//if user didnt use command line, we use this function
		int i,j,num=1;

		for(int i=0;i<height;i++){//deleting previous datas
			delete [] mtrx2d[i];
			}
			delete [] mtrx2d;		

		cout<< "Enter height: "<<endl;
		cin >> height;
		cout<< "Enter width: "<<endl;
		cin >> width;
		
		
			mtrx2d = new int * [height];
			cout<< "sette 1.new sonrası: "<<endl;
			for(int i=0;i<height;i++){
					mtrx2d[i] = new int [width];
				}

		for(i=0;i<height;i++){//filling array with solution (we dont use reset because of this)
			for(j=0;j<width;j++){
				if(i == height-1 && j == width-1){ 
					mtrx2d[i][j]= -2;//we declare -2 for bb 
					}		
				else	{mtrx2d[i][j] = num;}
					num=num+1;
			}
		}
		
		print();

	}

	void BoardArray2D::move(int printcheck) {
			
		
		int resetcheck=0,temp;
		char secim;
			cout << "Please enter the move direction : ";
			cin >> secim;
			reset(resetcheck);//for getting goalmatrix
			
				 
		if( secim == 'L'  || secim == 'l' ){

			if(x>0 && y< height && mtrx2d[y][x-1] != 0){
				temp=mtrx2d[y][x];
				mtrx2d[y][x]=mtrx2d[y][x-1];
				mtrx2d[y][x-1]=temp;				
				x=x-1;				
				movenum=movenum+1;			
				if(isSolved()== true ){
					cout <<"Problem solved"<<endl<<"Total number of moves: "<< movenum <<endl;					
					}
			if(printcheck==1){			
				print();}
				}
				
			else{ cout <<"\n you CAN'T use this move,NOT VALID\n";   }
		}
		else if(secim=='R' || secim=='r' ){
			if(x<width-1 && y<height && mtrx2d[y][x+1] != 0){
				temp=mtrx2d[y][x];
				mtrx2d[y][x]=mtrx2d[y][x+1];
				mtrx2d[y][x+1]=temp;
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

			if(x>=0 && y>0 && mtrx2d[y-1][x] != 0){
				temp=mtrx2d[y][x];
				mtrx2d[y][x]=mtrx2d[y-1][x];
				mtrx2d[y-1][x]=temp;
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
			if(x>=0 && y<height-1 && mtrx2d[y+1][x] != 0){
				temp=mtrx2d[y][x];
				mtrx2d[y][x]=mtrx2d[y+1][x];
				mtrx2d[y+1][x]=temp;
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

    	bool BoardArray2D::isSolved() {//comparing current matrix with goal
		int i,j,k,counter=0;
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(goalmtrx2d[i][j]==mtrx2d[i][j]){
				counter++;		
				}				
			}
		}
		if(counter== height * width) return true;

		else 	return false;

	}
	
	int  BoardArray2D::operator () (const int index1,const int index2) { //we use this operator for get mtrx[index1][index2] 's value  
		
		int x,y,index1d;
			
		if (index1 >= height || index2 >= width ){
			cout << "wrong index for boardarray1d ,try it again later"<<endl;
			return 0;
		}
			
		else {
			return mtrx2d[index1][index2];
		}
	

	}


}//namespace curl





