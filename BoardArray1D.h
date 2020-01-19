#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include<iostream>
#include "AbstractBoard.h"

namespace frknboards{
	class BoardArray1D : public AbstractBoard {//1D dynamic array class derived from abstract board

		public:
			BoardArray1D();
		
			BoardArray1D(int h,int w,char lmove,int nummove);
			
			BoardArray1D(const BoardArray1D& obj1d);
			
			BoardArray1D& operator =(const BoardArray1D& right);			

			int getsize()const;
			
			void setsize(int height,int width);	
				
			void print() override ;
		
			void readFromFile(string fname) override;
		
			void writeToFile() override ;

			void reset(int resetcheck) override ;

			void setSize()override ;

			void move(int printcheck) override ;

		    	bool isSolved() override ;

			int  operator () (const int index1,const int index2) ;

			friend bool operator == (const BoardArray1D &b1,const BoardArray1D &b2);

			~BoardArray1D();

		private:
			
			int size,c;//c for coordinate of the bb
			int  *mtrx1d,*goalmtrx1d;	
		
		};
}

#endif

