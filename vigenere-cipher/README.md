# Vigenere Cipher

Implementation of the vigenere cipher and my attempt to crack it using frequency analysis.

## Tests

### Simple Encryption

```
Vigenere Cipher
1. Encrypt a string
2. Decrypt a string
3. Retrieve the key of a ciphertext (with strings)
4. Retrieve the key of a ciphertext (with files)

Option: 1
Enter a keyword: bacon
Enter some text: Meet me at the park at eleven am
Encrypted: Negh zf av huf pcfx bt gzrwep oz

Process finished with exit code 0
```

### Simple Decryption

```
Vigenere Cipher
1. Encrypt a string
2. Decrypt a string
3. Retrieve the key of a ciphertext (with strings)
4. Retrieve the key of a ciphertext (with files)

Option: 2
Enter a keyword: bacon
Enter some text: Negh zf av huf pcfx bt gzrwep oz
Decrypted: Meet me at the park at eleven am

Process finished with exit code 0
```

### Cracking the Cipher with Ciphertext in a String

```
Vigenere Cipher
1. Encrypt a string
2. Decrypt a string
3. Retrieve the key of a ciphertext (with strings)
4. Retrieve the key of a ciphertext (with files)

Option: 3
Enter a keyword: qwertyuiop
Extracting contents of plaintext.txt into a string...
Encrypting plaintext using the entered keyword...
Retrieving the keyword from the ciphertext...
Retrieved keyword: qwertyuiop
Decrypting the ciphertext using the retrieved keyword...
Outputting the decrypted text into decrypted.txt...

Process finished with exit code 0
```

### Cracking the Cipher with Ciphertext in a File

```
Vigenere Cipher
1. Encrypt a string
2. Decrypt a string
3. Retrieve the key of a ciphertext (with strings)
4. Retrieve the key of a ciphertext (with files)

Option: 4
Enter a keyword: qwertyuiop
Encrypting plaintext.txt to ciphertext.txt using the entered keyword...
Retrieving the keyword from ciphertext.txt...
Retrieved keyword: qwertyuiop
Decrypting ciphertext.txt to decrypted.txt using the retrieved keyword...

Process finished with exit code 0
```
