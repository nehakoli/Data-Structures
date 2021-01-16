
#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
    int m,i,j,k,N[30][3],T[30][3];
    cout<<"Enter no. of rows of sparse matrix: ";
    cin>>m;
    cout<<"Enter elements:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        cin>>N[i][j];
    }
    
    int row=N[0][0];
    int col=N[0][1];
    int val=N[0][2];
    T[0][0]=col;
    T[0][1]=row;
    T[0][2]=val;
    i=1;
    
    for(j=0;j<col;j++)
    {
        for(k=1;k<=val;k++)
        {
            if(N[k][1]==j)
            {
                T[i][0]=N[i][1];
                T[i][1]=N[i][0];
                T[i][2]=N[i][2];
                i++;
            }
        }
    }
    cout<<"\nTranspose of Sparse Matrix\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        cout<<"\t"<<T[i][j];
        cout<<endl;
    }
}

