#include "init.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

// namespace fs = std::filesystem;

// void initRepo() {
//     fs::path repoPath = ".mygit";

//     if (fs::exists(repoPath)) {
//         std::cout << "Repository already exists at " << fs::absolute(repoPath) << "\n";
//         return;
//     }

//     fs::create_directory(repoPath);
//     fs::create_directory(repoPath / "objects");
//     fs::create_directory(repoPath / "refs");

//     std::ofstream(repoPath / "HEAD") << "ref: refs/heads/master\n";

//     std::cout << "Initialized empty mygit repository at " << fs::absolute(repoPath) << "\n";
// }


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