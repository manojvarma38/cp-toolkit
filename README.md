# cp-toolkit

## Simple Competitive Programming Test Runner

A minimal framework for compiling and testing C++ competitive programming solutions. It automates compilation, execution, and output comparison against test cases.

## 📁 Project Structure

```
cp-toolkit/
├── main.cpp               # Entry point for test runner
├── runner.cpp             # Implementation of test logic
├── runner.hpp             # Header file
├── submissions/
│   ├── solution.cpp       # Your solution
│   └── user_output.txt    # Output generated
├── tests/
│   ├── input.in           # Input test case
│   └── expected_output.out # Expected output
├── compile_errors.txt     # Compilation errors, if any
```

## 🚀 Usage

1. **Add Your Code:**
   - Place your C++ code in `submissions/solution.cpp`

2. **Add Test Case:**
   - Add input in `tests/input.in`
   - Add expected output in `tests/expected_output.out`

3. **Compile:**
   ```bash
   g++ main.cpp runner.cpp -o test_runner -std=c++17
   ```

4. **Run:**
   ```bash
   ./test_runner
   ```

## 🧾 Output

- ✅ Compilation success or errors (in `compile_errors.txt`)
- ⏱️ Execution time or runtime failure
- 📋 Output comparison with line-by-line mismatches (if any)

## ⚙️ Requirements

- g++ (C++17 or later)
- Linux/Mac or WSL for Windows users

## 🔧 Optional Ideas

- Stress testing
- Add support for time/memory limits

---

