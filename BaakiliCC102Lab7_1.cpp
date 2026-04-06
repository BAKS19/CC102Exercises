#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct definition [cite: 5]
struct student {
    string studentID; [cite: 6]
    string name;      [cite: 7]
    string course;    [cite: 9]
    double gpa;       [cite: 11]
};

// Function to determine academic standing [cite: 25]
string getStanding(double gpa) {
    if (gpa >= 90) return "Excellent";
    if (gpa >= 80) return "Very Good";
    if (gpa >= 70) return "Good";
    if (gpa >= 60) return "Passing";
    return "Failed";
}

int main() {
    vector<student> students; [cite: 12]
    int choice;

    do {
        // Menu-Driven System [cite: 32, 33]
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Edit Student\n3. Delete Student\n4. Display Students\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            student s;
            cout << "Enter Student ID: ";
            cin >> s.studentID;

            // Unique ID Check [cite: 20, 22]
            bool exists = false;
            for (const auto& existing : students) {
                if (existing.studentID == s.studentID) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Error: Student ID already exists. Try again.\n"; [cite: 23]
            } else {
                cin.ignore();
                cout << "Enter Name: "; getline(cin, s.name); [cite: 17]
                cout << "Enter Course: "; getline(cin, s.course); [cite: 18]
                cout << "Enter GPA (0-100): "; cin >> s.gpa; [cite: 19]
                students.push_back(s);
            }
        }
        else if (choice == 4) {
            // Table Display [cite: 26]
            cout << left << setw(15) << "ID" << setw(20) << "Name" << setw(15)
                 << "Course" << setw(10) << "GPA" << "Standing" << endl;
            for (const auto& s : students) {
                cout << left << setw(15) << s.studentID << setw(20) << s.name << setw(15)
                     << s.course << setw(10) << s.gpa << getStanding(s.gpa) << endl; [cite: 31]
            }
        }
    } while (choice != 5); [cite: 39]

    return 0;
}
