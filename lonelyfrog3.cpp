#include<iostream>
using namespace std;
unsigned jumpTo(unsigned x,unsigned y)
{
    unsigned result=0;
    while(y>x)
    {
      if(y%2!=0) y--;
      else
      {
        if(y/2>=x) y=y/2;
        else y--;
      }
      result++;
    }
 return result;
}
int main()
{
  std::cout<<jumpTo(10,19)<<std::endl;
  return 0;
}
