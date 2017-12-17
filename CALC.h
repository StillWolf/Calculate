#ifndef _SCLASS_CALCULATOR_H_
#define _SCLASS_CALCULATOR_H_

#include<iostream>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<stack>
#include<string>
using namespace std;

class Calculator{
	private :
     	string postfixExp;
     	string infixExp;
     	double ans;
	public :
     	Calculator(string s=""){
       		infixExp=s;
       		ans=0.0;
     	}
     	void display();
     	double calculate(string infixExp);
     	bool infix_to_postfix();
     	double  cal_postfix();
     	double cal(double ,double ,char);
     	int get_priority(char);
     	double read_num(string s,int *pos); 
};

void Calculator::display(){
    cout<<"后缀表达式为："<<postfixExp<<endl;
    cout<<"表达式的值为：";
    printf("%.2f\n",ans);
}

double Calculator::calculate(string infixExp){
        this->infixExp=infixExp;
        if(infix_to_postfix()){
            return ans=cal_postfix();
        }
		else{
           cout<<"语法错误，请检查表达式"<<endl;
           return 0.0;
        }
}

double Calculator::read_num(string s,int *pos){
    double x=0;
    int flag=0,w=0,h=1,i;
    if(s[(*pos)]=='-'){
		(*pos)++;
		h=-1;
	}
    for(i=(*pos);i<s.length();i++)
    if (s[i]!='#')
        if(s[i]=='.'){
            flag=1;
        }
		else{
            if(flag) w++;
            x=x*10+s[i]-'0';
    }
	else  break;
    (*pos)=i;
    return x/pow(10,w)*h;
}

double Calculator::cal(double num1,double num2,char op){
    switch(op){
  	case '+':
      return num1+num2;
  	case '-':
      return num1-num2;
  	case '*':
      return num1*num2;
  	case '/':
      return num1/num2;
  	default:
     return 0.0;
    }
}

int Calculator::get_priority(char c){
    switch(c){
      case '+':case '-': return 1;
      case '*':case '/': return 2;
      case '(':return 0;
      case ')':return 0;
      case '#':return -2;
      default:return -1;
    }
}
bool Calculator::infix_to_postfix(){
    stack<char> stk;
    int a_num_end=0,is_negative=0;
    string result="#";
    stk.push('#');
    for (int i=0;i<infixExp.length();i++){
        char c=infixExp[i];
        if(c=='-'&&(i==0||infixExp[i-1]=='(')){
			result+='-';
			is_negative=1;
			continue;
		}
        if((c<='9'&&c>='0')||c=='.'){
                if(a_num_end&&!is_negative)
                	result+='#';
                is_negative=0;
                result+=c;
                a_num_end=0;
        }
        else{
			a_num_end=1;
         	if(c=='(') stk.push('(');
        else if(c==')'){
                while (stk.top()!='(')
                {
                    result+='#';
                    result+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        else {
             int p=get_priority(c);
             if (p==-1) return false;
             while (p<=get_priority(stk.top())){
                result+='#';
                result+=stk.top();
                stk.pop();
             }
             stk.push(c);
        }
        }
    }
    while (stk.top()!='#'){
        result+='#';
        result+=stk.top();
        stk.pop();
    }
    result+='#';
    postfixExp = result;
    return true;
}
double Calculator::cal_postfix(){
    int l=postfixExp.length();
    stack<double> stk1;
    for (int i=1;i<l;i++){
        char c = postfixExp[i];
        if(c=='#')continue;
        if((c=='-'&&postfixExp[i+1]!='#')||(c>='0'&&c<='9')||c=='x')
			stk1.push(read_num(postfixExp,&i));
        else{
           double y=stk1.top();
           stk1.pop();
           double x=stk1.top();
           stk1.pop();
           stk1.push(cal(x,y,c));
        }
    }
   return stk1.top();
}
#endif
