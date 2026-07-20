#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if username already exists
bool userExists(string username)
{
    ifstream file("users.txt");

    string u, p;

    while(file >> u >> p)
    {
        if(u == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n----- Registration -----\n";

    cout << "Enter Username: ";
    cin >> username;

    if(userExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;

    cout << "\n----- Login -----\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");

    string u, p;

    while(file >> u >> p)
    {
        if(u == username && p == password)
        {
            cout << "\nLogin Successful!\n";
            file.close();
            return;
        }
    }

    file.close();

    cout << "\nInvalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n============================\n";
        cout << " Login & Registration System\n";
        cout << "============================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    }while(choice != 3);

    return 0;
}