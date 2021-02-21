#include <iostream>
using namespace std;

class Conversion
{
    public:
    char stack[50];
    int top;
    
    Conversion()
    {
        top=-1;
    }
    
    int Pop();
    void Push(int item);
    char Convert(char str[50]);
    int Operator(char s);
    int Precedence(char a);
};

int Conversion::Pop()
{
    char item = stack[top];
    top--;
    return item;
}

void Conversion::Push(int item)
{
    top++;
    stack[top] = item;
}

int Conversion::Operator(char s)
{
    if((s=='+')||(s=='-')||(s=='*')||(s=='/'))
        return 1;
}

int Conversion::Precedence(char a)
{
    switch(a)
        {
            case '+':
                return 1;
            break;
                
            case '-':
                return 1;
            break;
                
            case '*':
                return 2;
            break;
                
            case '/':
                return 2;
            break;
                
            default:
                return 0;
        }
}

char Conversion::Convert(char str[50])
{
    int index=0;
    char expr[50];
    while(str[index]!='\0')
    {
        if(isdigit(str[index]))
            expr[index]=str[index];
        else if(str[index]=='(')
            Push(str[index]);
        else if(Operator(str[index]))
        {
            while(Precedence(stack[top])>=Precedence(str[index]))
            {
                expr[index]=Pop();
                index++;
            }
            Push(expr[index]);
            Push(str[index]);
        }
        else if(str[index]==')')
        {
            while(stack[top]!='(')
            {
                expr[index] = stack[top];
                Pop();
            }
        }
        while(top>=0)
        {
            expr[index]=Pop();
            index++;             
        }
        index++;
    }
    return expr[50];
}

int main()
{
    Conversion a;
    char ch,str[50],result;
    
    do{
        cout<<"Enter the infix operation:\n";
        cin>>str[50];
        result=a.Convert(str);
        cout<<"The postfic operation is: "<<result;
        cout<<"\nDo you want to continue? (y/n) ";
        cin>>ch;
    }while((ch=='Y')||(ch=='y'));
}
