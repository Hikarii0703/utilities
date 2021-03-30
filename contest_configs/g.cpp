#include <iostream>
#include <algorithm>
#include <filesystem>
#include <cassert>

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

int main() {
    // copy
    fs::path sourceFile = "/home/hikarii/template.cpp";
    fs::path targetParent = fs::current_path();
    std::string targetName = getTargetName(std::string(fs::current_path()));
    auto target = targetParent / (targetName + ".cpp");

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
        std::cerr << command << '\n';
        system(command.data());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << targetName << ".cpp is generated!\n";

    return 0;
}
