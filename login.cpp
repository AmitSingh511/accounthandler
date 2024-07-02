#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class account
{
private:
    string username, email, password, epass;

public:
    void signup(); // Function prototype for signing up
    void login();  // Function prototype for logging in
    void forgot();
};

int main()
{
    account a1;           // Create an instance of the account class
    cout << "\n1-LOGIN";  // Display option for login
    cout << "\n2-SIGNUP"; // Display option for signup
    cout << "\n3-FORGOT PASSWORD"<<endl;
    int choice;
    cin >> choice; // Read the user's choice
    cin.ignore();  // Ignore the newline character left in the buffer after cin

    // Switch to handle the user's choice
    switch (choice)
    {
    case 1:
        a1.login(); // Call the login function
        break;
    case 2:
        a1.signup(); // Call the signup function
        break;
    case 3:
        a1.forgot();
        break;
    default:
        cout << "invalid choice" << endl; // Display message for invalid choice
    }

    return 0;
}

// Function definition for signing up
void account::signup()
{
    cout << "\t\t\t---------------------------------------WELCOME TO SIGN UP PAGE------------------------------------------------" << endl; // Display signup page heading
    cout << "enter your E-MAIL address" << endl;                                                                                            // Prompt for email
    getline(cin, email);                                                                                                                    // Read email input
    cout << "enter the EMAIL PASSWORD for sign up" << endl;
    getline(cin, epass);
    cout << "enter your USERNAME" << endl;      // Prompt for username
    getline(cin, username);                     // Read username input
    cout << "create a strong password" << endl; // Prompt for password
    getline(cin, password);                     // Read password input
    ofstream out("signup.txt", ios::app);       // Open signup.txt file for appending
    if (out.is_open())                          // Check if the file is successfully opened
    {
        out << "USERNAME:" << username << endl;     // Write username to file
        out << "EMAIL:" << email << endl;           // Write email to file
        out << "PASSWORD:" << password << endl;     // Write password to file
        out << "E-MAIL KEY:" << epass << endl; // write email password
        out << "-------------------------" << endl; // Write separator to file
        out.close();                                // Close the file
        cout << "SIGN-UP is SUCCESSFULL";           // Display success message
    }
    else
        cout << "ERROR! file not opening" << endl; // Display error message if file not opened
}

// Function definition for logging in
void account::login()
{
    cout << "------------------------WELCOME TO LOGIN PAGE------------------------" << endl; // Display login heading
    cout << "enter the useranme" << endl;                                                    // Prompt for username
    getline(cin, username);                                                                  // Read username input
    cout << "enter the password" << endl;                                                    // Prompt for password
    getline(cin, password);                                                                  // Read password input
    ifstream in("signup.txt");                                                               // Open signup.txt file for reading
    if (in.is_open())                                                                        // Check if the file is successfully opened
    {
        string line;              // Variable to store each line of the file
        bool found = false;       // Flag to indicate if username is found
        while (getline(in, line)) // Read each line of the file
        {
            if (line.find("USERNAME:" + username) != string::npos) // Check if the line contains the username
            {
                found = true;      // Set found flag to true
                getline(in, line); // Read the next line (email)--unneccessary
                getline(in, line); // Read the next line (password)

                if (line.find("PASSWORD:" + password) != string::npos) // Check if the line contains the password
                {
                    cout << "CONGRATULATIONS!--LOGIN SUCCESSFULL--" << endl; // Display success message
                    in.close();                                              // Close the file
                    return;
                }
                else
                {
                    cout << "incorrect password! try again later" << endl; // Display error message for incorrect password
                    in.close();                                            // Close the file

                    return;
                }
            }
        }
        if (!found) // Check if username is not found
        {
            cout << "username not found!signup first" << endl; // Display error message for username not found
        }
        in.close(); // Close the file
    }
    else
    {
        cout << "unable to open file" << endl; // Display error message if file not opened
    }
}
void account::forgot()
{
    cout << "enter the username :" << endl;
    getline(cin, username);
    cout << "enter your email address" << endl;
    getline(cin, email);
    cout << "enter the email password" << endl;
    getline(cin, epass);
    ifstream in("signup.txt"); // read
    if (in.is_open())
    {
        string line;
        bool found = false;
        while (getline(in, line))
        {
            if (line.find("USERNAME:" + username) != string::npos)
            {
                // cout<<"read=="<<line <<endl;
                getline(in, line);
                
                found=true;

                if (line.find("EMAIL:" + email) != string::npos)
                {
                    // cout<<"read"<<line<<endl;
                    getline(in, line);
                    // cout<<"read"<<line;
                   string pos=line;
                   getline(in,line);
                    if (line.find("E-MAIL KEY:" + epass) != string::npos)
                    {
                        // cout<<"read"<<line;
                        cout<<endl;
                        cout << "---------password matched!---------"<< endl;      
                        cout<<pos;            
                       break;
                    }
                    else
                    {
                        cout << "EMAIL password is incorrect" << endl;
                        cout<<"SORRY!unable to restore the password"<<endl;
                        in.close();
                        break;
                        
                    }
                }
                    else
                    {
                        cout << " email not found" << endl;
                        break;
                    }
            }
        }
                    if (!found)
                    {
                        cout << "username not found" << endl;
                        
                    }
                    in.close();
                }
               
}
            
        
    

