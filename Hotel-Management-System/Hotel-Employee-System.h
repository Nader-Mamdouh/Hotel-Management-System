#pragma once
#pragma once
#ifndef HOTEL_Employee_SYSTEM_H
#define HOTEL_Employee_SYSTEM_H

#include <iostream>
#include <map>
#include <string>
class ENode
{
public:
    int id;
    string name, address, email;
    double salary;
    ENode* next;

};
class Empl_management_system
{
public:
    ENode* head = NULL;
    ENode* temp = NULL;
    void insert()
    {
        int ID;
        string n;
        string mail;
        string add;
        double salary;

        cout << "\n\n Enter ID: ";
        cin >> ID;
        cout << "\n\n Enter Name: ";
        cin >> n;
        cout << "\n\n Enter Email: ";
        cin >> mail;
        cout << "\n\n Enter your Address: ";
        cin >> add;
        cout << "\n\n Enter your salary : ";
        cin >> salary;

        ENode* new_node = new ENode;
        new_node->id = ID;
        new_node->name = n;
        new_node->email = mail;
        new_node->address = add;
        new_node->salary = salary;

        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            ENode* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        cout << "\n\n\n New Record Node has been Inserted Successfully....";
    }
    void Search()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID for search: ";
            cin >> ID;
            ENode* ptr = head;
            while (ptr != NULL)
            {
                if (ID == ptr->id)
                {
                    cout << "\n\n ID: " << ptr->id;
                    cout << "\n\n Name: " << ptr->name;
                    cout << "\n\n Email: " << ptr->email;
                    cout << "\n\n Address: " << ptr->address;
                    cout << "\n\n Salary: " << ptr->address;

                    found++;
                }
                ptr = ptr->next;
            }
            if (found == 0)
            {
                cout << "\n\n Searched ID: " << ID << " Record Not Found...";
            }
        }
    }
    void update()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID to update: ";
            cin >> ID;
            ENode* ptr = head;
            while (ptr != NULL)
            {
                if (ID == ptr->id)
                {
                    cout << "\n\n Enter New ID: ";
                    cin >> ptr->id;
                    cout << "\n\n Enter New Name: ";
                    cin >> ptr->name;
                    cout << "\n\n Enter New Email: ";
                    cin >> ptr->email;
                    cout << "\n\n Enter New your Address: ";
                    cin >> ptr->address;
                    cout << "\n\n Enter New your salary: ";
                    cin >> ptr->salary;
                    found = 1;
                    cout << "\n\n Record Updated Successfully...";
                }
                ptr = ptr->next;
            }
            if (found == 0)
            {
                cout << "\n\n ID for Updation: " << ID << " Record Not Found...";
            }
        }
    }
    void Dequeue()
    {
        int element;
        cout << "Enter the element to delete: ";
        cin >> element;

        temp = head;
        ENode* prev = NULL;

        if (head == NULL)
        {
            cout << "Underflow\n";
            return;
        }

        if (temp != NULL && temp->id == element)
        {
            head = temp->next;
            cout << "Element deleted from queue is: " << temp->id << endl;
            delete temp;
            return;
        }

        while (temp != NULL && temp->id != element)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Element not found in queue.\n";
            return;
        }

        prev->next = temp->next;
        cout << "Element deleted from queue is: " << temp->id << endl;
        delete temp;
    }

    void Display()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            ENode* ptr = head;
            while (ptr != NULL)
            {
                cout << "\n\n ID: " << ptr->id;
                cout << "\n\n Name: " << ptr->name;
                cout << "\n\n Email: " << ptr->email;
                cout << "\n\n Address: " << ptr->address;
                cout << "\n\n salary: " << ptr->salary;

                ptr = ptr->next;
            }
        }
    }
    void Esetup()
    {
        // Empl_management_system Eobj;
        int choice;
        bool status = true;
        while (status)
        {
            cout << endl;
            cout << "************************************************************************************************************************\n\n\n";
            cout << "\t\t                        HOTEL Employee MANAGEMENT SYSTEM                        \t\t\n\n" << endl;
            cout << "***********************************************        MENU        *****************************************************\n\n";

            cout << "\n\n 1.Insert Employee: ";////
            cout << "\n\n 2.Search Employee: ";////
            cout << "\n\n 3.Update Employee: ";////
            cout << "\n\n 4.Delete Employee: ";/////
            cout << "\n\n 5.Show All Record: ";//// 
            cout << "\n\n 6.Exit";
            cout << "\n\n\n Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                insert();
                break;
            case 2:
                Search();
                break;
            case 3:
                update();
                break;
            case 4:
                Dequeue();
                break;
            case 5:
                Display();
                break;
            case 6:
                status = false;
                exit(0);
                break;

            }
        }
    }
};
#endif 

