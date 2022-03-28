#include<iostream>
#include<vector>
#include<string>
std::string Getinterval(int flag,int target)
{
   std::string combat;
    if(flag==target)
    {
       combat+=std::to_string(flag)+','; 
    }
    else
    {
          if(target-flag>=2)
             {
             combat+=std::to_string(flag)+'-'+ std::to_string(target)+',';
             }
             else
             {
               while(flag<=target)
               {
                  combat+=std::to_string(flag)+',';
                  flag++;
               } 
             }
    }
    return combat;
}
std::string ranage_extraction(std::vector<int> args)
{
   std::string result;
   int flag=args[0];
   for(int i=1;i<args.size();i++)
   {
       if(args[i]!=args[i-1]+1) 
       {
         result+=Getinterval(flag,args[i-1]);
         flag=args[i];
       }
   }
   result+=Getinterval(flag,*(args.end()-1));
   result.pop_back();
   return result;
}
int main()
{
   std::vector<int> args={-3,-2,-1,2,10,15,16,18,19,20};
   std::cout<<ranage_extraction(args)<<std::endl;
   return 0;
}