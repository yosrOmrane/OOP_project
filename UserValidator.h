#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include "IValidator.h"
#include <string>

class UserValidator : public IValidator {
public:
    bool isValidUsername(const std::string& username) override;
    bool isValidPassword(const std::string& password) override;
};

#endif // USERVALIDATOR_H