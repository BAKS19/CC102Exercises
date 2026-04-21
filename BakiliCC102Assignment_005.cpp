#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ofstream out("original.txt");
    if (!out) return 1;
    out << "One\nTwo\nThree\nFour\nFive\nSix";
    out.close();

    std::ifstream in("original.txt");
    if (!in) return 1;

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    std::sort(lines.begin(), lines.end());

    std::ofstream outSorted("sorted.txt");
    if (!outSorted) return 1;
    for (const auto& s : lines) {
        outSorted << s << "\n";
    }
    outSorted.close();

    return 0;
}
