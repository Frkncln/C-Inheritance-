#include<iostream>
#include<fstream>
#include "BoardArray1D.h"
#include "AbstractBoard.h"
	
//implementation of the abstract board class
namespace frknboards{

	
	BoardArray1D::BoardArray1D(){//default constructor	
		height = 9;
		width = 9;
		size =	height*width; 
		mtrx1d = new int [size];
		goalmtrx1d=new int [size];
		boardnum++;
	}


		
	BoardArray1D::BoardArray1D(int h,int w,char lmove,int nummove)
			:AbstractBoard(h,w,lmove,nummove){
			size =	h*w; 
			mtrx1d = new int [size];
			goalmtrx1d=new int [size];
			boardnum++;
			}
				

	int BoardArray1D::getsize()const{
			return size;		
		}
			
	void BoardArray1D::setsize(int height,int width){
			
			size = height * width;

		}
	//copy constructor
	BoardArray1D::BoardArray1D(const BoardArray1D& obj1d):size(obj1d.getsize( )){
			 mtrx1d = new int[size];
			 for (int i = 0; i < size; i++)
			 mtrx1d[i] = obj1d.mtrx1d[i];

			}
	
	
	BoardArray1D& BoardArray1D::operator =(const BoardArray1D& right){//overloaded assignment operator
		 if (size != right.size){
			 delete [] mtrx1d;
			 mtrx1d = new int[right.size];
		 }
			 size = right.size;
			
		 for (int i = 0; i < size; i++)
			 mtrx1d[i] = right.mtrx1d[i];

			 return *this;
		}
		

	
		//1d destructor
	BoardArray1D::~BoardArray1D() {//destructor for 1d dynamic matrix
			delete [] mtrx1d;
			}

		
	void BoardArray1D::print(){ //printing matrix
	   	 int i,j,k=0;
				   
		for (i = 0; i < height; i++){		
			for (j = 0; j < width; j++){

				if(mtrx1d[k]== -2){//if it is 99 this means bb
					cout <<"bb"<<" ";
						c=k; 
					}
				else{
	     		if((mtrx1d[k]/10)==0)
						cout<<"0"<< mtrx1d[k] << " ";
					else 
						cout<< mtrx1d[k] << " ";
				}
				
			   k++;			
			} 
		cout <<"\n"; 
	    	} 
	} 
		
	void BoardArray1D::readFromFile(string fname){
				int i,j,k=0;
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
													mtrx1d[k]= -2;	//we assign for bb option 
														}
											else   mtrx1d[k]=stoi(smtrx[i][j]);//string to int
											k++;//we use that for 1d array
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

