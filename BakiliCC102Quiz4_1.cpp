#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int parking[5][10] = {0};
    int choice, row, col;
    double total = 0;
    const double FEE = 12.00;

    do {
        cout << "\n===== CAR PARKING SYSTEM =====\n";
        cout << "Total Collection: P" << fixed << setprecision(2) << total << endl;
        cout << "1. View Parking Layout\n";
        cout << "2. Park a Car\n";
        cout << "3. Leave Parking\n";
        cout << "4. Reset Parking Area\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "\n   ";
            for(int i=1;i<=10;i++)
                cout << i << " ";
            cout << endl;

            for(int i=0;i<5;i++){
                cout << char('A'+i) << "  ";
                for(int j=0;j<10;j++){
                    cout << parking[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 2: {
            bool full = true;
            for(int i=0;i<5;i++)
                for(int j=0;j<10;j++)
                    if(parking[i][j]==0)
                        full = false;

            if(full){
                cout << "Parking area is fully booked! No available slot.\n";
                break;
            }

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if(row<1||row>5||col<1||col>10){
                cout << "Invalid slot selection!\n";
            }
            else if(parking[row-1][col-1]==1){
                cout << "Slot already occupied!\n";
            }
            else{
                parking[row-1][col-1] = 1;
                cout << "Car successfully parked at "
                     << char('A'+row-1) << col << endl;
            }
            break;
        }

        case 3:
            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if(row<1||row>5||col<1||col>10){
                cout << "Invalid slot selection!\n";
            }
            else if(parking[row-1][col-1]==0){
                cout << "Slot is already empty!\n";
            }
            else{
                parking[row-1][col-1] = 0;
                total += FEE;

                cout << "Car at " << char('A'+row-1) << col
                     << " has left the parking area.\n";
                cout << "Parking fee collected: P12.00\n";
                cout << "Updated Total Collection: P"
                     << fixed << setprecision(2) << total << endl;
            }
            break;

        case 4:
            for(int i=0;i<5;i++)
                for(int j=0;j<10;j++)
                    parking[i][j]=0;

            cout << "Parking area reset successfully!\n";
            break;

        case 5:
            cout << "Exiting Parking Area...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice!=5);

    return 0;
}
