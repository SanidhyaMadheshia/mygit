#include "init.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs  = std::filesystem;

void initRepo() {
    fs::path repoPath = ".git";
    if(fs::exists(repoPath)) {
        std::cout<< "Repositotrty already exists at  "<<fs::absolute(repoPath);
        return ;

    }

    fs::create_directory(repoPath);
    fs::create_directory(repoPath/"objects");
    fs::create_directory(repoPath/"refs");
    
}