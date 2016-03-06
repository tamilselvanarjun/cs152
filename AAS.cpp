#include <iostream>
using namespace std;

bool AAS(int p, int q, int v[])
{
    int count=0;
    int i=p+1;
    while(i<q)
    {
        if(v[i-1]>v[i])
            count++;
        i++;
    }
    if(count<=1)
        return true;
    else
        return false;
}

int main()
{
    int z=0,n=0,N,k=0,t=0,d=0;

    cin>>N;
    int num[n];
    for(int ai=0;ai<N;ai++)
    {
        cin>>num[ai];
    }

    while(n!=N)
    {
        t=0;
        d=0;
        while(t!=n+1)
        {
            if(AAS(t,n+1,num))
            {
                d = max(d,n+1-t);
            }
            t++;
        }

        z = max(z,d);
        n++;
    }
    cout<<z;
}
