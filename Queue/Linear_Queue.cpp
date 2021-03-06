#include <iostream>
using namespace std;
int Q[100], size=100, front=-1, rear=-1;

void enQueue(int element)
{
    if(rear!=size-1)
    {
        rear++;
        Q[rear]=element;
        cout<<"Element "<<Q[rear]<<" has been inserted\n";
    }
    else
    {
        cout<<"\nQueue is full";
    }
}

void deQueue()
{
    if(rear!=front)
    {
        front++;
        cout<<"Element "<<Q[front]<<" has been deleted\n";
    }
    else
    {
        cout<<"Queue is empty\n";
    }
}

void display()
{
    if(front!=rear)
    {
        for(int i=front+1;i<=rear;i++)
            cout<<Q[i]<<"\t";
    }
    else
        cout<<"Queue is empty\n";
}

int main()
{
    int element, ch;
    do{
    cout<<"\nChoose:\n1. Insertion \n2. Deletion \n3. Display \n4. Exit\n";
    cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>element;
                enQueue(element);
                break;
                
            case 2:
                deQueue();
                break;
                
            case 3:
                display();
        }
    }while(ch!=4);
}
