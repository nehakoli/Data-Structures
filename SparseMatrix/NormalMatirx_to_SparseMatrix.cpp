#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n,k=1,count=0;
    cout<<"Enter rows of normal matrix: ";
    cin>>m;
    cout<<"Enter columns of normal matrix: ";
    cin>>n;
    
    int nor[m][n],x=m*n,spr[x][3];
    cout<<"Enter elements of matrix: ";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>nor[i][j];
        }
    }
    
    spr[0][0]=m;
    spr[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(nor[i][j]!=0)
            {
                spr[k][0]=i;
                spr[k][1]=j;
                spr[k][2]=nor[i][j];
                k++;
                count++;
            }
        }
    }
    spr[0][2]=count;
    
    cout<<"\n\t*** SPARSE MATRIX ***\n";
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"\t"<<spr[i][j];
        }
        cout<<endl;
    }
    
    
}
