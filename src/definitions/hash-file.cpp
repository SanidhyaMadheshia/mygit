#include "hash-file.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
#include<openssl/sha.h>
#include<openssl/evp.h>

namespace fs = std::filesystem;


bool validateHashFileArgs(int argc , char* argv[])  {
    std::vector<std::string> validParams = {"-w"};
    if(argc== 3) {
            return true ;
    }else if(argc==4){
        std::string param(argv[2]);
        if(std::find(validParams.begin(),validParams.end(),param)!= validParams.end()) {
            return true ;
        }
    }
    std::cerr << "Args error"<< std::endl;
    return false;
}

bool hashFileSHA256(const std::string& filename, std::string& hashHex) {
    const int bufferSize = 4096;
    unsigned char buffer[bufferSize];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        std::cerr << "Error: Failed to create EVP_MD_CTX" << std::endl;
        return false;
    }

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        std::cerr << "Error: EVP_DigestInit_ex failed" << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    while (file.good()) {
        file.read(reinterpret_cast<char*>(buffer), bufferSize);
        std::streamsize bytesRead = file.gcount();
        if (bytesRead > 0) {
            if (EVP_DigestUpdate(ctx, buffer, bytesRead) != 1) {
                std::cerr << "Error: EVP_DigestUpdate failed" << std::endl;
                EVP_MD_CTX_free(ctx);
                return false;
            }
        }
    }

    if (EVP_DigestFinal_ex(ctx, hash, nullptr) != 1) {
        std::cerr << "Error: EVP_DigestFinal_ex failed" << std::endl;
        EVP_MD_CTX_free(ctx);
        return false;
    }

    EVP_MD_CTX_free(ctx);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    
    hashHex = oss.str();
    return true;
}

void hashFile(int argc , char* argv[]) {
    if(!validateHashFileArgs(argc,argv)) {
        std::cerr<<"Error in args"<<std::endl;
        return ;
    }
    std::string param= argv[2];
    std::string filename= argv[3];

    if(param == "-w") {
        hashFileHandler(param,filename);
    }else {
        std::cerr<<"Error in args"<<std::endl;
    }
}
void hashFileHandler(std::string param , std::string filename) {
    std::string hash;

    bool hashed = hashFileSHA256(filename,hash);
    if(hashed) {
        std::cout<<"SHA-256  hash : " <<hash<<std::endl;

    }else {
        std::cerr<<"Error in hashing";
    }

}



