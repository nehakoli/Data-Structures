#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class circular_linked_list
{
    public:
    node *head;
    circular_linked_list()
    {
        head=NULL;
    }
    
    public:
    void add_begin(int num);
    void add_specific(int num, int pos);
    void add_end(int num);
    void remove(int num);
    void display();
};

void circular_linked_list::add_begin(int num)
{
    node *newnode=new node;
    newnode->data=num;
    newnode->next=NULL;
    
    node *tmp;
    
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        tmp=head;
        while(tmp->next!=head)
        {
            tmp=tmp->next;
        }
        newnode->next=head;
        head=newnode;
        tmp->next=head;
    }
}

void circular_linked_list::add_specific(int num, int pos)
{
    node *newnode=new node;
    newnode->data=num;
    
    node *tmp1,*tmp2;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        tmp1=head;
        while(tmp1->data!=pos)
        {
            if(tmp1->next==head)
            {
                cout<<"Given node not found in the list!! INSERTION NOT POSSIBLE!!\n";
            }
            tmp1=tmp1->next;
        }
        tmp2=tmp1->next;
        tmp1->next=newnode;
        newnode->next=tmp2;
    }
}

void circular_linked_list::add_end(int num)
{
    node *newnode=new node;
    newnode->data=num;
    
    node *tmp;
    
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        tmp=head;
        while(tmp->next!=head)
        {
            tmp=tmp->next;
        }
        tmp->next=newnode;
        newnode->next=head;
    }
}

void circular_linked_list::remove(int num)
{
    node *tmp1,*tmp2;
    
    if(head==NULL)
    {
        cout<<"List is Empty!! DELETION IS NOT POSSIBLE!!";
    }
    else
    {
        tmp1=head;
        while(tmp1->data!=num)
        {
            if(tmp1->next==head)
            {
                cout<<"Given node not found in the list!! DELETION NOT POSSIBLE!!\n";
                return;
            }
            tmp2=tmp1;
            tmp1=tmp1->next;
        }
        if(tmp1->next==head)    //check if list is having only one node
        {
            head==NULL;
        }
        else
        {
            if(tmp1==head)     //check if it is the first node
            {
                tmp2=head;
                while(tmp2->next!=head)
                {
                    tmp2=tmp2->next;
                }
                head=head->next;
                tmp2->next=head;
            }
            else if(tmp1->next==head)       //check if it is the last node
            {
                tmp2->next=head;
            }
            else
            {
                tmp2->next=tmp1->next;
            }
        }
    }
}

void circular_linked_list::display()
{
    node *tmp;
    
    if(head==NULL)
        cout<<"List is Empty!!\n";
    else
    {
        tmp=head;
        while(tmp->next!=head)
        {
            cout<<tmp->data<<"\t";
            tmp=tmp->next;
        }
        cout<<tmp->data<<"\n";
    }
}

int main()
{
    circular_linked_list s;
    int ch,num,pos;
    
    do{
        cout<<"Choose: \n1. Insert at the beginning \n2. Insert at the specific location \n3. Insert at the end \n";
        cout<<"4. Delete \n5. Display \n6. Exit \n";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                cout<<"Enter number: ";
                cin>>num;
                s.add_begin(num);
                break;
                
            case 2:
                cout<<"Enter number: ";
                cin>>num;
                cout<<"Enter the number after which you want to insert: ";
                cin>>pos;
                s.add_specific(num,pos);
                break;
                
            case 3:
                cout<<"Enter number: ";
                cin>>num;
                s.add_end(num);
                break;
                
            case 4:
                cout<<"Enter number: ";
                cin>>num;
                s.remove(num);
                break;
                
            case 5:
                s.display();
                break;
                
            default:
                cout<<"INVALID INPUT!!";
        }
    }while(ch!=6);
}
