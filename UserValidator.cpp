#include "UserValidator.h"
#include <regex>

bool UserValidator::isValidUsername(const std::string& username) {
    // Username must be at least 3 characters long and contain only alphanumeric characters
    if (username.length() < 3) {
        return false;
    }
    
    std::regex pattern("^[a-zA-Z0-9_]+$");
    return std::regex_match(username, pattern);
}

bool UserValidator::isValidPassword(const std::string& password) {
    // Password must be at least 8 characters long
    // and contain at least one uppercase letter, one lowercase letter, and one digit
    if (password.length() < 8) {
        return false;
    }
    
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    
    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
    }
    
    return hasUpper && hasLower && hasDigit;
}