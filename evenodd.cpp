/* Program assumes odd positions mean even indices (0 index means 1st position) and vice versa */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int odd=0,even=0,N;
	cin>>N;
	vector<int> v,evenNum,oddNum;

	for(int ai=0;ai<N;ai++)
	{
		int tempVar;
		cin>>tempVar;
		v.push_back(tempVar);

		if(tempVar%2==0)		//even
		{
			evenNum.push_back(tempVar);
			even++;
		}
		else
		{
			oddNum.push_back(tempVar);
			odd++;
		}
	}

	for(int ai=0;ai<N;ai++)
		v[ai] = -1000;				//assuming -1000 as minus infinity and all elements are greater than that

	if(odd<even)
	{
		int j=0,k=0;
		while(j<odd)
		{
			v[2*j] = oddNum[j];
			j++;
		}
		j=0;

		while(j<N)
		{
			if(v[j]==-1000)
			{
				v[j] = evenNum[k];
				k++;
			}
			j++;
		}
	}
	else
	{
		int j=0,k=0;
		while(j<even)
		{
			v[2*j+1] = evenNum[j];
 			j++;
		}
		j=0;

		while(j<N)
		{
			if(v[j]==-1000)
			{
				v[j]= oddNum[k];
				k++;
			}
			j++;
		}
	}

	for(int ai=0;ai<N;ai++)
		cout<<v[ai]<<" ";

}