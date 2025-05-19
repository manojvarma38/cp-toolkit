// runner.cpp
#include "runner.hpp"
#include <iostream>
#include <chrono>
#include <cstdlib> // system()
#include <fstream> // ifstream
#include <string>

bool compileSolution(const std::string &sourceFile, const std::string &outputBinary)
{
    std::string command = "g++ " + sourceFile + " -o " + outputBinary + " -std=c++17 -O2 2> compile_errors.txt";
    int result = system(command.c_str());
    return result == 0;
}

bool runSolution(const std::string &execFile, const std::string &inputFile, const std::string &userOutputFile, double &execTime)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::string command = execFile + ".exe < " + inputFile + " > " + userOutputFile;
    int result = system(command.c_str());

    auto end = std::chrono::high_resolution_clock::now();
    execTime = std::chrono::duration<double>(end - start).count();

    return result == 0;
}

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}

bool compareFiles(const std::string &expectedFile, const std::string &userFile)
{
    std::ifstream expected(expectedFile);
    std::ifstream user(userFile);

    if (!expected.is_open() || !user.is_open())
    {
        std::cerr << "Error: Could not open files for comparison.\n";
        return false;
    }

    std::string expectedLine, userLine;
    int lineNum = 1;
    bool allMatch = true;

    while (true)
    {
        bool expEOF = !std::getline(expected, expectedLine);
        bool userEOF = !std::getline(user, userLine);

        if (expEOF && userEOF)
            break;

        if (expEOF != userEOF || expectedLine != userLine)
        {
            std::cout << "Difference at line " << lineNum << ":\n";
            std::cout << "Expected: \"" << expectedLine << "\"\n";
            std::cout << "Your output: \"" << userLine << "\"\n";
            allMatch = false;
        }

        lineNum++;
    }

    if (allMatch)
    {
        std::cout << "Output matches exactly.\n";
    }
    else
    {
        std::cout << "Output differs.\n";
    }
    return allMatch;
}