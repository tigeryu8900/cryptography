# One-time Pad

Implementation of the one-time pad.

This project contains three functions:
```C++
namespace one_time_pad {
    std::string genKey(int length);
    std::string enc(const std::string &key, const std::string &plaintext);
    std::string dec(const std::string &key, const std::string &ciphertext);
}  // namespace one_time_pad
```

## Test Results

```$xslt
One time pad algorithm demonstration: key generation, message encryption, and message decryption.
plainText: Hello world!
decryptedText: Hello world!
Second test, read plain text from a file : plainText.txt
Write key to file : key.txt
Write cipherText to file : cipherText.txt
Write decryptedText to file : decryptedText.txt

Process finished with exit code 0
```