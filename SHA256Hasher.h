#ifndef SHA256HASHER_H
#define SHA256HASHER_H

#include "IHasher.h"
#include <string>

class SHA256Hasher : public IHasher {
public:
    std::string hashPassword(const std::string& password, const std::string& salt) override;
    std::string generateSalt() override;

private:
    std::string sha256(const std::string& input);
};

#endif // SHA256HASHER_H