#include <iostream>
using namespace std;
#define size 5
int CQ[size], front = -1, rear = -1;

void InsertCircularQueue(int value)
{
   if((front==0 && rear==size-1)||(front==rear+1))
      cout<<"Circular Queue is Full! Insertion not possible!!!\n";
   else
   {
      if(rear==size-1 && front!=0)
         rear=-1;
      CQ[++rear] = value;
      cout<<"Insertion Success!!!\n";
      if(front == -1)
         front = 0;
   }
}
void DeleteCircularQueue()
{
   if(front==-1 && rear==-1)
      cout<<"Circular Queue is Empty! Deletion is not possible!!!\n";
   else{
      cout<<"Deleted element : \n"<<CQ[front++];
      if(front==size)
         front=0;
      if(front-1==rear)
         front=rear=-1;
   }
}
void Display()
{
   if(front==-1)
      cout<<"Circular Queue is Empty!!!\n";
   else{
      int i=front;
      cout<<"Circular Queue Elements are : \n";
      if(front<=rear)
      {
         while(i<=rear)
            cout<<"\t"<<CQ[i++];
      }
      else
      {
         while(i<=size-1)
            cout<<"\t"<<CQ[i++];
         i = 0;
         while(i<=rear)
            cout<<"\t"<<CQ[i++];
      }
   }
}

int main()
{
   int choice, value;
   clrscr();
   while(1){
      cout<<"\nChoose: \n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
      {
         case 1: cout<<"\nEnter the value to be insert: ";
                 cin>>value;
                 InsertCircularQueue(value);
                 break;
         case 2: DeleteCircularQueue();
                 break;
         case 3: Display();
                 break;
         case 4: return 0;
         default: cout<<"Please select the correct choice!!!\n";
      }
   }
}
