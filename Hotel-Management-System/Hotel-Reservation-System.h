#pragma once
#pragma once
#ifndef Hotel_Reservation_System_H
#define Hotel_Reservation_System_H
#include <iostream>
#include<vector>
#include<map>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int room_per_day = 1000;
/*    Project Members :
*     1) Nader Mamdouh ELzanaty     200013285
*     2) NourELdin Ekramy           200017737
*     3)Ibrahim Ahmed               200017733
*     4)Mohamed Ahmed               200013210
*     5)Mohamed Aymen               200013226
*/
class Node
{
public:
    int id;
    int price;
    int no_of_rooms_booked;
    int no_of_days_of_stay;
    string name, email, address;
    Node* next;
    Node* right = NULL;
    Node* left = NULL;
};

class  hotel_management_system : public Node
{
public:
    multimap<string, double>rate;
    Node* front = NULL;
    Node* rear = NULL;
    Node* temp = NULL;
    Node* bstRoot = NULL;
    Node* ptr = NULL;
    int ResRooms = 0;
    void insert()
    {
        system("cls");
        int ID, No_of_Rooms, days_of_stay;
        string n, mail, add;
        cout << "\n\n Enter ID: ";
        cin >> ID;
        cout << "\n\n Enter Name: ";
        cin >> n;
        cout << "\n\n Enter Email: ";
        cin >> mail;
        cout << "\n\n Enter your Address: ";
        cin >> add;
        cout << "\n\n Enter Number of Rooms: ";
        cin >> No_of_Rooms;
        ResRooms += No_of_Rooms;
        cout << "\n\n Enter Number of Days of your Stay: ";
        cin >> days_of_stay;

        Node* new_node = new Node;
        new_node->id = ID;
        new_node->name = n;
        new_node->email = mail;
        new_node->address = add;
        new_node->no_of_rooms_booked = No_of_Rooms;
        new_node->no_of_days_of_stay = days_of_stay;
        new_node->price = room_per_day * No_of_Rooms * days_of_stay;
        new_node->next = NULL;
        if (rear == NULL)
        {
            rear = new_node;
            front = rear;
            rear->next = front;
        }
        else
        {
            Node* temp = new_node;
            rear->next = temp;
            temp->next = front;
            rear = temp;
        }
        bstRoot = insertBST(bstRoot, new_node);
        cout << "\n\n\n New Record Node has been Inserted Successfully...." << '\n';

    }
    Node* insertBST(Node* root, Node* newNode)
    {
        if (root == NULL)
        {
            return newNode;
        }

        if (newNode->id <= root->id)
        {
            root->left = insertBST(root->left, newNode);
        }
        else if (newNode->id > root->id)
        {
            root->right = insertBST(root->right, newNode);
        }

        return root;
    }
    void inorderTraversal(Node* root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left);
            cout << root->id << " ";
            inorderTraversal(root->right);
        }
    }
    void displayBST()
    {
        cout << "Inorder traversal of the BST: ";
        inorderTraversal(bstRoot);
        cout << endl;
    }
    Node* searchBST(Node* root, int id)
    {
        if (root == NULL || root->id == id)
        {
            return root;
        }
        if (id < root->id)
        {
            return searchBST(root->left, id);
        }
        else
        {
            return searchBST(root->right, id);
        }
    }
    void searchByID()
    {
        system("cls");
        int searchID;
        cout << "\n\n Enter ID to search: ";
        cin >> searchID;

        Node* result = searchBST(bstRoot, searchID);
        if (result == NULL)
        {
            cout << "\n\n ID not found.";
        }
        else
        {
            cout << "\n\n ID found. Data in the node: ";
            cout << "\n\n ID: " << result->id;
            cout << "\n\n Name: " << result->name;
            cout << "\n\n Email: " << result->email;
            cout << "\n\n Address: " << result->address;
            cout << "\n\n Number of Rooms Booked: " << result->no_of_rooms_booked;
            cout << "\n\n Number of Days of Staying: " << result->no_of_days_of_stay;
            cout << "\n\n Total Bill: " << result->price;
            cout << endl;
        }
    }
    void dequeue()
    {
        system("cls");
        int element;
        double rat;
        if (front == NULL)
        {
            cout << "\n\n Empty Linked list...";
            return;
        }
        cout << "Enter the element to delete: ";
        cin >> element;
        temp = front;

        if (temp->next != front)
        {
            while (temp->next != front && temp->next->id != element)
            {
                temp = temp->next;
            }

            if (temp->next->id == element)
            {
                Node* deletedNode = temp->next;
                temp->next = temp->next->next;

                if (front == deletedNode)
                {
                    front = temp->next;
                }

                if (rear == deletedNode)
                {
                    rear = temp;
                }

                cout << "Element deleted from queue is: " << deletedNode->id << "\n";
                ResRooms -= deletedNode->no_of_rooms_booked;
                cout << "Enter your Rate out of 5 : ";
                cin >> rat;
                cout << endl;
                string nameofcustomer = deletedNode->name;
                rate.insert(make_pair(nameofcustomer, rat));
                delete deletedNode;
            }
            else
            {
                cout << "Element not found in queue.\n";
            }
        }
        else
        {
            if (front->id == element)
            {
                cout << "Element deleted from queue is: " << front->id << "\n";
                ResRooms -= front->no_of_rooms_booked;
                cout << "Enter your Rate out of 5: ";
                cin >> rat;
                cout << endl;
                string nameofcustomer = front->name;
                rate.insert(make_pair(nameofcustomer, rat));
                delete front;
                front = NULL;
                rear = NULL;
            }
            else
            {
                cout << "Element not found in queue.\n";
            }
        }
    }

    void showrate()
    {
        system("cls");
        if (rate.empty())
        {
            cout << " There is no rate yet !! " << endl;
        }
        else
        {
            for (auto k : rate)
            {
                cout << k.first << " His rate was : " << k.second << '\n';
            }
        }

    }

    void update()
    {
        system("cls");
        if (rear == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID to update: ";
            cin >> ID;
            Node* ptr = rear->next;
            do
            {
                if (ID == ptr->id)
                {
                    cout << "\n\n Enter New ID: ";
                    cin >> ptr->id;
                    cout << "\n\n Enter New Name: ";
                    cin >> ptr->name;
                    cout << "\n\n Enter New Email: ";
                    cin >> ptr->email;
                    cout << "\n\n Enter New Address: ";
                    cin >> ptr->address;
                    cout << "\n\n Enter New Number of Rooms: ";
                    cin >> ptr->no_of_rooms_booked;
                    cout << "\n\n Enter New Number of Days of Stay: ";
                    cin >> ptr->no_of_days_of_stay;
                    ptr->price = room_per_day * ptr->no_of_rooms_booked * ptr->no_of_days_of_stay;
                    found = 1;
                    cout << "\n\n Record Updated Successfully...";
                    break;
                }
                ptr = ptr->next;
            } while (ptr != rear->next);

            if (found == 0)
            {
                cout << "\n\n ID for Updation: " << ID << " Record Not Found...";
            }
        }
    }
    void Display()
    {
        system("cls");
        if (rear == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            Node* ptr = rear->next;
            do
            {
                cout << "\n\n ID: " << ptr->id;
                cout << "\n\n Name: " << ptr->name;
                cout << "\n\n Email: " << ptr->email;
                cout << "\n\n Address: " << ptr->address;
                cout << "\n\n Number of Rooms Booked: " << ptr->no_of_rooms_booked;
                cout << "\n\n Number of Days of Staying: " << ptr->no_of_days_of_stay;
                cout << "\n\n Total Bill: " << ptr->price;
                cout << endl;
                ptr = ptr->next;
            } while (ptr != rear->next);
            cout << "The total rooms booked in the hotel are " << ResRooms << endl;
        }
    }
    void setup()
    {
        //hotel_management_system obj;
        bool status = true;
        int choice;
        while (status)
        {
            cout << endl;
            cout << "************************************************************************************************************************\n\n\n";
            cout << "\t\t\t\t\t\tHOTEL MANAGEMENT SYSTEM\t\t\n\n" << endl;
            cout << "************************************************************************************************************************\n\n\n";
            cout << "\n\n 1. Check IN: ";////
            cout << "\n\n 2. Search Record:";////
            cout << "\n\n 3. Update Record:";////
            cout << "\n\n 4. Check Out: ";/////
            cout << "\n\n 5. Show All Records:";////
            cout << "\n\n 6. Show All Rates: ";
            cout << "\n\n 7. Exit";
            cout << "\n\n\n Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                insert();
                break;
            case 2:
                displayBST();
                break;
            case 3:
                update();
                break;
            case 4:
                dequeue();
                break;
            case 5:
                Display();
                break;
            case 6:
                showrate();
                break;
            case 7:
                status = false;
                break;

            }
        }
    }
};
#endif 
