#include<iostream>
#include<cmath>
#include<string>
bool Isornot(int n)
{
   for(int i=2;i<n;i++)
   {
      if(n%i==0) return false;
   }
   return true;
}
int main()
{
    int n=3990;//you can chage number by yourself
    std::string result;
    for(int i=2;i<=n;i++)
    {
       if(i==2||i%2!=0)
       {
	   if(i==2||Isornot(i))
	    {
		 int number=0;
		 int start=1;
	         while(pow(i,start)<=n)
		 {
		    number+=n/pow(i,start);
		    start++;
		 }
		 if(number>=2)  result=result+std::to_string(i)+'^'+std::to_string(number)+" * ";
	         else result=result+std::to_string(i)+" * ";	 
	    }
       }
    }
    result.pop_back();
    result.pop_back();
    result.pop_back();
    std::cout<<result<<std::endl;
}
