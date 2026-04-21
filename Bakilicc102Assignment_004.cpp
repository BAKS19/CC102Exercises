#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("color.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create or open color.txt for writing." << std::endl;
        return 1;
    }

    outFile << "Red" << std::endl;
    outFile << "Blue" << std::endl;
    outFile << "Green" << std::endl;
    outFile << "Yellow" << std::endl;
    outFile << "Purple" << std::endl;

    outFile.close();
    std::cout << "color.txt has been generated." << std::endl;

    std::ifstream inFile("color.txt");
    std::ofstream copyFile("color_copy.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open color.txt for reading." << std::endl;
        return 1;
    }
    if (!copyFile.is_open()) {
        std::cerr << "Error: Could not create or open color_copy.txt for writing." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        copyFile << line << "\n";
    }

    inFile.close();
    copyFile.close();

    std::cout << "Successfully copied contents to color_copy.txt." << std::endl;

    return 0;
}
