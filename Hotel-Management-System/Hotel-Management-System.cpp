#include <iostream>
#include<map>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include"Hotel-Reservation-System.h"
#include"Hotel-Employee-System.h"
#include"Hotel-Login & Register-System.h"

using namespace std;
/*    Project Members :
*     1) Nader Mamdouh ELzanaty     200013285
*     2) NourELdin Ekramy           200017737
*     3) Ibrahim Ahmed              200017733
*     4) Mohamed Ahmed              200013210
*     5) Mohamed Aymen              200013226
*/
int main()
{
    Login obj;
    int choice;
    cout << "************************************************************************************************************************\n\n\n";
    cout << "                                              Welcome To Login Page                               \n\n\n";
    cout << "***********************************************        MENU        *****************************************************\n\n";
    cout << "1.REGISTER" << endl;
    cout << "2.Login As HR" << endl;
    cout << "3.Login As RS" << endl;
    cout << "4.FORGOT PASSWORD (or) USERNAME" << endl;
    cout << "5.Exit" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        obj.registr();
        break;
    case 2:
        obj.loginHR();
        break;
    case 3:
        obj.loginRS();
    case 4:
        obj.forgot();
        break;
    case 5:
        cout << "Thanks for using this program.\n\n\n";
        break;
    }
}
