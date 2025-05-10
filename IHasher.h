#ifndef IHASHER_H
#define IHASHER_H

#include <string>

class IHasher {
public:
    virtual ~IHasher() = default;
    virtual std::string hashPassword(const std::string& password, const std::string& salt) = 0;
    virtual std::string generateSalt() = 0;
};

#endif // IHASHER_H