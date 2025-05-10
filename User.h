#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string hashedPassword;
    std::string salt;

public:
    User(const std::string& username, const std::string& hashedPassword, const std::string& salt);
    
    // Getters
    std::string getUsername() const;
    std::string getHashedPassword() const;
    std::string getSalt() const;
    
    // For CSV serialization
    std::string toCSV() const;
    static User fromCSV(const std::string& csvLine);
};

#endif // USER_H