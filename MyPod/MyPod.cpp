// LinkListExample1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// list Node Class
class node 
{
	char name[50];
	int song; // this could be any type or object
	node *next;
public:
	node(int x);
	friend class linkedList;
};

node::node(int x)
{
	song = x;
	next = NULL;
}

// Linked List Class
class linkedList
{
	node *head;
	node *tail;
public:
	linkedList();
	void addNodeToEnd(node *nptr);
	int removeNode(int i);
	void showList();
};

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

void linkedList::showList()
{
	node *ptr;
	ptr = head;
	cout << "****  Songs List *****" << endl;
	if (ptr == NULL)
	{
		cout << "list is empty " << endl;
		return;
	}
	
	while (ptr != NULL)
	{
		cout << "song " << ptr->song << endl;
		ptr = ptr->next;
	}
}

void linkedList::addNodeToEnd(node *ptr)
{
	// if list is empty
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}



/**/
int linkedList::removeNode(int i)
{
	node *ptr = head;
	if (ptr == NULL)  // empty list
		return -1;

	// if node is at the head
	if (head->song == i)
	{
		//if only 1 node in the list
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
			head = head->next;
		delete ptr;
		return 0;
	}

	while (ptr != NULL)
	{
		if (ptr->next && (ptr->next)->song == i)
		{
			if (tail == ptr->next)
				tail = ptr;
			node *tbd = ptr->next;
			ptr->next = (ptr->next)->next;
			delete tbd;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

int main()
{
	char answer;

	linkedList *mylist = new linkedList();
	// test if list is empty
	node *newnode = new node(1);
	mylist->addNodeToEnd(newnode);
	mylist->addNodeToEnd(new node(2));
	mylist->addNodeToEnd(new node(3));
	mylist->addNodeToEnd(new node(4));
	mylist->showList();

	cout << "Now playing song 1: White and Nerdy" << endl;
	cout << "Enter D to delete song or S to skip" << endl;
	cin >> answer;
	while (answer == 'D' || answer == 'd' || answer == 's' || answer == 'S')
	{
		if (answer == 'D' || answer == 'd')
			(mylist->removeNode(1));

		cout << "Now playing song 2: Amish Paradise" << endl;
		cout << "Enter D to delete song or S to skip" << endl;
		cin >> answer;
		if (answer == 'D' || answer == 'd')
			(mylist->removeNode(2));

		cout << "Now playing song 3: Eat It" << endl;
		cout << "Enter D to delete song or S to skip" << endl;
		cin >> answer;
		if (answer == 'D' || answer == 'd')
			(mylist->removeNode(3));

		cout << "Now playing song 4: Smells like Nirvana" << endl;
		cout << "Enter D to delete song or S to skip" << endl;
		cin >> answer;
		if (answer == 'D' || answer == 'd')
			(mylist->removeNode(4));

		mylist->showList();

		return 0;

	
	
	
	
	}

	
	
	mylist->showList();

    return 0;
}
