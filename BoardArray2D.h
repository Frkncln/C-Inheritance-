#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include<iostream>
#include "AbstractBoard.h"

namespace frknboards{
	class BoardArray2D : public AbstractBoard {//2d dynamic array class derived from abstract board
	   
			public:
			BoardArray2D ();//default constructor	
			
			BoardArray2D (int h,int w,char lmove,int nummove);

			BoardArray2D(const BoardArray2D& obj2d);
			
			BoardArray2D& operator =(const BoardArray2D& right);
	    			
			void print() override ;

			void writeToFile() override ;

			void readFromFile(string fname) override;

			void reset(int resetcheck) override ;

			void setSize()override ;

			void move(int printcheck) override ;

		    	bool isSolved() override ;

			int  operator () (const int index1,const int index2);
		
			friend bool operator == (const BoardArray2D &b1,const BoardArray2D &b2);

			~BoardArray2D();
			
			//void driver2d();//we use that for little test driver
			
		 private:
		
			
	    	int  **mtrx2d;
		int  **goalmtrx2d;	

		};//end of the 2d class 


}





#endif

