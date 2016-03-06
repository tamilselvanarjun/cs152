#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x=1,y=n;
    int mid;
    while(y!=x+1)
    {
        mid = (x+y)/2;
        if(mid*mid <= n)
            x = mid;
        else
            y = mid;
        cout<<x<<","<<y<<endl;
    }
    cout<<x;
}
