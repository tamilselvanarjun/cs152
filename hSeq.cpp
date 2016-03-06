#include <iostream>
using namespace std;

bool hsearch(int &i, int ar[], int size)
{
    if(i<size)
    {
        if(ar[i]==0)
            {
                i++;
                return true;
            }
        else if(ar[i]==1)
        {
            i++;
            if(i<size)
            {
                if(hsearch(i,ar,size)==true)
                {
                    if(i<size)
                        {
                            if(hsearch(i,ar,size)==true)
                                return true;
                            else
                                return false;
                        }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    int i=0;

    for(int j=0;j<n;j++)
        cin>>ar[n];

    bool value = (hsearch(i,ar,n));
    cout<<value;
}
