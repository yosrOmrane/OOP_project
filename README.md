# OOP_project

A secure authentication system in C++ that hashes passwords with a salt using SHA-256. It supports user registration, login, and password verification. User data (username, hashed password, and salt) is stored in a CSV file for persistence.

## Features

- Secure password hashing with salt using SHA-256
- User registration with validation
- User authentication
- Persistent storage using CSV files
- Object-oriented design with interfaces and implementations

## Class Structure

- **IHasher**: Interface for password hashing and salt generation

  - **SHA256Hasher**: Implementation using SHA-256 algorithm

- **IValidator**: Interface for input validation

  - **UserValidator**: Implementation with username and password validation rules

- **User**: Data class for user information

- **IUserRepository**: Interface for user data storage

  - **FileUserRepository**: Implementation using CSV file storage

- **AuthService**: Main service that coordinates authentication operations

## Validation Rules

- Username: At least 3 characters, alphanumeric only
- Password: At least 8 characters, must contain uppercase, lowercase, and digits

## Building and Running

Compile all .cpp files together:

```bash
g++ -std=c++17 main.cpp SHA256Hasher.cpp UserValidator.cpp User.cpp FileUserRepository.cpp AuthService.cpp -o auth_system
```
