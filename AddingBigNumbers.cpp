#include<iostream>
#include<string>
int ChangeNumber(char sh)
{
   return (sh-'0');
}
char changeChar(int num)
{
   return( '0'+num);
}
std::string add(const std::string& a,const std::string& b)
{
    if(a.length()==0&&b.length()!=0) return b;
    else if(a.length()!=0&&b.length()==0) return a;
    else if(a.length()==0&&b.length()==0) return "";
    std::string result;
    int n=0;
    int left=a.length()-1;
    int right=b.length()-1;
    while(left>=0||right>=0)
    {
	 if(left>=0&&right>=0)
	 {
        int num=ChangeNumber(a[left])+ChangeNumber(b[right])+n;
	   n=num/10;
	   num=num%10;
	   result=changeChar(num)+result;
	   left--;
	   right--;
	 }
	 else if(left<0&&right>=0)
	 {  
        int num=ChangeNumber(b[right])+n;
	   n=num/10;
	   num=num%10;
	   result=changeChar(num)+result;
	   right--;
	 }
	 else if(left>=0&&right<0)
	 {
        int num=ChangeNumber(a[left])+n;
	   n=num/10;
	   num=num%10;
	   result=changeChar(num)+result;
	   left--;
	 }
    }
    if(n!=0) result=changeChar(n)+result;
    return result;
}
int main()
{
   std::string a="9999",b="1111";
   std::cout<<add(a,b)<<std::endl;
}
