#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;


void Push(int val)
{
    node *newnode = new node;
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}


int Pop()
{
    int item = top->data;
    top=top->next;
    return item;    
}


void Display()
{
    struct node *ptr;
    if(top==NULL)
        cout<<"Stack is empty";
    else
    {
        ptr=top;
        cout<<"Stack elements are: ";
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
    }
    cout<<endl;
}
  

int Operation(int a, int b, char operand)
{
    switch(operand)
    {
        case '+':
            return a+b;
            break;
                
        case '-':
            return a-b;
            break;
                
        case '*':
            return a*b;
            break;
                
        case '/':
            return b/a;
            break;
                
        default:
            return 0;
    }
}
    

void Calculation()
{
    while(top!=NULL)
    {
        Pop();
    }
    int index=0;
    char str[50];
    cout<<"Enter the postfix operation:\n";
    cin>>str;
    while(str[index]!='\0')
    {
        if(isdigit(str[index]))
            Push(str[index]-'0');
        else
        {
            int x = Pop();
            int y = Pop();
            int result = Operation(x,y,str[index]);
            Push(result);
        }
        index ++;
    }
}


int main()
{
    char ch;
    
    do{
        Calculation();
        Display();
        cout<<"\nDo you want to contine? (y/n) ";
        cin>>ch;
    }while((ch=='y')||(ch=='Y'));
}
