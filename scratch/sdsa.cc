#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

//SHA-256ハッシュを計算し、メッセージとハッシュ値を出力する

int main() {
    CryptoPP::SHA256 hash;
    std::string message = "Hello, Crypto++!";
    std::string digest;

    CryptoPP::StringSource(message, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest),
                false
            )
        )
    );

    std::cout << "Message: " << message << std::endl;
    std::cout << "SHA-256 Digest: " << digest << std::endl;

    return 0;
}