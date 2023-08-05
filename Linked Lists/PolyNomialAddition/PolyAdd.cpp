#include <iostream>
using namespace std;

// Polynomial Addition in Singly Linked List
// Created by Andrew Joy Hembrom

// Initialising Class Node.
class Node
{
public:
    int coeff;
    int pow;
    Node *next;
};

// Making a Polynomial Class and it's function
class Polynomial
{
    Node *head;

public:
    Polynomial()
    {
        // Setting Head pointer to NULL for an empty list.
        head = NULL;
    }

    // Declaring required functions for polynomial addition.
    void read();
    void insertTerm(int coeff, int pow);
    void display();
    void addPolynomial(const Polynomial &poly1, const Polynomial &poly2);
};

// Reading User inputs
void Polynomial ::read()
{
    int numTerms;
    cout << "Enter no. of terms: " << endl;
    cin >> numTerms;

    for (int i = 0; i < numTerms; ++i)
    {
        int coeff, pow;
        cout << "Enter coeff and power for term " << i + 1 << ": ";
        cin >> coeff >> pow;

        insertTerm(coeff, pow);
    }
}

// Inserting user inputs into the required polynomial list.
void Polynomial ::insertTerm(int coeff, int pow)
{
    Node *newNode = new Node{coeff, pow, nullptr};

    if (head == nullptr || pow > head->pow)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;

        while (current->next != nullptr && pow < current->next->pow)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// To display the required polynomial
void Polynomial ::display()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->coeff << "," << current->pow;
        if (current->next != nullptr)
        {
            cout << "->";
        }
        current = current->next;
    }
}

// Adding Algorithm for Polynomial Addition
// This function also calls display function and automatically displays the result of the two polynomials added.
void Polynomial ::addPolynomial(const Polynomial &poly1, const Polynomial &poly2)
{
    Polynomial result;
    Node *current1 = poly1.head;
    Node *current2 = poly2.head;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->pow > current2->pow)
        {
            result.insertTerm(current1->coeff, current1->pow);
            current1 = current1->next;
        }
        else if (current1->pow < current2->pow)
        {
            result.insertTerm(current2->coeff, current2->pow);
            current2 = current2->next;
        }
        else
        {
            int coeff_sum = current1->coeff + current2->coeff;
            if (coeff_sum != 0)
            {
                result.insertTerm(coeff_sum, current1->pow);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        result.insertTerm(current1->coeff, current1->pow);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        result.insertTerm(current2->coeff, current2->pow);
        current2 = current2->next;
    }

    result.display();
}

int main()
{

    Polynomial poly1, poly2, result;

    cout << "\nEnter the first polynomial: " << endl;
    poly1.read();
    // poly1.display();

    cout << "" << endl;
    cout << "\nEnter the second polynomial: " << endl;
    poly2.read();
    // poly2.display();

    cout << "" << endl;
    cout << "------------------" << endl;
    result.addPolynomial(poly1, poly2);
    cout << "\n------------------" << endl;

    return 0;
}