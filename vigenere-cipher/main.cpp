#include <iostream>
#include "vigenere.h"

int main() {
    std::cout << "Enter the keyword: ";
    std::string keyword;
    std::cin >> keyword;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the text: ";
    std::string text;
    std::getline(std::cin, text);
    std::cout << "Encrypted: " << vigenere::encrypt(keyword, text) << std::endl;
    std::cout << "Decrypted: " << vigenere::decrypt(keyword, text) << std::endl;
    return 0;
}
