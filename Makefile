
output:  AbstractBoard.o BoardArray1D.o  BoardVector.o globalfunct2.o  BoardArray2D.o 
	g++ AbstractBoard.o BoardArray1D.o  BoardVector.o globalfunct2.o  BoardArray2D.o  -o output

#there are another two driver inside 1d and vector if you want to use them you can erase  this /*  */ for them 

AbstractBoard.o: AbstractBoard.h AbstractBoard.cpp
	g++ -c AbstractBoard.cpp

BoardArray2D.o: BoardArray2D.h BoardArray2D.cpp 
	g++ -c BoardArray2D.cpp

BoardArray1D.o: BoardArray1D.h BoardArray1D.cpp
	g++ -c BoardArray1D.cpp

BoardVector.o: BoardVector.h BoardVector.cpp
	g++ -c BoardVector.cpp

globalfunct2.o: globalfunct2.cpp
	g++ -c globalfunct2.cpp

clean: 
	rm *.o output






