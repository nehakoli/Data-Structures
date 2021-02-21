#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
    public:
    node *head, *tail;
    
    public:
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void add_begin(int num);
    void add_specific(int num, int pos_data);
    void add_end(int num);
    void remove(int num);    
    void display();
};

void linked_list::add_begin(int num)
{
    node *tmp=new node;
    tmp->data=num;
    tmp->next=NULL;
    
    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
    }
    else
    {
        tmp->next=head;
        head=tmp;
    }
    cout<<"The element has been added successfully";
}

void linked_list::add_end(int num)
{
    node *tmp=new node;
    tmp->data=num;
    tmp->next=NULL;
    
    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
    }
    else
    {
        tail->next=tmp;
        tail=tmp;
    }
}

void linked_list::add_specific(int num, int pos_data)
{
    node *tmp=new node;
    tmp->data=num;
    tmp->next=NULL;
    
    node *t;
    head=t;
    
    while(t->data!=pos_data)
    {
        t=t->next;
    }
    
    tmp->next=t->next;
    t->next=tmp;
}

void linked_list::remove(int num)
{
    node *tmp1,*tmp2;
    tmp1=head;
    
    if(head==NULL)
        cout<<"\nList is empty!! Deletion is not possible\n";
    else
    {
        while(tmp1->data!=num)
        {
            tmp2=tmp1;
            tmp1=tmp1->next;
            
            if(tmp1==NULL)
            {
                cout<<"\nGiven node not found in the list! Deletion not possible!!!\n";                
                return;
            }
        }
        if(tmp1->next==NULL)  //if the node is at the end
        {
            head=NULL;
            delete tmp1;
        }
        else if(tmp1==head)  //if the node is at the begining
        {
            head=head->next;
            delete tmp1;
        }
        else //if the node is at a specific position
        {
            if(tmp1->next==NULL)
            {
                tmp2->next=NULL;
                delete tmp1;
            }
            else
            {
                tmp2->next=tmp1->next;
                delete tmp1;
            }
        }
    }       
}

void linked_list::display()
{
   node *tmp;
    tmp=head;
    
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }  
}

int main()
{
    int choice,p,n;
    linked_list s;
    
    do
    {
        cout<<"\nChoose:\n1. Insert at the begining \n2. Insert at the end \n3. Insert at the specific location\n";
        cout<<"4. Delete \n5.Display \n6.Exit\n";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter the element you want to insert: ";
                cin>>n;
                s.add_begin(n);
                break;
                
            case 2:
                cout<<"Enter the element you want to insert: ";
                cin>>n;
                s.add_end(n);
                break;
                
            case 3:
                cout<<"Enter the element you want to insert: ";
                cin>>n;
                cout<<"Enter the the element after which you want to insert: ";
                cin>>p;
                s.add_specific(n,p);
                break;
                
            case 4:
                cout<<"Enter the element you want to delete: ";
                cin>>n;
                s.remove(n);
                
            case 5:
                s.display();
        }
    }while(choice!=6);
}
