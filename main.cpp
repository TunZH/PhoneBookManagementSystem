void pauseScreen() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    PhoneBook pb;
    pb.load();
    const string ADMIN_PASSWORD = "Admin";
    int choice;

    while (true) {
        cout << "\n=== PHONE BOOK MANAGEMENT SYSTEM ===\n1. Admin Login\n2. Guest Access (User)\n3. Exit System\nChoose role: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        if (choice == 1) {
            string pwd;
            cout << "Enter security password: ";
            cin >> pwd;
            if (pwd == ADMIN_PASSWORD) {
                while (true) {
                    cout << "\n=== ADMIN MENU ===\n1. Add Contact\n2. Update Contact\n3. Delete Contact\n4. Delete All Contact\n5. Display Contact\n6. Search By Name\n7. Search By Phone\n8. Search By City\n9. Logout\n10. Exit\nChoice: ";
                    cin >> choice;
                    if (choice == 10) { pb.save(); return 0; }
                    if (choice == 9) break;
                    switch (choice) {
                        case 1: pb.addContact(); break;
                        case 2: pb.updateContact(); break;
                        case 3: pb.deleteContact(); break;
                        case 4: pb.deleteAll(); break;
                        case 5: pb.displayContacts(); break;
                        case 6: pb.searchByName(); break;
                        case 7: pb.searchByPhone(); break;
                        case 8: pb.searchByCity(); break;
                        default: cout << "Invalid.\n";
                    }
                    pauseScreen();
                }
            } else cout << "[Error] Wrong password!\n";
        } else if (choice == 2) {
            while (true) {
                cout << "\n=== USER MENU ===\n1. Display\n2. Search Name\n3. Search Phone\n4. Search City\n5. Logout\n6. Exit\nChoice: ";
                cin >> choice;
                if (choice == 6) { pb.save(); return 0; }
                if (choice == 5) break;
                switch (choice) {
                    case 1: pb.displayContacts(); break;
                    case 2: pb.searchByName(); break;
                    case 3: pb.searchByPhone(); break;
                    case 4: pb.searchByCity(); break;
                    default: cout << "Invalid.\n";
                }
                pauseScreen();
            }
        } else if (choice == 3) break;
    }
    pb.save();
    return 0;
}
