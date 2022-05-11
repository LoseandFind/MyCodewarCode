#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool validSolution(unsigned int board[9][9])
{
   for(unsigned int i=0;i<3;i++)
  {
    unsigned int row_01=i*3,row_02=i*3+1,row_03=i*3+2;
    unordered_set<int> elems;
    for(unsigned int j=0;j<3;j++)
   {
     unsigned int y_01=j*3,y_02=j*3+1,y_03=j*3+2;
     elems.insert(board[row_01][y_01]);
     elems.insert(board[row_01][y_02]);
     elems.insert(board[row_01][y_03]);
     elems.insert(board[row_02][y_01]);
     elems.insert(board[row_02][y_02]);
     elems.insert(board[row_02][y_03]);
     elems.insert(board[row_03][y_01]);
     elems.insert(board[row_03][y_02]);
     elems.insert(board[row_03][y_03]);
     if(elems.count(0)||elems.size()<9) return false;
     elems.clear();
   }
  }
  return true;
}
