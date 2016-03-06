#include <iostream>
using namespace std;
long unsigned int count=0;

void multiply(long unsigned int A[2][2], long unsigned int B[2][2])
{
	long unsigned int w,x,y,z;
	w = A[0][0]*B[0][0] + A[0][1]*B[1][0];
	x = A[0][0]*B[0][1] + A[0][1]*B[1][1];
	y = A[1][0]*B[0][0] + A[1][1]*B[1][0];
	z = A[1][0]*B[0][1] + A[1][1]*B[1][1];

	A[0][0] = w;
	A[0][1] = x;
	A[1][0] = y;
	A[1][1] = z;

	//A = C;
}

void power(long unsigned int F[2][2], long unsigned int n)
{
    count++;
    long unsigned int I[2][2] = {{1,1},{1,0}};

	if(n==1)
	{
		F = I;
		return;
	}

	power(F,n/2);
	multiply(F,F);

	if(n%2==1)
		multiply(F,I);


}

long unsigned int fib(long unsigned int n)
{
	long unsigned int F[2][2] = {{1,1},{1,0}};

    power(F,n);
    //cout<<F[0][0]<<F[0][1]<<endl<<F[1][0]<<F[1][1]<<endl;
	return F[0][1];
}


int main()
{
	long unsigned int n;
	cin>>n;
	cout<<fib(n)<<endl;
	cout<<::count<<endl;
}
