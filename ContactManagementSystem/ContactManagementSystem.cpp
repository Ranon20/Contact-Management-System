// ContactManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact
{
    int id;
    char name[50];
    char phone[15];
};

void AddContact()
{
    ofstream file("phonebook.dat", ios::app | ios::binary);
    if (!file)
    {
        cout << "Error opening file\n";
    }
    else
    {
        Contact c;
        cout << "Enter id: ";
        cin >> c.id;

        cout << "Enter Name: ";
        cin >> c.name;

        cout << "Enter Phone: ";
        cin >> c.phone;

        file.write((char*)&c, sizeof(c));
        file.close();
    }
}
void viewContact()
 {
        ifstream file("phonebook.dat", ios::in | ios::binary);

        if (!file)
        {
            cout << "File not found\n";
        }
        else
        {
            Contact c;
            while (file.read((char*)&c, sizeof(c)))
            {
                cout << "ID: " << c.id << endl;
                cout << "Name: " << c.name << endl;
                cout << "Phone: " << c.phone << endl;
                cout << "----------------------------\n";
            }
        }
 }
void searchContact()
{
    ifstream file("phonebook.dat", ios::in | ios::binary);

    if (!file)
    {
        cout << "File not found\n";
        return;
    }

    int n;
    cout << "Enter record number: ";
    cin >> n;

    
    if (n <= 0)
    {
        cout << "Invalid record number\n";
        return;
    }

    Contact c;

    file.seekg((n - 1) * sizeof(Contact));

    file.read((char*)&c, sizeof(c));

    if (file)   
    {
        cout << "ID: " << c.id << endl;
        cout << "Name: " << c.name << endl;
        cout << "Phone: " << c.phone << endl;
    }
    else
    {
        cout << "Record not found\n";
    }

    file.close();
}

int main()
{
    int choice;

    do {
        cout << "\n1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: AddContact(); break;
        case 2: viewContact(); break;
        case 3: searchContact(); break;
        }

    } while (choice != 4);
}
