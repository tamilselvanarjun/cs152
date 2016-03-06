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

	void reverseList()
	{
			Book* pNode = NULL;
			Book* cNode;

			if(head == NULL)
				cNode = NULL;
			else
				cNode = head;

			Book* nNode;
			if(cNode != NULL)
				nNode = head->next;
			else
				nNode = NULL;

			reverseIterate(pNode,cNode,nNode);
	}

	void reverseIterate(Book* pNode, Book* cNode, Book* nNode)
	{
		if(cNode==NULL)
		{
			return;
		}
		else if(nNode==NULL)
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
			reverseIterate(pNode,cNode,nNode);
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

	cout<<"Want to enter elements?\n";
	cin>>choice;

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
	
	myList.reverseList();

	myBook = myList.head;
	myList.displayList(myBook);

}