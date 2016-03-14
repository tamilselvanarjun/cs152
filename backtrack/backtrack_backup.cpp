#include <iostream>
#include <string>
//#include "testFunctions.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Test functions

void initialise(int &a, int &b, char numbermap[])
{
	//cout<<"Initializing!\n";		//remove
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
	//cout<<"Checking assignment\n";		//remove
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
	//cout<<"Value assigned.\n";		//remove
}

int numberSum(string str1, string str2, int counter, int lettermap[],int carry, int& carryHere)
{
	int sum = 0,a1,a2;

	//cout<<"Calculating sum.\n";

	if(counter >= str1.length())
		a1 = 0;
	else
	{
		a1 = lettermap[ str1[counter] - 'a'];
	}
	if(counter >= str2.length())
		a2 = 0;
	else
	{
		a2 = lettermap[ str2[counter] - 'a'];
	}

	sum = (a1 + a2 + carry)%10;
	carryHere  = (a1+a2+carry)/10;
	return sum;
}

int valueOf(string str, int counter, int lettermap[])
{
	//cout<<"Returning values.\n";		//remove

	if(counter > str.length())
		return 0;
	else
		{
			int k = lettermap[ str[counter] -'a'];
			return k;
		} 
}

void iterateValues(int &a, int &b, char numbermap[])
{
	b++;
	while(b<10)
	{
		if(numbermap[b] == '\0')
			break;
		b++;
	}

	if(b==10)
	{
		a++;
		while(a<10)
		{
			if(numbermap[a] == '\0')
				break;
			a++;
		}

	}

	//cout<<"Values iterated.\n";
}

void resetValues(bool &s1, bool &s2, bool &s3, string str1, string str2, string str3, int lettermap[], char numbermap[], int &a, int &b, int counter)
{
	//resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);			//to call the resetValues function

	if(s1 == true and b==9)		//assignment was done in the current recursion
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

	//cout<<"Values reset.\n";
}



void normalise(int &a, int &b)
{
	a = a%10;
	b = b%10;
	//cout<<"Normalised. \n";
}

bool isTaken(int num, char numbermap[])
{
	num%=10;
	if(numbermap[num] == '\0')
		return false;
	else
		return true;
}

void printArray(int lettermap[],char numbermap[])
{
	//for(int i =0;i<26;i++)
		//cout<<lettermap[i]<<" ";

	//cout<<endl;
	cout<<"Solution -\n";
	for(int i=0;i<50;i++)
		cout<<"-";
	cout<<endl;

	for(int i=0;i<10;i++)
		if(numbermap[i]!='\0')
			cout<<numbermap[i]<<"="<<i<<" , ";

	cout<<endl;

	for(int i=0;i<50;i++)
		cout<<"-";
	cout<<endl;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool backtrack(string str1, string str2, string str3, int counter, int lettermap[], char numbermap[], int carry = 0)
{
	int a = 0, b = 0;
	bool s2,s3;
	bool s1 = s2 = s3 = false;
	int carryHere = 0;

	if(counter == str3.length() and carry == 0)	//end case
	{
		return true;
	}
	else if(counter == str3.length() and carry == 1)
	{
		return false;
	}
	else								//not the end case
	{
		initialise(a,b,numbermap);

		while(true)
		{
			//printArray(lettermap,numbermap);

			if(a==10 and b==10)
				return false;
			else
				normalise(a,b);

			if(!isAssigned(str1,counter,lettermap))
			{
				assignValue(str1,counter,lettermap,numbermap,a);
				s1 = true;
			}

			if(!isAssigned(str2,counter,lettermap))
			{
				assignValue(str2,counter,lettermap,numbermap,b);
				s2 = true;
			}

			//printArray(lettermap,numbermap);
			//cout<<"//////\n";
			// Now we need to check whether str3 has got the number mapping or not
			if(isAssigned(str3,counter,lettermap))	//if str3 is assigned
			{
				if(numberSum(str1,str2,counter,lettermap,carry,carryHere)==valueOf(str3,counter,lettermap))
				{
					if(backtrack(str1,str2,str3,counter+1,lettermap,numbermap,carryHere) == true)
						return true;	//change this later
					else
						resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);
				}
				else
				{
					if(s1==false and s2==false)		//both strings already given a number from previous columns
						return false;
					else						 
					{
						resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);
					}
				}
			}	
			else	//if str3 isnt assigned
			{
				if( !isTaken(numberSum(str1,str2,counter,lettermap,carry,carryHere) , numbermap ))	//if the sum is NOT given to some other letter
				{
					assignValue(str3,counter,lettermap,numbermap,numberSum(str1,str2,counter,lettermap,carry,carryHere));
					s3 = true;
					if(backtrack(str1,str2,str3,counter+1,lettermap,numbermap,carryHere) == true)						//change this later
						return true;
					else
						resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);							//if backtrack doesn't work, reset whatever has been done
				}
				else
				{
					if(s1==false and s2==false)
						return false;
					else
						resetValues(s1,s2,s3,str1,str2,str3,lettermap,numbermap,a,b,counter);
				}
			}
		}
		//cout<<"Out of while!\n";
	}
}

void reverse(string &s)
{
	int n = s.length();
	char c;

	for(int i = 0;i<n/2;i++)
	{
		c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}
}

int main()
{
	string str1,str2,str3;

	int lettermap[26];
	for(int i=0;i<26;i++)
		lettermap[i] = -1;

	char numbermap[10];
	for(int i=0;i<10;i++)
		numbermap[i] = '\0';

	cin>>str1>>str2>>str3;
	reverse(str1);
	reverse(str2);
	reverse(str3);

	if(backtrack(str1,str2,str3,0,lettermap,numbermap))
		{
			cout<<"Solution Found!\n";
			printArray(lettermap,numbermap);
		}
	else
		cout<<"No Solution Found!\n";
}