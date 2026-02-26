#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    char again;
    
    do {
        int numStudents, numDays;
        
        
        cout << "Enter number of students: ";
        cin >> numStudents;
        
        cout << "Enter number of days: ";
        cin >> numDays;
        cout << endl;
     

        vector<vector<int>> attendance(numStudents, vector<int>(numDays));
        
       
        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << (i + 1) << " attendance: ";
            for (int j = 0; j < numDays; j++) {
                cin >> attendance[i][j];
            }
        }
        
        cout << endl;
        
       
        cout << left << setw(10) << "Student";
        for (int d = 1; d <= numDays; d++) {
            cout << setw(5) << ("D" + to_string(d));
        }
        cout << setw(8) << "Total" 
             << setw(12) << "Percentage" 
             << setw(8) << "Remarks" << endl;
        
       

        for (int i = 0; i < numStudents; i++) {
            int total = 0;
            
           
            for (int j = 0; j < numDays; j++) {
                total += attendance[i][j];
            }
            
            
            double percentage = (static_cast<double>(total) / numDays) * 100;
            
            
            string remarks = (percentage < 50) ? "DRP" : "OK";
            
           
            cout << left << setw(10) << (i + 1);
            for (int j = 0; j < numDays; j++) {
                cout << setw(5) << attendance[i][j];
            }
            cout << setw(8) << total
                 << setw(12) << fixed << setprecision(0) << percentage << "%"
                 << setw(8) << remarks << endl;
        }
        
        
        cout << "\nTry again? (y/n): ";
        cin >> choice;
        cout << endl;
        
    } while (again == 'y' || again == 'Y');
    
    cout << "Program terminated." << endl;
    
    return 0;
}