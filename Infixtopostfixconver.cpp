#include<iostream>
#include<string>
#include<stack>
void operator_postfix(std::stack<char>& operators,std::stack<std::string>& number)
{
	 std::string combat;
     combat=number.top()+combat;
	 number.pop();
	 combat=number.top()+combat;
	 number.pop();
	 combat+=operators.top();
	 operators.pop();
	 number.push(combat);
}
std::string to_postfix(std::string infix)
{
  std::stack<char> operators;
  std::stack<std::string> number;
  std::string result;
  for(auto ch:infix)
  {
	std::string sh;
	sh+=ch;
    if(ch<='9'&&ch>='0') number.push(sh);//if ch is a number,push stack directly
    else
    {
     if(ch=='^'||ch=='(') operators.push(ch);//if ch is '^' or '(',push stack directly too.
     else if(ch=='+'||ch=='-')//when ch is '+' or '-'
     {
	 if(operators.empty()) operators.push(ch);//if empty,push stack directly
	 else //if(operators.top()!='+'||operators.top()!='-')
	 {
	    while(!operators.empty()&&operators.top()!='(')
	    {
        operator_postfix(operators,number);
	    }
	    operators.push(ch);
	 } 
     }
     else if(ch=='*'||ch=='/')
     {
	 if(!operators.empty()&&(ch=='^'||ch=='*'||ch=='/'))
	 {
        while(!operators.empty()&&(operators.top()=='^'||operators.top()=='/'||operators.top()=='*'))
	   {
       operator_postfix(operators,number);
	   }
	 }
	 operators.push(ch);
     }
     else if(ch==')')
     {
        while(operators.top()!='(')
	{
         operator_postfix(operators,number);
	}
	operators.pop();
     }
    }
  }
  while(!operators.empty())
  { 
	 operator_postfix(operators,number);
  }
  result=number.top();
  return result;
}
int main()
{
  std::string infix="1^2^3";
  std::cout<<to_postfix(infix)<<std::endl;

}
