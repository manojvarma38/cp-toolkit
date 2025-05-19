// RUNNER_HPP
#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <string>

bool compileSolution(const std::string &sourceFile, const std::string &outputBinary);

bool runSolution(const std::string &execFile, const std::string &inputFile, const std::string &userOutputFile, double &execTime);

bool fileExists(const std::string &filename);

bool compareFiles(const std::string &expectedFile, const std::string &userFile);

#endif