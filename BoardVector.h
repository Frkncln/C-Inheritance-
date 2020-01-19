#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H

#include<iostream>
#include<vector>
#include "AbstractBoard.h"

namespace frknboards{
	class BoardVector : public AbstractBoard {//vector board derived from abstract board

		
		public:
			BoardVector();
			
			BoardVector(vector<vector<int>> &mtrx,const int height,const int width,char lastmove,int movenum);
			
			void print() override ;

			void writeToFile() override ;

			void readFromFile(string fname) override;

			void reset(int resetcheck) override ;

			void setSize()override ;

			void move(int printcheck) override ;

		    	bool isSolved() override ;

			int  operator () (const int index1,const int index2);

			friend bool operator == (const BoardVector &b1,const BoardVector &b2);

		private:

		vector<vector<int>> mtrx;//our 2d vector
			
		vector<vector<int>> goalmtrx;//for compare
		
	};

}
#endif
