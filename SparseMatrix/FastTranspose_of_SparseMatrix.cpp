#include<iostream>
using namespace std; 

int main()
{
    int m,i,j,tmp,freq[50],R[50];
    cout<<"Enter no. of rows of the sparse matrix: ";
    cin>>m;
    int A[m][3],T[m][3];
    cout<<"Enter elements of matrix: ";
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        cin>>A[i][j];
    }
    
    int row=A[0][0];
    int col=A[0][1];
    int val=A[0][2];
    T[0][0]=col;
    T[0][1]=row;
    T[0][2]=val;
    
    for(i=0;i<col;i++) //stores the frequency count of each column, initially set to 0
    {
        freq[i]=0;
    }
    for(i=1;i<val;i++)
    {
        tmp=A[i][1];
        freq[tmp]++;;
    }
    for(i=1;i<col;i++)
    {
        R[i]=R[i-1]+freq[i-1];
    }
    for(i=1;i<=val;i++)
    {
        j=R[A[i][1]];
        T[j][0]=A[i][1];
        T[j][1]=A[i][0];
        T[j][2]=A[i][2];
        R[j]++;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        cout<<"\t"<<T[i][j];
        cout<<endl;
    }
}


