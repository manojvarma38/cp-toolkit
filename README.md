# cp-toolkit

**cp-toolkit** is a lightweight C++ tool to automate the process of compiling, running, and verifying competitive programming solutions against test inputs and expected outputs. Perfect for quick local testing and debugging your solution files.

---

## Project Structure

cp-toolkit/
│
├── main.cpp # Entry point: orchestrates compile-run-compare steps
├── runner.cpp # Implementation of compile, run, and compare functions
├── runner.hpp # Header declarations for runner functions
│
├── submissions/ # Folder for user solutions and output files
│ ├── solution.cpp # User’s C++ solution file to be tested
│ ├── user_output.txt # Output generated after running the solution
│
├── tests/ # Folder containing test input and expected output
│ ├── input.in # Input file for the solution
│ ├── expected_output.out # Expected output file for verification
│
└── compile_errors.txt # Captures compilation errors, if any

---

## How cp-toolkit Works

**Flow Diagram:**

solution.cpp (user code)
│
▼
[Compile] → If fails → Check compile_errors.txt → Stop
│
▼
[Run] → Executes solution with input.in → Output saved as user_output.txt
│
▼
[Compare] → Compares user_output.txt vs expected_output.out
│
▼
Shows if outputs match exactly or reports differences line by line

---

## How to Use

1. **Place your solution code** inside `submissions/solution.cpp`.

2. **Prepare your test case:**
   - Input file: `tests/input.in`
   - Expected output file: `tests/expected_output.out`

3. **Build and run the toolkit:**

g++ main.cpp runner.cpp -o cp-toolkit -std=c++17 -O2
./cp-toolkit
View results:

If compilation fails, check compile_errors.txt.

If runtime errors occur, they will be displayed.

If successful, the execution time will be shown.

Output comparison results will be printed — matching lines or detailed differences.

Notes
This toolkit currently supports Windows due to .exe usage in run commands.

You can adapt the run command in runner.cpp for other OSes (Linux, macOS).

The comparison is line-by-line exact match; whitespace differences will cause mismatch.

Designed primarily for competitive programming solutions testing.
