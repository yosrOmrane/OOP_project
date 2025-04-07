#include "FileUserRepository.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

FileUserRepository::FileUserRepository(const std::string& filename) : filename(filename) {}

void FileUserRepository::saveUser(const User& user) {
    // Load existing users
    std::vector<User> users = loadUsers();
    
    // Check if user already exists
    auto it = std::find_if(users.begin(), users.end(), [&user](const User& existingUser) {
        return existingUser.getUsername() == user.getUsername();
    });
    
    // If user exists, remove it (we'll add the updated version)
    if (it != users.end()) {
        users.erase(it);
    }
    
    // Add the new/updated user
    users.push_back(user);
    
    // Write all users back to the file
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }
    
    for (const auto& u : users) {
        file << u.toCSV() << std::endl;
    }
}

std::vector<User> FileUserRepository::loadUsers() {
    std::vector<User> users;
    std::ifstream file(filename);
    
    // If file doesn't exist yet, return empty vector
    if (!file.is_open()) {
        return users;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                users.push_back(User::fromCSV(line));
            } catch (const std::exception& e) {
                // Skip invalid lines
            }
        }
    }
    
    return users;
}