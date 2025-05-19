// main.cpp
#include "runner.hpp"
#include <iostream>

int main()
{
    const std::string sourceFile = "submissions/solution.cpp";
    const std::string execFile = "solution_exec";
    const std::string inputFile = "tests/input.in";
    const std::string expectedOutputFile = "tests/expected_output.out";
    const std::string userOutputFile = "submissions/user_output.txt";

    if (!compileSolution(sourceFile, execFile))
    {
        std::cerr << "Compilation failed. Check compile_errors.txt\n";
        return 1;
    }

    std::cout << "Compilation successful.\n";

    double execTime;

    if (!runSolution(execFile, inputFile, userOutputFile, execTime))
    {
        std::cerr << "Runtime error occurred.\n";
        return 1;
    }

    std::cout << "Ran successfully . Time: " << execTime << " sec\n";

    compareFiles(expectedOutputFile, userOutputFile);

    return 0;
}
