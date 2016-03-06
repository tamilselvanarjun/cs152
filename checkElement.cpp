#include <iostream>
using namespace std;


bool checkElement(int &i, bool value, bool arr[], int size)
{
	int count=0;
	while(arr[i]==value and i<size)
	{
		i++;
		count++;
	}

	if(count==0)
		i++;

	if(count>=50)			//change 
		return true;
	else
		return false;
}

int findVal(int &i, bool arr[], int size)
{
//	int i=0;
	bool found =false;
	int k;

	while(i<size)
	{
		if(checkElement(i,true,arr,size)==true)
		{
			k = (i-50);								   //storing the starting index
			
			if(checkElement(i,false,arr,size)==true)
			{
				found = true;
				break;
			}
		}
			
	}

	if(found)
		return k;
	else
		return -1;
}

int main()
{
	int size;
	cin>>size;

	bool* arr = new bool[size];//bool arr[500];
	int index=0;

	for(int i=0;i<size;i++)
		cin>>arr[i];

	int placeArray = findVal(index,arr,size);

	if(placeArray==-1)
		cout<<"Not found\n";
	else
		cout<<"Found at index "<<placeArray<<endl;


	delete[] arr;

	//if()

}