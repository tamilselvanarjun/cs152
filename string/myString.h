#include <iostream>
using namespace std;

struct myString
{
	char* ptr;
	int len;
	char nullchar;

	myString()
	{
		len=0;
		ptr = NULL;
		nullchar = '\0';
	}

	~myString()
	{
		delete[] ptr;
	}

	myString(const char* b)
	{
		len = 0;

		for(int i=0;b[i]!='\0';i++)
			len++;

		ptr = new char[len+1];

		for(int i=0;i<len;i++)
			ptr[i] = b[i];
		
		ptr[len] = '\0';
		nullchar = '\0';
	}

	myString(const myString& b)
	{
		len = b.len;
		ptr = new char[len+1];

		for(int i=0;i<len+1;i++)
			ptr[i] = b.ptr[i];
		nullchar = '\0';
	}

	char& operator[](int i)
	{
		if(i<len and i>=0 and len>0)
			return ptr[i];
		else
		{
			cout<<"Please access within the string.\n";
			cout<<"You tried to access index "<<i;
			cout<<" which doesnot exist in the string.\n";
			return nullchar;
		}
	}

	myString& operator=(const myString& b)
	{
		len = b.len;
		delete[] ptr;

		ptr = new char[len+1];
		for(int i=0;i<len+1;i++)
			ptr[i] = b.ptr[i];

		return *this;   
	}

	myString& operator=(const char* str)
	{
		delete[] ptr;
		len = 0;

		for(int i=0;str[i]!='\0';i++)
			len++;
		ptr = new char[len+1];
		for(int i=0;i<len;i++)
			ptr[i] = str[i];
		ptr[len] = '\0';

		return *this;
	}
	
	myString(const char* ai , const char* bi)
	{
		nullchar = '\0';
		myString a(ai);
		myString b(bi);
		len = a.len + b.len;
		ptr = new char[len+1];

		for(int i=0;i<a.len;i++)
			ptr[i] = a.ptr[i];
		for(int i=0;i<b.len;i++)
			ptr[a.len+i] = b.ptr[i];
		ptr[len] = '\0';
	}
	

	myString operator+(const myString& b)
	{
		return myString(ptr, b.ptr);
	}

	void print()
	{
		for(int i=0;i<len;i++)
			cout<<ptr[i];
		cout<<endl;
	}

	char lower(char a)
	{
		if(a>'a' and a<'z')
			return a;
		else if(a>'A' and a<'Z')
		{
			int k = a - 'A' + 'a';
			return (char)k;
		}
	}

	bool operator<(const myString& b)
	{
		int r = min(len,b.len);

		for(int i=0;i<r;i++)
		{
			int t = lower(ptr[i]) - lower(b.ptr[i]);
			if(t>0)
				return false;
		}
		if(len - b.len > 0)
			return false;

		return true;

	}
};