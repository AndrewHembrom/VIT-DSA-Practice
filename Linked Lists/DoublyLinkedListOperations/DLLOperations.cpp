#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL
{
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void printList();
    void reverse();
    int size();
    int search(int data);
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insert(int data, int position);
    void deleteFirst();
    void deleteLast();
    void deleteElement(int data);
    void deleteList();
};

void DLL ::printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DLL ::reverse()
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int DLL ::size()
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

void DLL ::insertAtFirst(int data)
{
    // Empty list
    if (head == NULL)
    {
        Node *temp = new Node(data);
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
}

void DLL ::insertAtLast(int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void DLL ::insert(int data, int position)
{

    // insert at Start
    if (position == 1)
    {
        insertAtFirst(data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtLast(data);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int DLL ::search(int data)
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

void DLL ::deleteFirst()
{
    Node *temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        (temp->next)->prev = NULL;
        head = temp->next;
    }
    delete temp;
}

void DLL ::deleteLast()
{
    Node *temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        (temp->prev)->next = NULL;
        tail = temp->prev;
    }
    delete temp;
}

// void DLL ::deleteElement(int data)
// {
//     Node *prevNode, *deleteNode;
//     deleteNode = head;
//     while ((deleteNode->data != data) && (deleteNode != NULL))
//     {
//         prevNode = deleteNode;
//         deleteNode = deleteNode->next;
//     }
//     if (deleteNode->data == data)
//     {
//         prevNode->next = deleteNode->next;
//         delete deleteNode;
//     }
// }

void DLL ::deleteList()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

int main()
{
    DLL cool;
    cool.insertAtFirst(10);
    cool.insertAtLast(12);
    cool.insert(14, 3);
    cout << cool.size() << endl;
    cout << cool.search(14) << endl;

    cool.printList();
    cool.reverse();
    cool.deleteLast();
    cool.printList();

    return 0;
}