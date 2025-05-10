#ifndef FILEUSERREPOSITORY_H
#define FILEUSERREPOSITORY_H

#include "IUserRepository.h"
#include "User.h"
#include <string>
#include <vector>

class FileUserRepository : public IUserRepository {
private:
    std::string filename;

public:
    explicit FileUserRepository(const std::string& filename);
    void saveUser(const User& user) override;
    std::vector<User> loadUsers() override;
};

#endif // FILEUSERREPOSITORY_H