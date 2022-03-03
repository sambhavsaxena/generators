// Code by Sambhav Saxena
// Date:03/03/2022
// Roll number: 20001001100
// Class: CSE-B
// DSA Internal Assignment

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long int roll;
    int age;
    string name;
    char gender;
    Node *next;
};

void push(Node **head)
{
    Node *new_node = new Node();
    long long int roll;
    int age;
    string name;
    char gender;
    cout << "Enter the roll number:\t";
    cin >> roll;
    cout << "Enter the age:\t";
    cin >> age;
    cout << "Enter the gender:  ";
    cin >> gender;
    cout << "Enter the name:\t";
    cin >> name;
    new_node->roll = roll;
    new_node->age = age;
    new_node->gender = gender;
    new_node->name = name;
    new_node->next = *head;
    *head = new_node;
}

void delete_node(Node **head)
{
    Node *current = *head;
    Node *prev = NULL;
    long long int roll;
    cout << "Enter the roll number of the student whose record you want to delete:\t";
    cin >> roll;
    if (current->roll == roll)
    {
        *head = current->next;
        delete current;
    }
    else
    {
        while (current != NULL && current->roll != roll)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            return;
        }
        prev->next = current->next;
        delete current;
    }
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->roll << "\t\t\t" << head->age << "\t\t\t\t" << head->gender << "\t\t\t\t" << head->name << endl;
        head = head->next;
    }
}

void writetofile(Node *head)
{
    ofstream o("output.txt", ios::app);
    Node *current = head;
    while (current != NULL)
    {
        o << current->roll << "\t\t\t" << current->age << "\t\t\t\t" << current->gender << "\t\t\t\t" << current->name << endl;
        current = current->next;
    }
    o.close();
}

int main()
{
    Node *head = NULL;
    int integ, input;
    do
    {
        cout << "Enter the action you wish to perform:\n\n";
        cout << "Enter '1' for Adding a student record to the current list\n";
        cout << "Enter '2' for Deleting a student record from the current list\n";
        cout << "Enter '3' for Printing the current list to the console\n";
        cout << "Enter '4' for Displaying data in the file\n";
        cout << "Enter '5' for Saving the entire list record to a file\n";
        cin >> input;
        if (input == 1)
        {
            push(&head);
            cout << "Added✓" << endl;
        }
        else if (input == 2)
        {
            delete_node(&head);
            cout << "Deleted✓" << endl;
        }
        else if (input == 3)
        {
            printlist(head);
        }
        else if (input == 4)
        {
            string t;
            ofstream o("output.txt", ios::app);
            ifstream i("output.txt");
            cout << "\n\n\nThe file contains the following entries:\n\n";
            while (!i.eof())
            {
                getline(i, t);
                cout << t << endl;
            }
        }
        else if (input == 5)
        {
            writetofile(head);
            cout << "Saved✓" << endl;
        }
        else
        {
            cout << "Invalid input\n";
        }
        cout << "Do you want to continue?\n";
        cout << "Enter '1' for yes or any other key to exit: ";
        cin >> integ;
        if (integ != 1)
        {
            break;
        }
    } while (integ == 1);
    return 0;
}
