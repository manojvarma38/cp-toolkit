# cp-toolkit

# Simple Competitive Programming Test Runner

This project provides a basic framework for compiling and testing competitive programming solutions written in C++. It automates the process of compiling a user's solution, running it against a given input, and comparing its output with an expected output.

## Overview

The `main.cpp` script orchestrates the testing process by utilizing functions from `runner.hpp` and `runner.cpp` to compile, execute, and compare the output of a user-submitted C++ solution against predefined test cases.

## Project Structure

```
├── main.cpp          (Test runner entry point)
├── runner.cpp        (Implements testing functionalities)
├── runner.hpp        (Declares functions in runner.cpp)
├── submissions/
│   └── solution.cpp  (User's solution code)
└── tests/
    ├── input.in      (Input data for the solution)
    └── expected_output.out (Expected output for the input)
├── compile_errors.txt (Compilation error log)
└── user_output.txt    (Output from the user's solution)
```

## Usage

1.  **Prepare Solution:** Place your C++ solution file in the `submissions` directory and name it `solution.cpp`.
2.  **Create Test Case:**
    * Place the input for your solution in a file named `input.in` within the `tests` directory.
    * Place the corresponding expected output in a file named `expected_output.out` within the `tests` directory.
3.  **Compile Runner:** Open your terminal in the project root and compile the test runner:
    ```bash
    g++ main.cpp runner.cpp -o test_runner -std=c++17
    ```
4.  **Run Tests:** Execute the compiled test runner:
    ```bash
    ./test_runner
    ```

## Output

The test runner will provide feedback on the testing process:

* **Compilation Status:** Indicates whether the compilation was successful or if errors occurred (check `compile_errors.txt`).
* **Execution Status:** Reports whether the solution ran successfully and the execution time, or if a runtime error occurred.
* **Comparison Result:** States whether the user's output matches the expected output. If differences are found, the first differing line will be displayed.

## Dependencies

* **g++:** GNU C++ compiler (version supporting C++17).

## Potential Enhancements

* Support for multiple test cases.
* Options for different output comparison methods (e.g., ignoring whitespace).
* Automated discovery of test files.
* More detailed reporting of output differences.
* Integration with common testing frameworks.
* Implementation of execution timeouts.


