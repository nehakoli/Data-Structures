#include <iostream>
using namespace std;
int main()
{
    int m1,m2,a,b;
    cout<<"Sparse Matrix A\n";
    cout<<"Enter no. of rows of A: ";
    cin>>m1;
    cout<<"Sparse Matrix B\n";    
    cout<<"Enter no. of rows of B: ";
    cin>>m2;
   
    int A[20][3],B[20][3],C[30][3];
    cout<<"\nEnter element of Sparse matrix A: \n";
    for(a=0;a<m1;a++)
    {
        for(b=0;b<3;b++)
        {
            cin>>A[a][b];
        }
    }
    cout<<"\nEnter element of Sparse matrix B: \n";
    for(a=0;a<m2;a++)
    {
        for(b=0;b<3;b++)
        {
            cin>>B[a][b];
        }
    }
   
   
    int M=A[0][2],N=B[0][2];
    int i,j,k;
   

    if((A[0][0]==B[0][0]) && (A[0][1]==B[0][1]))  //if1 //check if dimensions of A & B are same
    {
        i=j=k=1;
        C[0][0]=A[0][0];
        C[0][1]=A[0][1];
       
        while((i<=M) && (j<=N))     //while1
        {
            if((A[i][0]==B[j][0]))      //if2
            {
                if((A[i][1]==B[j][1]))    
                {
                    C[k][0]=A[i][0];
                    C[k][1]=A[i][1];
                    C[k][2]=A[i][2]+B[j][2];
                    i++; j++; k++;
                }      
                else if((A[i][1]<B[j][1]))      
                {
                    C[k][0]=A[i][0];
                    C[k][1]=A[i][1];
                    C[k][2]=A[i][2];
                    i++; k++;
                }      
                else if((A[i][1]>B[j][1]))      
                {
                    C[k][0]=B[j][0];
                    C[k][1]=B[j][1];
                    C[k][2]=B[j][2];
                    j++; k++;
                }      
            }    //end if2
            else if(A[i][0]<B[j][0])    //elseif1 of if2
            {
                C[k][0]=A[i][0];
                C[k][1]=A[i][1];
                C[k][2]=A[i][2];
                i++; k++;
            }       //end elseif1 of if2
            else if(A[i][0]>B[j][0])        //elseif2 of if2
            {
                C[k][0]=B[j][0];
                C[k][1]=B[j][1];
                C[k][2]=B[j][2];
                j++; k++;
            }       //end elseif1 of if2
        }       //end while1
        while(i<=M)     //while2
        {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
            i++; k++;
        }       //end while2
        while(j<=N)     //while3
        {
            C[k][0]=B[j][0];
            C[k][1]=B[j][1];
            C[k][2]=B[j][2];
            j++; k++;
        }       //end while3
        C[0][2]=k;
       
        for(a=0;a<k;a++)
        {
            for(b=0;b<3;b++)
            {
                cout<<"\t"<<C[a][b];
            }
            cout<<endl;
        }
    }       //end if1
    else        //else of if1
    {
        cout<<"Matrices cannot be added, dimensions dosen't match";
    }
}
