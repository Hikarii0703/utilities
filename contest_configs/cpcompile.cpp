#include <algorithm>
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"             /* Yellow */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */

void quitFromException(const std::invalid_argument &e) {
    printf("%s[ERROR]: %s%s%s\n", BOLDRED, YELLOW, e.what(), RESET);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("%sArgument missing.%s\n", BOLDRED, RESET);
        return EXIT_FAILURE;
    }

    std::string taskName = argv[1];

    if (taskName.size() > 4 && taskName.substr(taskName.size() - 4, 4) == ".cpp") {
        taskName = taskName.substr(0, taskName.size() - 4);
    }

    printf("%s[TASK: %s]%s\n", BOLDCYAN, taskName.data(), RESET);

    try {
        int ver = 17;
        if (argc == 3) ver = atoi(argv[2]);

        try {
            std::array<int, 4> versions {17, 14, 11, 98};
            if (std::none_of(versions.begin(), versions.end(), [&ver](int x) { return x == ver; })) {
                throw std::invalid_argument("C++ version is invalid.");
            }
        }
        catch (const std::invalid_argument &e) {
            quitFromException(e);
        }

        printf("%s[COMPILING IN %sC++%d%s]%s\n", BOLDMAGENTA, BOLDYELLOW, ver, BOLDMAGENTA, RESET);
        int exitcode =
            system(std::string(
                       "g++ -o " + taskName + ".exe " + taskName + ".cpp -O2 -std=c++17 " +
                       "-Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op "
                       "-Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align "
                       "-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 "
                       "-fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector "
                       "-DLOCAL_DEFINE")
                       .data());

        switch (exitcode) {
            case 0:
                break;
            case 2:
                throw std::invalid_argument("Aborted");
            default:
                throw std::invalid_argument("Compilation did not exit successfully.");
        }
    }
    catch (const std::invalid_argument &e) {
        quitFromException(e);
    }

    printf("%s[FINISHED]%s\n", BOLDGREEN, RESET);

    return EXIT_SUCCESS;
}
