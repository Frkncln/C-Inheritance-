#include<iostream>
#include "AbstractBoard.h"
#include<string>
#include<fstream>
//implementation of the abstract board class
namespace frknboards{
			
			int AbstractBoard::getmovenum ()const{
				return movenum;
			}

			int AbstractBoard::getheight ()const{
				return height;
			}
			int AbstractBoard::getwidth ()const{
				return width;
			}
			string AbstractBoard::getfilename ()const{
				return filename;
			}			
			
			int AbstractBoard::getx() const{
				return x;
			}

			int AbstractBoard::gety() const{
				return y;
			}


			void AbstractBoard::setmovenum (int nummove){
				movenum = nummove;
			}
			void AbstractBoard::setheight (int newh){
				height = newh;
			}

			void AbstractBoard::setwidth (int neww){
				width= neww;
			}

			void AbstractBoard::setfilename (string fname){
				filename= fname;
			}

			char AbstractBoard::lastMove()const{
				if (movenum == 0)
					return 'S';
				else 
					return lastmove;			
			}

			int AbstractBoard::NumberofBoards() const{
				return boardnum;
			}
	
			int AbstractBoard::numberofmoves() const{
				return movenum;
			}

			bool operator == (const AbstractBoard &b1,const AbstractBoard &b2){
				int flag ;	
				if(b1.height == b2.height && b1.width == b2.width){
							
							if(b1.x == b2.x && b1.y == b2.y)
								flag=1;
							
							else 
								flag = 0;
						}
					if(flag == 1)
						return true;
					else 
						return false;
			}

			
}//namespace curl









