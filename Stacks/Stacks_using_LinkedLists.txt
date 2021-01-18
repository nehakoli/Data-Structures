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

void Pop()
{
    if(top==NULL)
        cout<<"Stack Underflow";
    else
    {
        cout<<"The popped element is "<<top->data<<endl;
        top=top->next;
    }
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

int main()
{
    int val,i;
    char ch;
    while(i!=4)
    {
        cout<<"\nChoose: \n1. Push in Stack \n2. Pop from Stack";
        cout<<"\n3. Display Stack \n4.Exit\n";
        cin>>i;
        switch(i)
        {
            case 1: 
                cout<<"Enter value: ";
                cin>>val;
                Push(val);
            break;
                
            case 2:
                Pop();
            break;
                
            case 3:
                Display();
            break;
        }
    }
}
















