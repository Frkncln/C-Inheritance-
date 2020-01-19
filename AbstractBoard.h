#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H

#include<iostream>
#include<string>

using namespace std;

namespace frknboards{

	class AbstractBoard{

		public://AbstractBoard public
			AbstractBoard () :height(0),width(0),lastmove('S')
			{	
				}

			AbstractBoard (int h,int w,char lastm,int moven) :height(h),width(w)
			,lastmove(lastm),movenum(moven)
			{
				}

			int getmovenum () const;

			int getheight () const;

			int getwidth () const;
			
			int getx() const;

			int gety() const;	
		
			string getfilename()const ;


			void setmovenum (int nummove);

			void setheight (int newh);

			void setwidth (int neww);
			
			void setfilename(string fname);
			
			void setnumboard();

			virtual void print() = 0;

			virtual void readFromFile(string fname) =0;

			virtual void writeToFile()=0;


			virtual void reset(int resetcheck) = 0;

			virtual void setSize() =0;

			virtual void move(int printcheck) =0;

		    	
			virtual bool isSolved()=0;


			int  operator () (const int index1,const int index2) ;

			friend bool operator == (const AbstractBoard &b1,const AbstractBoard &b2);
			
	
			int NumberofBoards()const;

			char lastMove()const;

			int numberofmoves() const;

			
		protected://AbstractBoard private

			int movenum,height,width;
			int boardnum;//we use that for count the numberofboards
			char lastmove;
			int x,y;//using for bb coordinates
			string smtrx[9][9],filename;//for reading from file
		
		};//abstractboard curl

	
}

			
#endif //AbstractBoard




	
	

	


























