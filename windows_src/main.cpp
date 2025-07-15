// combined_custom.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>   // std::srand, std::rand
#include <ctime>     // std::time

int main() {
    // Seed once at program start (e.g. 2025-07-14T22:27:52)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Define counts and ranges
    const int invCount   = 3,  invMin   = 1,  invMax   = 10;  // Inventory: 1–10
    const int pegCount   = 15, pegMin   = 1,  pegMax   = 45;  // Peggle Level: 1–45
    const int bossCount  = 1,  bossMin  = 50, bossMax  = 55;  // Boss Level: 50–55

    // Second-digit ranges (1–10) only for Peggle and Boss
    const int secondMin  = 1,  secondMax = 10;

    std::ofstream file("preset.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open preset.txt for writing\n";
        return 1;
    }

    // 1) Inventory block (single value)
    for (int i = 1; i <= invCount; ++i) {
        int numInv = (std::rand() % (invMax - invMin + 1)) + invMin;
        file << i << ". Inventory: " << numInv << "\n";
    }
    file << "\n";

    // 2) Peggle Level block (two values: main + second digit)
    for (int i = 1; i <= pegCount; ++i) {
        int numPeg1 = (std::rand() % (pegMax - pegMin + 1)) + pegMin;
        int numPeg2 = (std::rand() % (secondMax - secondMin + 1)) + secondMin;
        file << i << ". Peggle Level: " 
             << numPeg1 << " " << numPeg2 << "\n";
    }
    file << "\n";

    // 3) Boss Level block (two values: main + second digit)
    for (int i = 1; i <= bossCount; ++i) {
        int numBoss1 = (std::rand() % (bossMax - bossMin + 1)) + bossMin;
        int numBoss2 = (std::rand() % (secondMax - secondMin + 1)) + secondMin;
        file << i << ". Boss Level: " 
             << numBoss1 << " " << numBoss2 << "\n";
    }

    file.close();

    std::cout << "Generated preset.txt with "
              << invCount   << " Inventory, "
              << pegCount   << " Peggle Levels, and "
              << bossCount  << " Boss Level.\n";
    return 0;
}