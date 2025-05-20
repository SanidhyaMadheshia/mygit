#include <iostream>
#include <string>
#include "init.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: mygit <command>\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "init") {
        initRepo();
    } else {
        std::cerr << "Unknown command: " << command << "\n";
    }

    return 0;
}
