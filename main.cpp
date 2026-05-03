// thanh vien 1
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <string>


using namespace std;
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

class Contact {
public:
    string firstName, lastName, city, phone;
    char gender;

    void inputDetails(string p) {
        phone = p; 

        do {
            cout << "Enter first name: ";
            getline(cin, firstName);
            if (firstName.empty()) cout << "[Error] First name cannot be empty!\n";
        } while (firstName.empty());

        do {
            cout << "Enter last name: ";
            getline(cin, lastName);
            if (lastName.empty()) cout << "[Error] Last name cannot be empty!\n";
        } while (lastName.empty());

        cout << "Enter city: ";
        getline(cin, city);
        while (true) {
            cout << "Enter gender (M/F): ";
            cin >> gender;
            gender = toupper(gender); 
            if (gender == 'M' || gender == 'F') break;
            cout << "[Error] Invalid gender! Please enter M or F.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    void display(int id) const {
        cout << id << ". " << firstName << " | " << lastName
             << " | " << gender
             << " | " << phone
             << " | " << city << "\n";
    }
};
// thanh vien 2
