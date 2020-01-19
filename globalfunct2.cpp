#include<iostream>
#include "AbstractBoard.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"
#include "BoardVector.h"

#include<string>
#include<fstream>


	using namespace frknboards;
	using namespace std;

	int main(){
		int secim;
		cout << "1:Boardarray2d      2:Boardarrya1d         3:Boardvector   "<<endl;
		cout <<	"Please select the number of the typename for a little testing programs "<<endl;
		cin>>secim;
		

		if(secim ==1){
		BoardArray2D twod;
		string fname = "shapefile1.txt";
			twod.readFromFile(fname);
			int i,j,x,y,size,randnum,o=0,resetcheck=0,movetemp=0,printcheck=1;
			char secim;
			twod.reset(resetcheck);
			cout << "------------CURRENT CONFIGURATION-----------\n\n";
			
			twod.print();
			cout << "--------------------------------------------\n\n";
		
			
			while(1){
			      cout   <<"\nM move \n"
				     <<"S setsize\n"
				     <<"E Asks a file name and saves the current board configuration as a loadable shapefile\n"
				     <<"O Asks a file name and loads the current board configuration from the shapefile\n"
				     <<"Q Quits the game\n"
				     << "Please enter your CHOICE: " ; 

				cin  >> secim;
				cout << "\n";
				if( secim == 'M'  || secim == 'm' ){
					twod.move(printcheck);}
				else if(secim=='E' || secim=='e' ){
					twod.writeToFile();
					}
				
				else if(secim=='S' || secim=='s' ){
					twod.setSize();
				}

			else if(secim=='O' || secim=='o' ){
				cout << "enter fname"<<endl;
				cin >> fname;	
				twod.readFromFile(fname);			
				twod.print();
				resetcheck=0;
				twod.reset(resetcheck);
			}

			else if(secim == 'Q' || secim == 'q'){
				cout <<"exiting,bye";
				return 0;
			}

			else{
				cout << "WRONG choice my friend,try AGAIN\n";
				}
			}//while curl



		}


		

		else if(secim ==2){
			BoardArray2D  oned;	
			string fname = "shapefile1.txt";

			oned.readFromFile(fname);
			 
					//we will use it for comparing with mtrx
			int i,resetcheck=0,movetemp=0,printcheck=1;
			char secim;
				oned.reset(resetcheck);

				cout << "------------CURRENT CONFIGURATION-----------\n\n";
				
				oned.print();
				cout << "--------------------------------------------\n\n";
			
				
			while(1){
			      cout   <<"\nM move \n"
				     <<"S setsize\n"
				     <<"E Asks a file name and saves the current board configuration as a loadable shapefile\n"
				     <<"O Asks a file name and loads the current board configuration from the shapefile\n"
				     <<"Q Quits the game\n"
				     << "Please enter your CHOICE: " ;  

				cin  >> secim;
				cout << "\n";
				if( secim == 'M'  || secim == 'm' ){
					oned.move(printcheck);}


				else if(secim=='E' || secim=='e' ){
					oned.writeToFile();
					}
				
				else if(secim=='S' || secim=='s' ){
					oned.setSize();
					}

				else if(secim=='O' || secim=='o' ){
					cout << "enter fname"<<endl;
					cin >> fname;	
					oned.readFromFile(fname);			
					oned.print();
					resetcheck=0;
					oned.reset(resetcheck);
				}

				else if(secim == 'Q' || secim == 'q'){
				cout <<"exiting,bye";
				return 0;
				}

				else{
				cout << "WRONG choice my friend,try AGAIN\n";
				}
			}//while curl
		}
		
		else if(secim ==3){
			BoardVector  vect;
			string fname = "shapefile1.txt";
			vect.readFromFile(fname);

			int i,resetcheck=0,printcheck=1;
			char secim;

				vect.reset(resetcheck);

				cout << "------------CURRENT CONFIGURATION-----------\n\n";
				
				vect.print();
				cout << "--------------------------------------------\n\n";
			
				
			while(1){
				     cout   <<"\nM move \n"
					     <<"S setsize\n"
					     <<"E Asks a file name and saves the current board configuration as a loadable shapefile\n"
					     <<"O Asks a file name and loads the current board configuration from the shapefile\n"
					     <<"Q Quits the game\n"
					     << "Please enter your CHOICE: " ; 

					cin  >> secim;
					cout << "\n";
					if( secim == 'M'  || secim == 'm' ){
						vect.move(printcheck);}

					else if(secim=='E' || secim=='e' ){
						vect.writeToFile();
						}
					
					else if(secim=='S' || secim=='s' ){
						vect.setSize();
						}

					else if(secim=='O' || secim=='o' ){
						cout << "enter fname"<<endl;
						cin >> fname;	
						vect.readFromFile(fname);			
						vect.print();
						resetcheck=0;
						vect.reset(resetcheck);
					}

					else if(secim == 'Q' || secim == 'q'){
					cout <<"exiting,bye";
					return 0;
					}

					else{
					cout << "WRONG choice my friend,try AGAIN\n";
					}
				}//while curl



			}
				
		}//main curl

		

bool checkmoves(AbstractBoard  *moves[] ){
	int i=0,j,x1,x2,y1,y2;
	bool flag;		
		/*
		for ( i = 0; i < height ; i++){
			for ( j = ; j < width; j++){
			*/

	while(moves[i] != NULL){//we compare the bb(blank) index,we use coordinates like  (y,x) ,
		x1= moves[i]->getx();		
		x2= moves[i-1]->getx();
		y1= moves[i]->gety();
		y2= moves[i-1]->gety();
		
			if(	(x1 -x2) <= 1 && (x1 -x2) >= -1  && y1 == y2)
					flag = true;
		
			else if((y1 -y2) <=1 && (y1 -y2) >= -1  && x1 == x2)
					flag = true;
					
			else 
				flag=false;

			i++;
		}

	return flag;
}





