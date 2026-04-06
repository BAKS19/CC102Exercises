#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct definition [cite: 45]
struct book {
    string barcode; [cite: 46]
    string title;   [cite: 48]
    int year;       [cite: 49]
    int rating;     [cite: 51]
};

// Function to determine category [cite: 65]
string getCategory(int rating) {
    switch(rating) {
        case 5: return "Excellent";
        case 4: return "Very Good";
        case 3: return "Good";
        case 2: return "Fair";
        case 1: return "Poor";
        default: return "No Rating";
    }
}

int main() {
    vector<book> library; [cite: 52]
    int choice;

    do {
        // Menu-Driven System [cite: 73, 75]
        cout << "\n--- Book Management System ---\n";
        cout << "1. Add Book\n2. Edit Book\n3. Delete Book\n4. Display Books\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            book b;
            cout << "Enter Barcode: ";
            cin >> b.barcode;

            // Unique Barcode Check [cite: 60, 62]
            bool exists = false;
            for (const auto& existing : library) {
                if (existing.barcode == b.barcode) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Error: Barcode already exists.\n"; [cite: 63]
            } else {
                cin.ignore();
                cout << "Enter Title: "; getline(cin, b.title); [cite: 57]
                cout << "Enter Year: "; cin >> b.year; [cite: 58]
                cout << "Enter Rating (0-5): "; cin >> b.rating; [cite: 59]
                library.push_back(b);
            }
        }
        else if (choice == 4) {
            // Table Display [cite: 66]
            cout << left << setw(15) << "Barcode" << setw(25) << "Title" << setw(10)
                 << "Year" << setw(10) << "Rating" << "Category" << endl;
            for (const auto& b : library) {
                cout << left << setw(15) << b.barcode << setw(25) << b.title << setw(10)
                     << b.year << setw(10) << b.rating << getCategory(b.rating) << endl; [cite: 72]
            }
        }
    } while (choice != 5); [cite: 79]

    return 0;
}
