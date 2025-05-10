#include "AuthService.h"
#include "FileUserRepository.h"
#include "SHA256Hasher.h"
#include "UserValidator.h"
#include <iostream>
#include <memory>

int main() {
    // Create dependencies
    auto userRepository = std::make_shared<FileUserRepository>("users.csv");
    auto hasher = std::make_shared<SHA256Hasher>();
    auto validator = std::make_shared<UserValidator>();
    
    // Create auth service
    AuthService authService(userRepository, hasher, validator);
    
    // Test registration
    std::cout << "Testing user registration:" << std::endl;
    
    // Valid registration
    bool result = authService.registerUser("testuser", "Password123");
    std::cout << "Register valid user: " << (result ? "Success" : "Failed") << std::endl;
    
    // Invalid username (too short)
    result = authService.registerUser("ab", "Password123");
    std::cout << "Register with short username: " << (result ? "Success" : "Failed") << std::endl;
    
    // Invalid password (no uppercase)
    result = authService.registerUser("newuser", "password123");
    std::cout << "Register with invalid password: " << (result ? "Success" : "Failed") << std::endl;
    
    // Duplicate username
    result = authService.registerUser("testuser", "AnotherPass123");
    std::cout << "Register duplicate username: " << (result ? "Success" : "Failed") << std::endl;
    
    // Test login
    std::cout << "\nTesting user login:" << std::endl;
    
    // Valid login
    result = authService.loginUser("testuser", "Password123");
    std::cout << "Login with correct credentials: " << (result ? "Success" : "Failed") << std::endl;
    
    // Invalid password
    result = authService.loginUser("testuser", "WrongPassword123");
    std::cout << "Login with wrong password: " << (result ? "Success" : "Failed") << std::endl;
    
    // Non-existent user
    result = authService.loginUser("nonexistent", "Password123");
    std::cout << "Login with non-existent user: " << (result ? "Success" : "Failed") << std::endl;
    
    return 0;
}