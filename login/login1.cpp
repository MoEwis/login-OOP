/*
 * REGISTER USER
 * LOGIN USER
 * SHOW USER LIST
 * SEARCH USER
 * DELETE USER
 * EXIT
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class USER
{
private:
    string username, password;

public:
    USER(string name, string pas)
    {
        username = name;
        password = pas;
    }
    string get_username()
    {
        return username;
    }
    string get_password()
    {
        return password;
    }
};
class USERMANAGER
{
private:
    vector<USER> users;

public:
    void RegisterUser()
    {
        string username, password;
        cout << " Enter User Name: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        USER newuser(username, password);
        users.push_back(newuser);
        cout << "\t\t User Register Successfully...\n";
    }
    bool loginuser(string name, string pas)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].get_username() == name && users[i].get_password() == pas)
            {
                cout << "\t\tlogin Successfully\n";
                return true;
            }
        }
        cout << "\t\tinvalid user name or password\n";
        return false;
    }
    void SHOW_USER_LIST()
    {
        for (int i = 0; i < users.size(); i++)
        {
            cout << users[i].get_username() << endl;
        }
    }
    void SEARCH_USER()
    {
        string name;
        for (int i = 0; i < users.size(); i++)
        {
            cout << "enter user name: ";
            cin >> name;
            if (users[i].get_username() == name)
            {
                cout << "user found: ";
                cout << users[i].get_username() << endl;
            }
            else
            {
                cout << "user is not found..\n";
            }
        }
    }
};
int main()
{
    USERMANAGER usermanager;
    int op;
    char ope;
    do
    {
        system("cls");
        cout << "1- REGISTER USER\n";
        cout << "2- LOGIN USER\n";
        cout << "3- SHOW USER LIST\n";
        cout << "4- SEARCH USER \n";
        cout << "5- DELETE USER\n";
        cout << "6- EXIT\n";
        cout << "Enter Your choice: ";
        cin >> op;
        switch (op)
        {
            {
        case 1:
            usermanager.RegisterUser();
            break;
            }
            {
        case 2:
            string username, password;
            cout << "enter user name: ";
            cin >> username;
            cout << "enter password: ";
            cin >> password;
            usermanager.loginuser(username, password);
            break;
            }
            {
        case 3:
            usermanager.SHOW_USER_LIST();
            break;
            }
            {
        case 4:
            usermanager.SEARCH_USER();
            break;
            }


        }


        cout << "Do You Want continue? [Yas / No]: ";
        cin >> ope;
    } while (ope == 'y' || ope == 'Y');
    return 0;
}