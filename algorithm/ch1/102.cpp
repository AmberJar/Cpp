/*
  Word Puzzle problem
  from the example in figure 1.1
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "matrix.h"
#include<algorithm>

using namespace std;

const int MAXROWS = 4;
const int MAXCOLS = 4;

struct Orientation
{
	Orientation() : delRow(0), delCol(0) {}
Orientation operator() (int direction)
  {
    switch (direction)
   {
	case 0 : delRow = -1; delCol = -1; break;
	case 1 : delRow = -1; delCol =  0; break;
	case 2 : delRow = -1; delCol =  1; break;
	case 3 : delRow = 0; delCol =  -1; break;
	case 4 : delRow = 0; delCol =   1; break;
	case 5 : delRow = 1; delCol =  -1; break;
	case 6 : delRow = 1; delCol =   0; break;
	case 7 : delRow = 1; delCol =   1; break;
   }
	return *this;
  }
  int delRow;
  int delCol;
};

class Puzzle
{
public:
    Puzzle(int numRows, int numCols) 
    {	
		matrix<char> temp(numRows,numCols);
		puzzle= temp;
		initPuzzle();
	}
	Puzzle(int numRows , int numCols , vector<string> wordList) : dictionary(wordList)
    { 
	    matrix<char> temp(numRows,numCols);
		puzzle= temp;
		initPuzzle();
	}
	void solvePuzzle();
	void findWords(int startRow, int startCol, Orientation orient);
private:
   void initPuzzle();
   matrix<char> puzzle;
   vector<string> dictionary;
};

void Puzzle::initPuzzle()
{
  puzzle[0][0] = 't';
  puzzle[0][1] = 'h';
  puzzle[0][2] = 'i';
  puzzle[0][3] = 's';
  puzzle[1][0] = 'w';
  puzzle[1][1] = 'a';
  puzzle[1][2] = 't';
  puzzle[1][3] = 's';
  puzzle[2][0] = 'o';
  puzzle[2][1] = 'a';
  puzzle[2][2] = 'h';
  puzzle[2][3] = 'g';
  puzzle[3][0] = 'f';
  puzzle[3][1] = 'g';
  puzzle[3][2] = 'd';
  puzzle[3][3] = 't';
}

void Puzzle::solvePuzzle()
{
  Orientation orient;
  for ( auto startRow = 0; startRow < puzzle.numrows(); startRow++)
	  for ( auto startCol=0; startCol < puzzle.numcols(); startCol++)
		 for (auto i = 0; i < 8 ; i++)
			 findWords(startRow,startCol,orient(i));
}


void Puzzle::findWords(int startRow, int startCol, Orientation orient)
{
  string word ="";
 int row = startRow;
 int col = startCol;
 do
	 { 
		 word = word + puzzle[row][col];
		 if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end())
			 cout<<word<<" found starting at ("<<startRow<<","<<startCol<<")\n";
		 row += orient.delRow;
		 col += orient.delCol;
	 }  while (row > -1 && col > -1 && row < puzzle.numrows() && col < puzzle.numcols());
}

int main()
{
 string diction[] = {"this", "two", "fat", "fats", "at", "wad", "ad", "hat", "that", "his","is","it","ah"} ;
 vector<string> dictionary(diction,diction+ 12);
 Puzzle puzzle(MAXROWS, MAXCOLS, dictionary);

  puzzle.solvePuzzle();

  return 0;
}
