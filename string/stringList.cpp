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

	void trivialInsertionSort(stringNode* end)			//this method accepts the array and then sorts
	{
		if(end==head)
		{
			end = end->next;
			trivialInsertionSort(end);
		}
		else if(end==NULL)
			return;
		else
		{
			stringNode* start = head;
			stringNode* temp = head;
			
			
				if(end->name < head->name)
				{
					while(true)
					{
						if(start->next == end)
							break;
						start= start->next;
					}

					start->next = end->next;
					end->next = head;
					head = end;
					trivialInsertionSort(start->next);
				}

				else
				{
					stringNode* s = head;

					while(!(end->name < start->next->name))
						start = start->next;

					if(start->next == end)
						trivialInsertionSort(end->next);
					else
					{
						while(true)
						{
							if(s->next==end)
								break;
							s = s->next;
						}

						temp = start->next;
						start->next = end;
						s->next = end->next;
						
						end->next = temp;
						trivialInsertionSort(s->next);
					}

				}

		}
	}



	void insertionSort(myString someString)		//adds and sorts at a time 
	{
		stringNode* end = head;

		if(head==NULL)								//in case of NULL list, just add the element
			{
				appendNode(end,someString);
			}

		else if(head->next==NULL)				//in case of only ONE node
		{
			if(!(head->name < someString))
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
			if(someString < head->name)			//base case, whether the string is alphabetically lesser than the head element
			{
				stringNode* s = new stringNode;
				s->name = someString;
				s->next = head;
				head = s;
			}
			else
			{
				while(end->next!=NULL)					//finding the element where the letter fits
				{
					if(someString < end->next->name)
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

	}

};


int main()
{
	stringList strList;
	stringNode* h = strList.head;
	char choice = 'y';
	char temp[100];
	myString s;

	cout<<"Do you want to enter strings?\n";
	cin>>choice;

	while(choice=='y' or choice=='Y')		//enter your choices
	{
		cin>>temp;
		s = temp;
		h = strList.head;
		strList.appendNode(h,s);					
		cout<<"Do you want to enter strings?\n";
		cin>>choice;
	}

	h = strList.head;
	strList.displayList(h);
	cout<<"\n----------------------------------------\n";
	h = strList.head;
	strList.trivialInsertionSort(h);
	stringNode* end = strList.head;			
	strList.displayList(end);
}