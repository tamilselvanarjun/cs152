#include <iostream>
#include <string>
using namespace std;

struct Book
{
	string name;
	double price;
	Book* next;

	Book()
	{
		name = "";
		price = 0;
		next = NULL;
	}
};

//The book struct has been made above

struct bookList
{
	Book* head;

	bookList()
	{
		head = NULL;
	}

	void appendNode(Book* end, string bookName, double bookPrice)
	{
		if(end==NULL)
		{
			Book* k = new Book;
			k->name = bookName;
			k->price = bookPrice;
			k->next = NULL;
			end = k;

			if(head==NULL)
				head = end;

			//cout<<1;		//checking whether control enters this part (for debugging only)
		}

		else if(end->next==NULL)
		{
			Book* k = new Book;
			k->name = bookName;
			k->price = bookPrice;
			k->next = NULL;
			end->next = k;

			//cout<<3;		//checking whether control enters this part (for debugging only)
		}

		else
		{
			end = end->next;
			appendNode(end,bookName,bookPrice);
			
			//cout<<2;			//checking whether control enters this part (for debugging only)
		}
	}

	void displayList(Book *b)
	{
		if(b==NULL)
			return;
		else
		{
			cout<<"Name: "<<b->name<<endl;
			cout<<"Price: "<<b->price<<endl<<endl;
			b = b->next;
			displayList(b);
		}
	}

	void reverseList(Book* pNode, Book* cNode, Book* nNode)
	{
		if(nNode==NULL)
		{
			cNode->next = pNode;
			head = cNode;
		}
		else
		{
			cNode->next = pNode;
			pNode = cNode;
			cNode = nNode;
			nNode = nNode->next;
			reverseList(pNode,cNode,nNode);
		}
	}

};



int main()
{
	bookList myList;
	char choice='y';
	Book* myBook = NULL;
	
	string myBookName;
	double myBookPrice;

	while(choice=='y' or choice=='Y')
	{
		cout<<"Enter name of Book.\n";
		cin>>myBookName;

		cout<<"Enter price of Book.\n";
		cin>>myBookPrice;

		Book* t = myList.head;
		myList.appendNode(t,myBookName,myBookPrice);

		cout<<"Enter more elements?\n";
		cin>>choice;
	}
	myBook = myList.head;
	myList.displayList(myBook);

	Book* pNode = NULL;
	Book* cNode = myList.head;
	Book* nNode = myList.head->next;
	myList.reverseList(pNode,cNode,nNode);

	myBook = myList.head;
	myList.displayList(myBook);

}