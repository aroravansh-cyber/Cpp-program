#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Expense {
    int id;
    string category;
    string description;
    double amount;
};

void addExpense() {
    Expense e;
    ofstream file("expenses.txt", ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    cout << "\nEnter Expense ID: ";
    cin >> e.id;

    cin.ignore();

    cout << "Enter Category: ";
    getline(cin, e.category);

    cout << "Enter Description: ";
    getline(cin, e.description);

    cout << "Enter Amount: Rs. ";
    cin >> e.amount;

    file << e.id << "|" << e.category << "|"
         << e.description << "|" << e.amount << "\n";

    file.close();

    cout << "\nExpense added successfully! \n";
}

void viewExpenses() {
    ifstream file("expenses.txt");
    Expense e;
    string line;

    if (!file) {
        cout << "\nNo expenses found.\n";
        return;
    }

    cout << "\n================ EXPENSES ================\n";

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);

        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
            continue;

        e.id = stoi(line.substr(0, p1));
        e.category = line.substr(p1 + 1, p2 - p1 - 1);
        e.description = line.substr(p2 + 1, p3 - p2 - 1);
        e.amount = stod(line.substr(p3 + 1));

        cout << "\nID          : " << e.id;
        cout << "\nCategory    : " << e.category;
        cout << "\nDescription : " << e.description;
        cout << "\nAmount      : Rs. " << fixed << setprecision(2) << e.amount;
        cout << "\n------------------------------------------";
    }

    file.close();
}

void totalExpense() {
    ifstream file("expenses.txt");
    string line;
    double total = 0;

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);

        if (p3 != string::npos) {
            total += stod(line.substr(p3 + 1));
        }
    }

    file.close();

    cout << "\nTotal Expenses: Rs. "
         << fixed << setprecision(2) << total << "\n";
}

void searchCategory() {
    ifstream file("expenses.txt");
    string category, line;
    bool found = false;

    cin.ignore();

    cout << "\nEnter category to search: ";
    getline(cin, category);

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);

        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
            continue;

        string currentCategory = line.substr(p1 + 1, p2 - p1 - 1);

        if (currentCategory == category) {
            cout << "\n" << line;
            found = true;
        }
    }

    if (!found)
        cout << "\nNo expenses found in this category.\n";

    file.close();
}

int main() {
    int choice;

    while (true) {
        cout << "\n\n========================================\n";
        cout << "          EXPENSE TRACKER\n";
        cout << "========================================\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Search by Category\n";
        cout << "4. Calculate Total Expense\n";
        cout << "5. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchCategory();
                break;

            case 4:
                totalExpense();
                break;

            case 5:
                cout << "\nThank you for using Expense Tracker! \n";
                return 0;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    }
}
