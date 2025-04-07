#ifndef IVALIDATOR_H
#define IVALIDATOR_H

#include <string>

class IValidator {
public:
    virtual ~IValidator() = default;
    virtual bool isValidUsername(const std::string& username) = 0;
    virtual bool isValidPassword(const std::string& password) = 0;
};

#endif // IVALIDATOR_H