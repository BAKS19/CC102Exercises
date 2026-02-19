#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;
    
    do {
        const int NUM_PRODUCTS = 5;
        const int NUM_SALESPEOPLE = 4;
        
        // Initialize sales array to 0
        double sales[NUM_PRODUCTS][NUM_SALESPEOPLE] = {0};
        int salesperson, product;
        double amount;
        
        cout << "\n--- Enter Sales Data (Enter 0 for salesperson to stop) ---\n";
        
        // Input loop
        while (true) {
            cout << "\nSalesperson: ";
            cin >> salesperson;
            
            // Stop condition
            if (salesperson == 0) break;
            
            // Validate salesperson number
            if (salesperson < 1 || salesperson > NUM_SALESPEOPLE) {
                cout << "Invalid salesperson number! Enter 1-4." << endl;
                continue;
            }
            
            cout << "Product: ";
            cin >> product;
            
            // Validate product number
            if (product < 1 || product > NUM_PRODUCTS) {
                cout << "Invalid product number! Enter 1-5." << endl;
                continue;
            }
            
            cout << "Amount: ";
            cin >> amount;
            
            // Accumulate sales: sales[product-1][salesperson-1]
            sales[product - 1][salesperson - 1] += amount;
        }
        
        // Calculate totals
        double rowTotals[NUM_PRODUCTS] = {0};      // Total per product
        double colTotals[NUM_SALESPEOPLE] = {0};   // Total per salesperson
        double grandTotal = 0;
        
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            for (int j = 0; j < NUM_SALESPEOPLE; j++) {
                rowTotals[i] += sales[i][j];
                colTotals[j] += sales[i][j];
                grandTotal += sales[i][j];
            }
        }
        
        // Display table
        cout << "\n\t\t\tSalesperson" << endl;
        cout << "Product\t\t1\t\t2\t\t3\t\t4\t\tTotal" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        
        cout << fixed << setprecision(2);
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            cout << (i + 1) << "\t\t";
            for (int j = 0; j < NUM_SALESPEOPLE; j++) {
                cout << sales[i][j] << "\t\t";
            }
            cout << rowTotals[i] << endl;
        }
        
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Total\t\t";
        for (int j = 0; j < NUM_SALESPEOPLE; j++) {
            cout << colTotals[j] << "\t\t";
        }
        cout << grandTotal << endl;
        
        // Ask to run again
        cout << "\nWould you like to Try again? (y/n): ";
        cin >> choice;
        
    } while (again == 'y' || again == 'Y');
    
    return 0;
}