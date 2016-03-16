#include <iostream>
#include <string>
using namespace std;

void initialise(int &a, int &b, char numbermap[])
{
	for(int i=0;i<10;i++)
	{
		if(numbermap[i] == '\0')
		{
			a = i;
			break;
		}
	}

	for(int i=0;i<10;i++)
	{
		if(numbermap[i] == '\0' and i!=a)
		{
			b = i;
			break;
		}
	}
}

bool isAssigned(string str,int counter,int lettermap[])
{
	if(counter >= str.length())
		return true;
	else
	{
		if(lettermap[ str[counter] - 'a'] == -1)		//letter maps to the number they denote
			return false;
		else
			return true;
	}
}

void assignValue(string str,int counter,int lettermap[],char numbermap[],int a)
{
	lettermap[ str[counter] - 'a' ] = a;
	numbermap[a] = str[counter];
}

int numberSum(string str1, string str2, int counter, int lettermap[])
{
	int sum = 0,a1,a2;

	if(counter > str1.length())
		a1 = 0;
	else
	{
		a1 = lettermap[ str1[counter] - 'a'];
	}
	if(counter > str2.length())
		a2 = 0;
	else
	{
		a2 = lettermap[ str2[counter] - 'a'];
	}

	sum = (a1 + a2)%10;
	return sum;
}

int valueOf(string str, int counter, int lettermap)
{
	if(counter > str.length())
		return 0;
	else
		{
			int k = lettermap[ str[counter] -'a'];
			return k;
		} 
}

void resetValues(bool &s1, bool &s2, bool &s3, string str1, string str2, string str3, int lettermap[], char numbermap[], int &a, int &b, int counter)
{
	//resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);			//to call the resetValues function

	if(s1 == true and b==10)		//assignment was done in the current recursion
	{
		numbermap[ lettermap[ str1[counter] -'a' ] ] = '\0';
		lettermap[str1[counter] - 'a'] = -1;
		s1 = false;
	}

	if(s2 == true)
	{
		numbermap[ lettermap[ str2[counter] - 'a' ] ] = '\0';
		lettermap[str2[counter]-'a'] = -1;
		s2 = false;
	}

	if(s3 == true)
	{
		numbermap[ lettermap[ str3[counter] - 'a' ] ] = '\0';
		lettermap[str3[counter]-'a'] = -1;
		s3 = false;
	}
	iterateValues(a,b,numbermap);
}

void iterateValues(int &a, int &b, char numbermap[])
{
	b++;
	while(b<10)
	{
		if(numbermap[b] == '\0')
			break;
	}

	if(b==10)
	{
		a++;
		while(a<10)
		{
			if(numbermap[a] == '\0')
				break;
		}
	}
}

void normalise(int &a, int &b)
{
	a = a%10;
	b = b%10;
}

bool isTaken(int num, char numbermap[])
{
	num%=10;
	if(numbermap[num] == '\0')
		return false;
	else
		return true;
}