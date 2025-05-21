// hashFile.hpp
#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>

bool validateHashFileArgs(int argc, char* argv[]);

bool hashFileSHA256(const std::string& filename, std::string& hashHex);

void hashFileHandler(std::string param, std::string filename);

void hashFile(int argc, char* argv[]);
