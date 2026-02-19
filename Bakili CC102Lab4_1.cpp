
        
        // Create 2D array
        double scores[numStudents][numQuizzes];
        double averages[numStudents] = {0};
        #include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;
    
    //Hi Sir ;) 
    do {
        int numStudents, numQuizzes;
        
        // Get number of students and quizzes
        cout << "Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;

        // Input scores for each student
        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << (i + 1) << " scores: ";
            for (int j = 0; j < numQuizzes; j++) {
                cin >> scores[i][j];
                averages[i] += scores[i][j];
            }
            averages[i] /= numQuizzes; // Calculate average
        }
        
        // Display table header
        cout << "\nStudent\t";
        for (int q = 1; q <= numQuizzes; q++) {
            cout << "Q" << q << "\t";
        }
        cout << "Average" << endl;
        
        // Display the separator line
        cout << "------------------------------------------------" << endl;
        
        // Display all scores and averages
        cout << fixed << setprecision(2);
        for (int i = 0; i < numStudents; i++) {
            cout << (i + 1) << "\t";
            for (int j = 0; j < numQuizzes; j++) {
                cout << scores[i][j] << "\t";
            }
            cout << averages[i] << endl;
        }
        
        // Ask to run again
        cout << "\nWould you like to try again? (y/n): ";
        cin >> choice;
        cout << endl;
        
    } while (again == 'y' || again == 'Y');
    
    return 0;
}