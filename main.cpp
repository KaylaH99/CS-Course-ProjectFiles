#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    //Initialize variables
    int size = 80;
    bool upper = false, lower = false, digit = false;
    char password[size];

    //Get password from the user
    cout << "Please enter your password \n";
    cin.getline(password, size);

    //Verify password length
    if (strlen(password) <= 6){
        cout << "Password needs to be at least 6 characters long";
        exit(0);
    }

    //Test password for uppercase characters
    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i])){
            upper = true;
            break;
        }
    }

    //Test password for lowercase characters
    for(int i = 0; i < strlen(password); i++){
        if(islower(password[i])){
            lower = true;
            break;
        }
    }

    //Send user feedback on password
    if(upper == false || lower == false){
        cout << "Passwords need at least one uppercase and lowercase letter";
        exit(0);
    }

    //Test if password has a digit
    for(int i = 0; i < strlen(password); i++){
        if(isdigit(password[i])){
            digit = true;
            break;
        }
    }

    if(digit == false){
        cout << "Passwords need at least one number";
        exit(0);
    }

    //Send final verification
    cout << "Your password is valid";

    return 0;
}
