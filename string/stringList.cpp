#include "myString.h"

struct stringNode
{
	myString name;
	stringNode* next;

	stringNode()
	{
		name = "";
		next = NULL;
	}
};

struct stringList
{
	stringNode* head;

	stringList()
	{
		head = NULL;
	}

	void appendNode(stringNode* end, myString someString)
	{
		if(end==NULL)
		{
			stringNode* k = new stringNode;
			k->name = someString;
			k->next = NULL;
			end = k;

			if(head==NULL)
				head = end;

			//cout<<1;		//checking whether control enters this part (for debugging only)
		}

		else if(end->next==NULL)
		{
			stringNode* k = new stringNode;
			k->name = someString;
			k->next = NULL;
			end->next = k;
			//cout<<3;		//checking whether control enters this part (for debugging only)
		}

		else
		{
			end = end->next;
			appendNode(end,someString);
			//cout<<2;			//checking whether control enters this part (for debugging only)
		}
	}

	void displayList(stringNode *b)
	{
		if(b==NULL)
			return;
		else
		{
			b->name.print();
			b = b->next;
			displayList(b);
		}
	}

	void reverseList()
	{
			stringNode* pNode = NULL;
			stringNode* cNode;

			if(head == NULL)
				cNode = NULL;
			else
				cNode = head;

			stringNode* nNode;
			if(cNode != NULL)
				nNode = head->next;
			else
				nNode = NULL;

			reverseIterate(pNode,cNode,nNode);
	}

	void reverseIterate(stringNode* pNode, stringNode* cNode, stringNode* nNode)
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

	void insertionSort(myString someString)		
	{
		stringNode* end = head;

		stringNode* freddy = head;
		displayList(freddy);

		//if(head==NULL)								//in case of NULL list, just add the element
			//appendNode(end,someString);


		else if(head->next==NULL)				//in case of only ONE node
		{
			if(!(head->name<someString))
			{
				stringNode* s =  new stringNode;
				s->name = someString;
				s->next = head;
				head = s;
				return;
			}
			else
			{
				appendNode(end,someString);
				return;
			}
		}

		else								//in case of more than one node.
		{
			if(!(head->name < someString))			//base case, whether the string is alphabetically lesser than the head element
			{
				stringNode* s = new stringNode;
				s->name = someString;
				s->next = head;
				head = s;
				return;
			}

			while(end->next!=NULL)					//finding the element where the letter fits
			{
				if(!(end->next->name < someString))
					break;

				end=end->next;
			}
			
			if(end->next==NULL)			// in case the element is in the last of the string
			{
				appendNode(end,someString);
			}		
			else					//appending in between the linked list
			{
				stringNode* s = new stringNode;
				s->name = someString;
				s->next = end->next;
				end->next = s;				
			}
		}

	}

};


int main()
{
	stringList strList;
	char choice = 'y';
	char temp[100];
	myString s;

	cout<<"Do you want to enter strings?\n";
	cin>>choice;

	while(choice=='y' or choice=='Y')		//enter your choices
	{
		cin>>temp;
		s = temp;
		strList.insertionSort(s);					//takes input and sorts them
		cout<<"Do you want to enter strings?\n";
		cin>>choice;
	}
	stringNode* end = strList.head;			
	strList.displayList(end);
}