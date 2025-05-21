#include <iostream>
#include <string>
#include "init.hpp"
#include "hash-file.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: mygit <command>\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "init") {
        initRepo();
    } else if (command == "hash-file") {
        hashFile(argc,argv);
    } 
    else {
        std::cerr << "Unknown command: " << command << "\n";
    }

    return 0;
}
