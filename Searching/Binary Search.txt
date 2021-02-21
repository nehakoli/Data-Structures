
WITHOUT RECURSION
#include<iostream>
using namespace std;
int main()
{
    int a[7],ns,lb=0,ub=6,mid,k=0;
    cout<<"Enter elements in an array"<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>a[i];
    }
    cout<<"Original Array :"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n Enter the number to be searched ";
    cin>>ns;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]<ns)
        {
            lb=mid+1;
        }
        if(a[mid]>ns)
        {
            ub=mid-1;
        }
        if(a[mid]==ns)
        {
            k=1;
            break;
        }
    }
    if(k==1)
    {
        cout<<"The number to be searched is found";
    }
    else
    {
         cout<<"The number to be searched is not found";
        
    }
    
}



WITH RECURSION

#include<iostream>
using namespace std;

int BinaryS(int a[],int ns,int lb,int ub)
{
    if(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(a[mid]<ns)
        return BinaryS(a,ns,lb+1,ub);
        if(a[mid]>ns)
        return BinaryS(a,ns,lb,ub-1);
        if(a[mid]==ns)
        return mid;
    }
    return -1;
}
int main()
{
    int ns;
    int a[7]={7,14,22,27,31,34,42};
    cout<<"Enter number to be searched";
    cin>>ns;
    int k=BinaryS(a,ns,0,6);
    if(k==-1)
    cout<< ns <<" is not present in the array";
    else
    cout<< ns <<" is present at index "<< k <<" in the array";
    return 0;
}   

