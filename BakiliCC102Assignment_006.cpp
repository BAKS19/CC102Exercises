#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int countPrimesInFile(const std::string& filename) {
    std::ifstream file(filename);
    int primeCount = 0;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 0;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        try {
            int number = std::stoi(line);
            if (isPrime(number)) {
                primeCount++;
            }
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    file.close();
    return primeCount;
}

int main() {
    std::string filename = "NUMS.TXT";
    int totalPrimes = countPrimesInFile(filename);

    std::cout << "Number of primes found: " << totalPrimes << std::endl;

    return 0;
}
