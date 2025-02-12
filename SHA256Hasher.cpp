#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <random>

class SHA256Hasher : public IHasher
{
public:
    std::string generateSalt() override
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(33, 126);
        std::string salt;
        for (int i = 0; i < 16; ++i)
            salt += static_cast<char>(dist(gen));
        return salt;
    }

    std::string hashPassword(const std::string &password, const std::string &salt) override
    {
        std::string input = password + salt;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char *>(input.c_str()), input.length(), hash);

        std::ostringstream oss;
        for (unsigned char c : hash)
            oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
        return oss.str();
    }
};
