#include <iostream>
using namespace std;

// SINGLY LINKED LIST OPERATIONS
// created by Andrew Joy Hembrom 22BLC1234.

class Node
{
public:
	int data;
	Node *next;

	// Initialising a constructor for making new nodes easily.
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class MyLinkedList
{
	// Declaring head node.
	Node *head;

public:
	MyLinkedList()
	{
		head = NULL;
	}

	// Declaring all the functions that will be used.
	void printList();
	int search(int data);
	int size();
	void insertAtFirst(int data);
	void insertAtEnd(int data);
	void insert(int data, int position);
	void deleteFirstElement();
	void deleteLastElement();
	void deleteElement(int data);
	void reverseList();
	void deleteList();
};

void MyLinkedList ::printList()
{
	// If the list is empty.
	if (head == NULL)
	{
		cout << " " << endl;
		return;
	}

	// Printing list in the required Format.
	Node *temp = head;
	int cnt = size();
	while (temp != NULL)
	{
		if (cnt == 1)
		{
			cout << temp->data;
			temp = temp->next;
		}
		else
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cnt--;
	}
	cout << " " << endl;
}

// For Searching for an Element in the list.
int MyLinkedList ::search(int data)
{
	Node *ptr;
	ptr = head;
	int cnt = 1;
	while (ptr != NULL)
	{
		if (ptr->data == data)
		{
			return cnt;
		}
		ptr = ptr->next;
		cnt++;
	}
	return -1;
}

// To get the size of the list.
int MyLinkedList ::size()
{
	Node *ptr;
	ptr = head;
	int cnt = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		cnt++;
	}
	return cnt;
}

// Inserting Element at the Start of the list.
void MyLinkedList ::insertAtFirst(int data)
{
	Node *temp = new Node(data);
	temp->next = head;
	head = temp;
}

// Inserting Element at the End of the list.
void MyLinkedList ::insertAtEnd(int data)
{
	Node *newNode = new Node(data);
	Node *temp = head;

	// If the initial list is empty.
	if (temp == NULL)
	{
		Node *temp = new Node(data);
		temp->next = head;
		head = temp;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

// Inserting Element at a specific position in the list.
void MyLinkedList ::insert(int data, int position)
{
	Node *newNode, *temp;
	temp = head;
	int cnt = 1;

	// Inserting at the first position.
	if (position == 1)
	{
		insertAtFirst(data);
		return;
	}

	while (temp != NULL)
	{
		if (cnt == position - 1)
		{
			break;
		}
		temp = temp->next;
		cnt++;
	}

	// If given position is larger than the size
	if (position > size())
	{
		cout << "Not a Valid Position." << endl;
		return;
	}
	newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

// Deleting First Element of the list.
void MyLinkedList ::deleteFirstElement()
{
	Node *temp;
	if (head == NULL)
	{
		return;
	}
	else
	{
		temp = head;
		head = temp->next;
		delete temp;
	}
}

// Deleting Last Element of the list.
void MyLinkedList ::deleteLastElement()
{
	Node *prevTail, *tail;
	if (head == NULL)
	{
		return;
	}
	else if (head->next == NULL)
	{
		tail = head;
		head = NULL;
		delete tail;
	}
	else
	{
		prevTail = head;
		tail = prevTail->next;
		while (tail->next != NULL)
		{
			prevTail = tail;
			tail = tail->next;
		}
		prevTail->next = NULL;
		delete tail;
	}
}

// Deleting a specific Element from the list.
void MyLinkedList ::deleteElement(int data)
{
	Node *prevNode, *deleteNode;
	deleteNode = head;
	while ((deleteNode->data != data) && (deleteNode != NULL))
	{
		prevNode = deleteNode;
		deleteNode = deleteNode->next;
	}
	if (deleteNode->data == data)
	{
		prevNode->next = deleteNode->next;
		delete deleteNode;
	}
}

// Reversing the list.
void MyLinkedList ::reverseList()
{
	Node *prevNode, *currentNode, *nextNode;
	prevNode = NULL;
	currentNode = head;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	head = prevNode;
}

// Deleting the Entire List.
void MyLinkedList ::deleteList()
{
	Node *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	MyLinkedList list;

	// Using Singly Linked List Operations as Required.
	cout << list.size() << endl;
	list.insertAtEnd(5);
	list.printList();
	list.insertAtFirst(10);
	list.printList();
	list.insert(12, 2);
	list.printList();
	list.insertAtFirst(4);
	list.printList();
	list.insert(56, 3);
	list.printList();
	cout << list.search(12) << endl;
	cout << list.search(15) << endl;
	list.reverseList();
	list.printList();
	cout << list.size() << endl;
	list.deleteFirstElement();
	list.printList();
	list.deleteElement(10);
	list.printList();
	list.deleteLastElement();
	list.printList();
	list.deleteList();
	list.printList();
	cout << list.size() << endl;

	return 0;
}