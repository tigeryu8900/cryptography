#include <iostream>
#include "vigenere.h"

int main() {
    std::cout << "Vigenere Cipher\n"
                 "1. Encrypt a string\n"
                 "2. Decrypt a string\n"
                 "3. Retrieve the key of a ciphertext (with strings)\n"
                 "4. Retrieve the key of a ciphertext (with files)\n\n"
                 "Option: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::cout << "Enter a keyword: ";
            std::string keyword;
            std::cin >> keyword;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter some text: ";
            std::string plaintext;
            std::getline(std::cin, plaintext);
            std::cout << "Encrypted: " << vigenere::encrypt(keyword, plaintext) << std::endl;
            break;
        }
        case 2: {
            std::cout << "Enter a keyword: ";
            std::string keyword;
            std::cin >> keyword;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter some text: ";
            std::string ciphertext;
            std::getline(std::cin, ciphertext);
            std::cout << "Decrypted: " << vigenere::decrypt(keyword, ciphertext) << std::endl;
            break;
        }
        case 3: {
            std::cout << "Enter a keyword: ";
            std::string keyword;
            std::cin >> keyword;
            std::ifstream inf("plaintext.txt");
            std::ofstream outf("decrypted.txt");
            std::cout << "Extracting contents of plaintext.txt into a string..." << std::endl;
            std::string plaintext((std::istreambuf_iterator<char>(inf)), std::istreambuf_iterator<char>());
            std::cout << "Encrypting plaintext using the entered keyword..." << std::endl;
            std::string ciphertext = vigenere::encrypt(keyword, plaintext);
            std::cout << "Retrieving the keyword from the ciphertext..." << std::endl;
            std::string key = vigenere::crack(ciphertext);
            std::cout << "Retrieved keyword: " << key << std::endl;
            std::cout << "Decrypting the ciphertext using the retrieved keyword..." << std::endl;
            std::string decrypted = vigenere::decrypt(key, ciphertext);
            std::cout << "Outputting the decrypted text into decrypted.txt..." << std::endl;
            outf << decrypted;
            break;
        }
        case 4: {
            std::cout << "Enter a keyword: ";
            std::string keyword;
            std::cin >> keyword;
            std::ifstream inf("plaintext.txt");
            std::ofstream outf("decrypted.txt");
            std::cout << "Encrypting plaintext.txt to ciphertext.txt using the entered keyword..." << std::endl;
            vigenere::encrypt(keyword, inf, outf);
            inf.close();
            outf.close();
            inf.open("ciphertext.txt");
            outf.open("decrypted.txt");
            std::cout << "Retrieving the keyword from ciphertext.txt..." << std::endl;
            std::string key = vigenere::crack(inf);
            std::cout << "Retrieved keyword: " << key << std::endl;
            inf.seekg(0, std::ifstream::beg);
            std::cout << "Decrypting ciphertext.txt to decrypted.txt using the retrieved keyword..." << std::endl;
            vigenere::decrypt(key, inf, outf);
            break;
        }
    }
    return 0;
}
