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
//thanh vien 2
class PhoneBook {
private:
    vector<Contact> list;
    bool isPhoneExists(const string& checkPhone) {
        for (const auto& c : list) {
            if (c.phone == checkPhone) return true;
        }
        return false;
    }

public:
    void load() {
        ifstream file("ContactList.txt");
        if (!file) return;
        Contact c;
        while (getline(file, c.firstName)) {
            getline(file, c.lastName);
            file >> c.gender;
            file.ignore();
            getline(file, c.phone);
            getline(file, c.city);
            list.push_back(c);
        }
    }

    void save() {
        ofstream file("ContactList.txt");
        for (auto& c : list) {
            file << c.firstName << "\n" << c.lastName << "\n"
                << c.gender << "\n" << c.phone << "\n" << c.city << "\n";
        }
    }

    void addContact() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string p;
        cout << "Enter phone number (Primary Key): ";
        getline(cin, p);
        if (p.empty() || isPhoneExists(p)) {
            cout << "[Error] Invalid or duplicate phone number!\n";
            return;
        }
        Contact c;
        c.inputDetails(p);
        list.push_back(c);
        cout << "[Success] Contact added to memory.\n";
    }

    void displayContacts() {
        if (list.empty()) { cout << "No contacts.\n"; return; }
        cout << "\n----- Contact List -----\nID. First Name | Last Name | Gender | Phone | City\n";
        int i = 1;
        for (auto& c : list) c.display(i++);
        cout << "------------------------\n";
    }
//thanh vien 3
void searchByName() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string key;
        cout << "Enter name to search: ";
        getline(cin, key);
        key = toLower(key);
        int found = 0;
        for (auto &c : list) {
            if (toLower(c.firstName) == key || toLower(c.lastName) == key) {
                if (found == 0) cout << "\nFound Contact(s):\n";
                c.display(++found);
            }
        }
        if (!found) cout << "Not found.\n";
    }

    void searchByPhone() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string key;
        cout << "Enter phone to search: ";
        getline(cin, key);
        int found = 0;
        for (auto &c : list) {
            if (c.phone == key) {
                if (found == 0) cout << "\nFound Contact(s):\n";
                c.display(++found);
            }
        }
        if (!found) cout << "Not found.\n";
    }

    
    void searchByCity() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string key;
        cout << "Enter city to filter: ";
        getline(cin, key);
        key = toLower(key);
        int found = 0;
        for (auto &c : list) {
            if (toLower(c.city) == key) {
                if (found == 0) cout << "\nFound Contact(s):\n";
                c.display(++found);
            }
        }
        if (!found) cout << "Not found.\n";
    }
//thanh vien 4 
