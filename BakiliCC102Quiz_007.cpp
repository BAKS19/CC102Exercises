#include <iostream>
#include <fstream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ifstream inFile("input.txt");     // open input file
    ofstream outFile("output.txt");   // open output file

    int num;

    if (!inFile) {
        cout << "Error opening input.txt\n";
        return 1;
    }

    while (inFile >> num) {
        // Check if number is odd AND prime
        if (num % 2 != 0 && isPrime(num)) {
            outFile << num << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Odd prime numbers written to output.txt\n";
    return 0;
}
