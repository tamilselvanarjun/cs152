#include "myString.h"

int main()
{
	myString a;		//default constructor
	myString b("Hello World!"); 	//parameterized constructor
	myString c(b);			//copy contructor

	a.print();		//doesnot print anything since string initialized to NULL
	b.print();		//prints "Hello World"
	c.print();		//prints same as b

	a = b;		//a is assigned b
	a.print();
	a = "Hi there";		// string a is reassigned to "Hi there" , a char array
	a.print();

	myString d = a + " " + b;		//concatenating 3 strings
	d.print();		//print the result

	//Accessing the individual elements 

	cout<<a[0]<<" "<<a[4]<<endl; 		//prints values
	cout<<a[100];		//handles out of order index exceptions

	
}