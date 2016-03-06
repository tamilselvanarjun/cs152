#include<iostream>
using namespace std;

void magicSquare(int n)
{
    int **A = new int*[n];
    for(int i=0;i<n;i++)
        A[i] = new int[n];

    int i = n/2 , j=n-1;
    int value =1;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            A[i][j] =0;

    while(value<=n*n)
    {
        if(i==-1 and j==n)
        {
            i=0; j=n-2;
        }
        else
        {
            if(i<0)
                i=(n-1);
            if(j==n)
                j=0;
        }

        if(A[i][j]!=0)
        {
            i++;
            j-=2;
            continue;
        }
        else
        {
            A[i][j] = value;
            value++;
        }

        j++ ; i--;

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<n;i++)
        delete[] A[i];
    delete[] A;
}

int main()
{
    int n;
    cin>>n;
    magicSquare(n);
}
