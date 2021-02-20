#include <cstring>
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

    bool runCase = false;
    if (argc >= 3 && strcmp(argv[2], "case") == 0) {
        runCase = true;
    }

    printf("%s[RUNNING: %s]%s\n", BOLDCYAN, taskName.data(), RESET);
    fflush(stdout);

    int caseID;
    try {
        std::string command = "./" + taskName + ".exe";

        if (runCase) {
            printf("%s[ENTER CASE ID]:%s ", BOLDGREEN, RESET);
            fflush(stdout);

            if (scanf("%d", &caseID) != 1) {
                throw std::invalid_argument("Invalid input.");
            }
            command += " < in" + std::to_string(caseID) + ".txt";
        }

        if (runCase) {
            printf("%s[INPUT]%s\n", BOLDRED, RESET);
            if (system(std::string("cat in" + std::to_string(caseID) + ".txt").data()) != 0) {
                throw std::invalid_argument("Input file not found.");
            }
            printf("%s[OUTPUT]%s\n", BOLDYELLOW, RESET);
        }

        int exitcode = system(command.data());

        switch (exitcode) {
            case 0:
                break;
            case 2:
                throw std::invalid_argument("Keyboard Interruption.");
            default:
                throw std::invalid_argument("Execution did not exit successfully.");
        }
    }
    catch (const std::invalid_argument &e) {
        quitFromException(e);
    }

    if (runCase) {
        printf("%s[ANSWER]%s\n", BOLDMAGENTA, RESET);
        if (system(std::string("cat ans" + std::to_string(caseID) + ".txt").data()) != 0) {
            quitFromException(std::invalid_argument("Answer file not found."));
        }
    }

    printf("%s[FINISHED]%s\n", BOLDGREEN, RESET);

    return EXIT_SUCCESS;
}

