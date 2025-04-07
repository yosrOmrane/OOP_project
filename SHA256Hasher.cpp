#include "SHA256Hasher.h"
#include <iomanip>
#include <sstream>
#include <random>
#include <ctime>

// Simple SHA-256 implementation for educational purposes
// In a real application, use a cryptographic library like OpenSSL
std::string SHA256Hasher::sha256(const std::string &input)
{
    // This is a simplified version for educational purposes
    // In a real application, use a proper cryptographic library

    // Create a hash using a simple algorithm (not secure, just for demonstration)
    std::hash<std::string> hasher;
    size_t hash = hasher(input);

    // Convert to hex string
    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << hash;

    // Pad to make it look like SHA-256 (64 chars)
    std::string result = ss.str();
    while (result.length() < 64)
    {
        result += result;
    }

    return result.substr(0, 64);
}

std::string SHA256Hasher::hashPassword(const std::string &password, const std::string &salt)
{
    return sha256(password + salt);
}

std::string SHA256Hasher::generateSalt()
{
    // Initialize random engine with time-based seed
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, 15);

    // Generate a random 16-character hexadecimal string
    const char *hex_chars = "0123456789abcdef";
    std::string salt;

    for (int i = 0; i < 16; ++i)
    {
        salt += hex_chars[dist(rng)];
    }

    return salt;
}