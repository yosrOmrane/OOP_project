#include "AuthService.h"
#include <algorithm>

AuthService::AuthService(
    std::shared_ptr<IUserRepository> userRepository,
    std::shared_ptr<IHasher> hasher,
    std::shared_ptr<IValidator> validator
) : userRepository(userRepository), hasher(hasher), validator(validator) {}

bool AuthService::registerUser(const std::string& username, const std::string& password) {
    // Validate input
    if (!validator->isValidUsername(username) || !validator->isValidPassword(password)) {
        return false;
    }
    
    // Check if username already exists
    auto users = userRepository->loadUsers();
    auto it = std::find_if(users.begin(), users.end(), [&username](const User& user) {
        return user.getUsername() == username;
    });
    
    if (it != users.end()) {
        // Username already exists
        return false;
    }
    
    // Generate salt and hash password
    std::string salt = hasher->generateSalt();
    std::string hashedPassword = hasher->hashPassword(password, salt);
    
    // Create and save user
    User newUser(username, hashedPassword, salt);
    userRepository->saveUser(newUser);
    
    return true;
}

bool AuthService::loginUser(const std::string& username, const std::string& password) {
    // Load users
    auto users = userRepository->loadUsers();
    
    // Find user by username
    auto it = std::find_if(users.begin(), users.end(), [&username](const User& user) {
        return user.getUsername() == username;
    });
    
    if (it == users.end()) {
        // User not found
        return false;
    }
    
    // Get user data
    const User& user = *it;
    
    // Hash the provided password with the stored salt
    std::string hashedPassword = hasher->hashPassword(password, user.getSalt());
    
    // Compare hashed passwords
    return hashedPassword == user.getHashedPassword();
}