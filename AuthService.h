#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "IUserRepository.h"
#include "IHasher.h"
#include "IValidator.h"
#include "User.h"
#include <memory>
#include <string>

class AuthService {
private:
    std::shared_ptr<IUserRepository> userRepository;
    std::shared_ptr<IHasher> hasher;
    std::shared_ptr<IValidator> validator;

public:
    AuthService(
        std::shared_ptr<IUserRepository> userRepository,
        std::shared_ptr<IHasher> hasher,
        std::shared_ptr<IValidator> validator
    );
    
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
};

#endif // AUTHSERVICE_H