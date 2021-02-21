#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class doubly_linked_list
{
    public:
    node *head,*tail;
    
    public:
    doubly_linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void add_begin(int num);
    void add_specific(int num,int pos);
    void add_end(int num);
    void remove(int num);
    void display();
};

void doubly_linked_list::add_begin(int num)
{
    node *tmp=new node;
    tmp->data=num;
    tmp->prev=NULL;
    
    if(head==NULL)
    {
        tmp->next=NULL;
        head=tmp;
        tail=tmp;
    }
    
    else
    {
        tmp->next=head;
        head=tmp;
    }
    cout<<"The element has been inserted successfully\n";
}

void doubly_linked_list::add_specific(int num,int pos)
{
    node *tmp=new node;
    tmp->data=num;
    
    node *tmp1,*tmp2;
    tmp1=head;
    
    if(head==NULL)
    {
        tmp->prev=NULL;
        tmp->next=NULL;
        head=tmp;
        tail=tmp;
    }
    
    else
    {
        while(tmp1->data!=pos)
        {
            if(tmp->next==NULL)
            {
                cout<<"Given node not found in the list!! DELETION IS NOT POSSIBLE!!!\n\n";                
                return;
            }
            tmp1=tmp1->next;
        }
        tmp2=tmp1->next;
        tmp1->next=tmp;
        tmp->next=tmp2;
        tmp->prev=tmp1;
        tmp2->prev=tmp;
    }
    cout<<"The element has been inserted successfully\n";  
}

void doubly_linked_list::add_end(int num)
{
    node *tmp=new node;
    tmp->data=num;
    tmp->next=NULL;
    
    node *tmp1;
    tmp1=head;
    
    if(head==NULL)
    {
        tmp->prev=NULL;
        head=tmp;
        tail=tmp;
    }
    
    else
    {
        while(tmp1->next!=NULL)
        {
            tmp1=tmp1->next;
        }
        tmp1->next=tmp;
        tmp->prev=tmp1;
        tmp->next=NULL;
    }
    cout<<"The element has been inserted successfully\n";
}

void doubly_linked_list::remove(int num)
{
    node *tmp;
    tmp=head;
    
    if(head==NULL)
        cout<<"List is empty!! DELETION IS NOT POSSIBLE!!!\n";
    else
    {
        while(tmp->data!=num)
        {
            if(tmp->next==NULL)
            {
                cout<<"Given node not found in the list!! DELETION IS NOT POSSIBLE!!!\n\n";                
                return;
            }
            tmp=tmp->next;
        }
        
        if((tmp->next==NULL)&&(tmp->prev==NULL))  //if it is the only node in the list
        {
            head=NULL;
            cout<<"Node has been deleted successfully!!\n";
        }     
        else if(tmp==head)  //if the node is at the begining
        {
            head=head->next;
            head->prev=NULL;
            cout<<"Node has been deleted successfully!!\n";
        }    
        else if(tmp->next==NULL)  //if the node is at a end position            
        {
            tmp->prev->next=NULL;
            cout<<"Node has been deleted successfully!!\n";
        }
        else    //of the node is at the specific location
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            cout<<"Node has been deleted successfully!!\n";
        }   
    }
}

void doubly_linked_list::display()
{
    node *tmp;
    tmp=head;
    if(head==NULL)
        cout<<"List is Empty\n";
    else
    {
        while(tmp!=NULL)
        {    
            cout<<tmp->data<<" <==> ";
            tmp=tmp->next;
        }   
        cout<<"NULL\n";
    }
}


int main()
{
    doubly_linked_list s;
    int ch,n,p;
    
    do{
        cout<<"Choose: \n1. Insert at the beginning \n2. Insert at specific location \n3. Insert at the end \n";
        cout<<"4. Delete \n5. Display \n6. Exit \n";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                cout<<"Enter number: ";
                cin>>n;
                s.add_begin(n);
                break;
                
            case 2:
                cout<<"Enter number: ";
                cin>>n;
                cout<<"Enter data after which you want to insert: ";
                cin>>p;
                s.add_specific(n,p);
                break;
                
            case 3:
                cout<<"Enter number: ";
                cin>>n;
                s.add_end(n);
                break;
                
            case 4:
                cout<<"Enter number: ";
                cin>>n;
                s.remove(n);
                break;
                
            case 5:
                s.display();                   
        }
    }while(ch!=6);
}
