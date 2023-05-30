#pragma once
#pragma once
#ifndef Hotel_Login_System_H
#define Hotel_Login_System_H
#include <iostream>
#include<vector>
#include<map>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
class Login : public  hotel_management_system, public Empl_management_system
{
public:
    void loginHR()
    {
        int count;
        string user, pass, u, p;
        system("cls");
        cout << "please enter the following details" << endl;
        cout << "USERNAME :";
        cin >> user;
        cout << "PASSWORD :";
        cin >> pass;
        bool check = false;
        ifstream input("HotelSys.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                check = true;
                system("cls");
            }
        }
        input.close();
        if (check)
        {
            cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
            system("cls");
            Esetup();
        }
        else
        {
            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            loginHR();
        }

    }
    void loginRS()
    {
        int count;
        string user, pass, u, p;
        system("cls");
        cout << "please enter the following details" << endl;
        cout << "USERNAME :";
        cin >> user;
        cout << "PASSWORD :";
        cin >> pass;
        bool check = false;
        ifstream input("HotelSys.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                check = true;
                system("cls");
            }
        }
        input.close();
        if (check)
        {
            cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
            system("cls");
            setup();
        }
        else
        {
            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            loginRS();
        }
    }
    void registr()
    {
        string reguser, regpass, ru, rp;
        system("cls");
        cout << "Enter the username :";
        cin >> reguser;
        cout << "\nEnter the password :";
        cin >> regpass;

        ofstream reg("HotelSys.txt", ios::app);
        reg << reguser << ' ' << regpass << endl;
        system("cls");
        cout << "\nRegistration Sucessful\n";
        int num;
        cout << "1) Login as HR  " << endl;
        cout << "2) Login as reseption   " << endl;
        cout << "Enter your choice :";
        cin >> num;
        switch (num)
        {
        case 1:
            loginHR();
            break;
        case 2:
            loginRS();
            break;
        }
    }
    void forgot()
    {
        int ch;
        system("cls");
        cout << "Forgotten ? We're here for help\n";
        cout << "1.Search your id by username" << endl;
        cout << "2.Search your id by password" << endl;
        cout << "Enter your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int count = 0;
            string searchuser, su, sp;
            cout << "\nEnter your remembered username :";
            cin >> searchuser;

            ifstream searchu("HotelSys.txt");
            while (searchu >> su >> sp)
            {
                if (su == searchuser)
                {
                    count = 1;
                }
            }
            searchu.close();
            if (count == 1)
            {
                cout << "\n\nsuccessful, account found\n";
                cout << "\nYour password is " << sp;
                cout << endl;
                int num;
                cout << "1) Login as HR  " << endl;
                cout << "2) Login as reseption   " << endl;
                cout << "Enter your choice :";
                cin >> num;
                switch (num)
                {
                case 1:
                    loginHR();
                    break;
                case 2:
                    loginRS();
                    break;
                }
            }
            else
            {
                cout << "\nSorry, Your userID is not found in our system\n";
                cout << "Do you want to register New Username and Password : y/n";
                char c;
                cin >> c;
                if (c == 'y')
                {
                    registr();
                }
            }
            break;
        }
        case 2:
        {
            int count = 0;
            string searchpass, su2, sp2;
            cout << "\nEnter the remembered password :";
            cin >> searchpass;

            ifstream searchp("HotelSys.txt");
            while (searchp >> su2 >> sp2)
            {
                if (sp2 == searchpass)
                {
                    count = 1;
                }
            }
            searchp.close();
            if (count == 1)
            {
                cout << "\nYour password is found in the system \n";
                cout << "\nYour Id is : " << su2;
                cout << endl;
                int num;
                cout << "1) Login as HR  " << endl;
                cout << "2) Login as reseption   " << endl;
                cout << "Enter your choice :";
                cin >> num;
                switch (num)
                {
                case 1:
                    loginHR();
                    break;
                case 2:
                    loginRS();
                    break;

                }
            }
            else
            {
                cout << "Sorry, We cannot found your password in our system \n";
                cout << "Do you want to register New Username and Password : y/n";
                char c;
                cin >> c;
                if (c == 'y')
                {
                    registr();
                }
            }
        }
        default:
            cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
            forgot();
        }
    }
};
#endif
