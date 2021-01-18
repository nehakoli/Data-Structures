#include<iostream>
#define MAX 5
using namespace std;
int STACK[MAX], TOP,temp;  

int isEmpty()  //Check if stack is empty
{
    if(TOP==-1)
        return 1;
    else
        return 0;
}

int isFull()  //Check if stack is full
{
    if(TOP==MAX-1)
        return 1;
    else
        return 0;
}

void Push(int num)
{
    if(isFull())
    {
        cout<<"STACK IS FULL\n";
        return;
    }
    TOP++;
    STACK[TOP]=num;
    cout<<num<<" has been inserted\n";
}

void Pull(int num)
{
    if(isEmpty())
    {
        cout<<"Stack is empty\n";
        return;
    }
    temp=STACK[TOP];
    TOP--;
    cout<<temp<<" has been removed\n";
}

void Display()
{
    int i;
    if (isEmpty())
    {
        cout<<"Stack is empty\n";
        return;
    }
    for(i=TOP;i>=0;i--)
        cout<<STACK[i]<<"\t";
    cout<<endl;
}

int main()
{
    int num;
    TOP=-1;
    char ch;
    do{
        int a;
        cout<<" Choose: \n1. Push \n2. Pop \n3 Display\n";
        cin>>a;
        switch(a)
        {
            case 1:
                cout<<"Enter an integer: ";
                cin>>num;
                Push(num);
            break;
                
            case 2:
                cout<<"Enter an integer: ";
                cin>>num;
                Pull(num);
            break;
                
            case 3:
                Display();
            break;
                
            default:
                cout<<"Invalid Choice...\n";                
        }
        cout<<"\nDo you want to continue? ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}
