#include "User.h"
#include <sstream>
#include <vector>

User::User(const std::string& username, const std::string& hashedPassword, const std::string& salt)
    : username(username), hashedPassword(hashedPassword), salt(salt) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getHashedPassword() const {
    return hashedPassword;
}

std::string User::getSalt() const {
    return salt;
}

std::string User::toCSV() const {
    return username + "," + hashedPassword + "," + salt;
}

User User::fromCSV(const std::string& csvLine) {
    std::vector<std::string> parts;
    std::stringstream ss(csvLine);
    std::string part;
    
    while (std::getline(ss, part, ',')) {
        parts.push_back(part);
    }
    
    if (parts.size() != 3) {
        throw std::runtime_error("Invalid CSV format for User");
    }
    
    return User(parts[0], parts[1], parts[2]);
}