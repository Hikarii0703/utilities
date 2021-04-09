#include <iostream>
#include <algorithm>
#include <filesystem>
#include <cassert>
#include <cstring>

namespace fs = std::filesystem;

std::string getTargetName(const std::string &s) {
    assert(s.size() > 0);

    std::string ret;
    for (size_t i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '/') break;
        ret += s[i];
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::cout << "fuck you\n";
        return 1;
    }

    // copy
    fs::path sourceFile = "/home/hikarii/template.cpp";
    std::string templateType = "NORMAL";

    if (argc == 2) {
        if (strcmp(argv[1], "c") == 0) {
            sourceFile = "/home/hikarii/template_cases.cpp";
            templateType = "CASES";
        }
        else if (strcmp(argv[1], "l") == 0) {
            sourceFile = "/home/hikarii/template_long.cpp";
            templateType = "LONG";
        }
    }
    fs::path targetParent = fs::current_path();
    std::string targetName = getTargetName(std::string(fs::current_path()));
    auto target = targetParent / (targetName + ".cpp");

    if (fs::exists(target)) {
        std::cout << "File already existed" << std::endl;
        std::cout << "Override? [Y/N]: ";

        std::string option;
        std::cin >> option;

        if (option != "Y" && option != "y") {
            if (option != "N" && option != "n") {
                std::cout << "Invalid option\n";
            }
            return 0;
        }
    }

    try {
        fs::create_directories(targetParent);
        fs::copy_file(sourceFile, target, fs::copy_options::overwrite_existing);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
        return 1;
    }
    
    // replace
    try {
        std::string command = std::string("sed -i \"s/\\\${FILENAME}/") + targetName + "/\" " + targetName + ".cpp";
        system(command.data());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << "[Name]: " << targetName << ".cpp\n";
    std::cout << "[Type]: " << templateType << '\n';

    return 0;
}
