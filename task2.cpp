// Program for Login and Registration system using C++ programming language.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() 
{
    string username, password;
    cout << "Register\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Store username and password in a file
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

// Function to login a user
bool loginUser() 
{
    string username, password, storedUsername, storedPassword;
    cout << "Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check credentials from file
    ifstream file("users.txt");
    while (file >> storedUsername >> storedPassword) 
    {
        if (username == storedUsername && password == storedPassword) 
        {
            file.close();
            return true;  // Successful login
        }
    }
    file.close();
    return false;  // Failed login
}

int main()
{
    int choice;
    bool exitSystem = false;

    while (!exitSystem) 
    {
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) 
                {
                    cout << "Login successful!" << endl;
                } 
                else 
                {
                    cout << "Invalid username or password!" << endl;
                }
                break;
            case 3:
                exitSystem = true;
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}