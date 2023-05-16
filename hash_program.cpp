#include <iostream>
#include <string>
#include <iomanip>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <md5.h>
#include <sha3.h>
#include <sha.h>
#include <shake.h>
#include <filter.h>
#include <files.h>
#include "hex.h"

using namespace std;

string md5(const string& message) {
    CryptoPP::Weak::MD5 hash;
    string digest;
    digest.resize(hash.DigestSize());
    hash.Update((const CryptoPP::byte*)&message[0], message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha224(const string& message) {
    CryptoPP::SHA224 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha256(const string& message) {
    CryptoPP::SHA256 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha384(const string& message) {
    CryptoPP::SHA384 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha512(const string& message) {
    CryptoPP::SHA512 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha3_224(const string& message) {
    CryptoPP::SHA3_224 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha3_256(const string& message) {
    CryptoPP::SHA3_256 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha3_384(const string& message) {
    CryptoPP::SHA3_384 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string sha3_512(const string& message) {
    CryptoPP::SHA3_512 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string shake128(const string& message) {
    CryptoPP::SHAKE128 hash;
    string digest;
    digest.resize(32);  // Set desired digest size

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

string shake256(const string& message) {
    CryptoPP::SHAKE256 hash;
    string digest;
    digest.resize(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)message.data(), message.size());
    hash.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}

int main() {
    string message;
    // cout << "Enter you message: ";
    getline(cin, message);

    int option;
    // cout << "Choose the algorithm: " << endl;
    // cout << "1. MD5" << endl;
    // cout << "2. SHA224" << endl;
    // cout << "3. SHA256" << endl;
    // cout << "4. SHA384" << endl;
    // cout << "5. SHA512" << endl;
    // cout << "6. SHA3-224" << endl;
    // cout << "7. SHA3-256" << endl;
    // cout << "8. SHA3-384" << endl;
    // cout << "9. SHA3-512" << endl;
    // cout << "10. SHAKE128" << endl;
    // cout << "11. SHAKE256" << endl;
    // cout << "Choose: ";
    cin >> option;
    string algorithm;
    string digest;
    switch (option) {
        case 1:
            digest = md5(message);
            algorithm = "md5";
            break;
        case 2:
            digest = sha224(message);
            algorithm = "sha224";
            break;
        case 3:
            digest = sha256(message);
            algorithm = "sha256";
            break;
        case 4:
            digest = sha384(message);
            algorithm = "sha384";
            break;
        case 5:
            digest = sha512(message);
            algorithm = "sha512";
            break;
        case 6:
            digest = sha3_224(message);
            algorithm = "sha3_224";
            break;
        case 7:
            digest = sha3_256(message);
            algorithm = "sha3_256";
            break;
        case 8:
            digest = sha3_384(message);
            algorithm = "sha3_384";
            break;
        case 9:
            digest = sha3_512(message);
            algorithm = "sha3_512";
            break;
        case 10:
            digest = shake128(message);
            algorithm = "shake128";
            break;
        case 11:
            digest = shake256(message);
            algorithm = "shake256";
            break;
        default:
            cout << "Option invalid!" << endl;
            return 1;
    }
    CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
    std::cout << "Message: " << message << endl;
    std::cout << "Hash result for " + algorithm + ": ";
    CryptoPP::StringSource(digest, true, new CryptoPP::Redirector(encoder));
    std::cout << std::endl;

    return 0;
}