#include <iostream>
#include <fstream>
using namespace std;

void addStudent() {
    ofstream file("students.txt", ios::app);

    string name;
    int roll;
    float marks;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> roll;

    cout << "Enter Marks: ";
    cin >> marks;

    file << roll << "|" << name << "|" << marks << endl;

    file.close();

    cout << "\nStudent record added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");

    int roll;
    string name;
    float marks;
    char separator;

    cout << "\n----- Student Records -----\n";

    while (file >> roll >> separator) {
        getline(file, name, '|');
        file >> marks;

        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "---------------------------\n";
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");

    int searchRoll, roll;
    string name;
    float marks;
    char separator;

    cout << "\nEnter Roll Number to Search: ";
    cin >> searchRoll;

    bool found = false;

    while (file >> roll >> separator) {
        getline(file, name, '|');
        file >> marks;

        if (roll == searchRoll) {
            cout << "\nStudent Found!\n";
            cout << "Roll: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                cout << "\nProgram ended.";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}