	void BoardArray1D::writeToFile() {
		ofstream wfile;
		int i,j,k=0;
		cout << "enter the name of the file : ";
			cin >> filename;
		wfile.open(filename);

		if(wfile.is_open()){
			cout << "file is opened succesfully"<<endl;
			for(i=0;i<height;i++){//height yerine size vardý çalýþmýosa bi dene onuda
		            for (j = 0; j < width; j++){
				if(k==c){
				 wfile<<"bb";
					if(j!=width-1){wfile << " ";}//we dont want to put space end of line
				}
				else{
	     		         	if((mtrx1d[k]/10)==0){
						wfile <<"0"<< mtrx1d[k]; 
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
					else {
						wfile <<mtrx1d[k];
						if(j!=width-1){wfile << " ";}//we dont want to put space end of line
					}
				   }
				k++;
			    }
			   wfile <<'\n';						
			}
			wfile.close();
		}
	}

	void BoardArray1D::reset(int resetcheck)  {//finding the final board ascending 
		int i,j,k,l,m,n,b=0,a=0;
		int temp;
		
		//filling goal array with initial array,we dont change initial;
		for (k = 0; k < size; k++){
			
				goalmtrx1d[k]=mtrx1d[k];
			
		}
			
			for (k = 0; k < height; k++){//sorting array
				for (m = 0; m < width; m++){
				    n = m+1;
				    for ( i = k; i < height ; i++){
					for ( j = n; j < width; j++){
					    if(goalmtrx1d [a]!= 0 && goalmtrx1d[b]!= 0  ){//we dont change 00 's
						if (goalmtrx1d [a] > goalmtrx1d [b]){
						temp=goalmtrx1d [a]; 
						goalmtrx1d [a]= goalmtrx1d [b];
						goalmtrx1d [b]=temp;     
						}
					    }
					b++;						
					}
					n=0;
				    }
				a++;	 
				}
			}
	     if(resetcheck==1){//if we use this function just for finding goalmatrix we dont use this section
		a=0;			
		for (k = 0; k < height; k++){//if we want reset mtrx1d then this resetting main matrix to goal
			for (m = 0; m < width; m++){
				mtrx1d[a]=goalmtrx1d[a];
				a++;	
			}
		}
	     }
	}

	void BoardArray1D::setSize() {//if user didnt use comman line, we use this function
		int i,j,k=0,num=1;
		delete [] mtrx1d;
		cout<< "Enter height: "<<endl;
		cin >> height;
		cout<< "Enter width: "<<endl;
		cin >> width;
		
		size =	height*width; 
		mtrx1d = new int[size];

		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(i == height-1 && j == width-1 ){ mtrx1d[k]= -2;//we declare -2 for bb 
					  }			
				else	{mtrx1d[k]=num;}
					num=num+1;		
					k=k+1;			
			}
		}
		print();

	}

	void BoardArray1D::move(int printcheck) {
			
		
		int resetcheck=0,temp;
		char secim;
			cout << "Please enter the move direction : ";
			cin >> secim;
			reset(resetcheck);//for getting goalmatrix
		if( secim == 'L'  || secim == 'l' ){
				if( (c+1) % width != 1 && mtrx1d[c-1] != 0){
					temp=mtrx1d[c];
					mtrx1d[c]=mtrx1d[c-1];
					mtrx1d[c-1]=temp;			
					c=c-1;
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
				if((c+1) % width !=0 && mtrx1d[c+1] != 0){
					temp=mtrx1d[c];
					mtrx1d[c]=mtrx1d[c+1];
					mtrx1d[c+1]=temp;				
					c=c+1;				
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

				if( c > width -1&& mtrx1d[c-width] != 0){
					temp=mtrx1d[c];
					mtrx1d[c]=mtrx1d[c-width];
					mtrx1d[c-width]=temp;
					c=c-width;				
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
				if(c <size - width &&  mtrx1d[c+width] != 0){
					temp=mtrx1d[c];
					mtrx1d[c]=mtrx1d[c+width];
					mtrx1d[c+width]=temp;
					c=c+width;				
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

    	bool BoardArray1D::isSolved() {//comparing current matrix with goal
		int i,j,k,counter=0;
		for(i=0;i<size;i++){
			
				if( goalmtrx1d[i] == mtrx1d[i]){
					counter++;		
				}		
			
		}
		if(counter== height * width) return true;

		else 	return false;

	}

	int  BoardArray1D::operator () (const int index1,const int index2) { //we use this operator for get mtrx[index1][index2] 's value  
		
		int x,y,index1d;
			
		if (index1 >= height || index2 >= width ){
			cout << "wrong index for boardarray1d ,try it again later"<<endl;
		}
			
		else {
			index1d = width*index1 + index2;			
			return 	mtrx1d [index1d];		
		}
	

	}

	bool operator == (const BoardArray1D &b1,const BoardArray1D &b2){
		int flag,k=0;	
		if(b1.height == b2.height && b1.width == b2.width){
			for(int i=0 ;i< b1.height ;i++){
				for(int j=0 ;j< b1.width ;j++){
					
					if(b1.mtrx1d[k] == b2.mtrx1d[k])
						flag=1;
					
					else 
						flag = 0;
					
					k++;
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

	

	



}//frknboards curl



