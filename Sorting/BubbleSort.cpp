#include <iostream>
using namespace std;

int main()
{
    int arr[5],i,j,temp,flag;
    cout<<"Enter 5 elements of array:\n";
    
    for(i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    
    for(i=0;i<5;i++)
    {
	flag=0;
        for(j=i+1;j<5;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
		flag=1;
            }
        }
	if(flag==0)
		break;
    }
    cout<<"Sorted Array using Bubble Sort: \n";
    for(i=0;i<5;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
