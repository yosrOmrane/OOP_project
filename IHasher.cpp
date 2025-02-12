#include <string>

class IHasher
{
public:
    virtual std::string hashPassword(const std::string &password, const std::string &salt) = 0;
    virtual std::string generateSalt() = 0;
    virtual ~IHasher() = default;
};
