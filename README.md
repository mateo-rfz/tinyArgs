# TinyArgs
**A lightweight C++ library for parsing command-line arguments**

## Features
- Supports **short flags** (`-f`) and **long flags** (`--flag`)
- Stores the **main run argument** (`runArg`)
- Auto-generates **help messages**
- **Minimal and lightweight** implementation with no dependencies

---

## Installation & Usage

### 1. Build & Compile
```sh
g++ -o my_program main.cpp tinyArgs.cpp
```

### 2. Example Usage
```cpp
#include "tinyArgs.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    if (args.getShortFlag("-h", "Show help message")) {
        std::cout << args.help();
        return 0;
    }

    std::string filename = args.getShortFlagValue("-f", "Input file name");
    if (!filename.empty()) {
        std::cout << "Reading from file: " << filename << std::endl;
    }

    return 0;
}
```

### 3. Running the Program
```sh
./my_program -h
```
Output:
```
-h -> Show help message
-f -> Input file name
```

---

## API Documentation

### `TinyArgs(int argc, char** argv)`
**Description:** Constructor that processes command-line arguments.

### `std::string getShortFlagValue(std::string flag, std::string help)`
**Description:** Returns the value of a short flag (`-f`).

### `bool getShortFlag(std::string flag, std::string help)`
**Description:** Checks if a short flag (`-h`) is set.

### `std::string getRunArgs()`
**Description:** Returns the first non-flag argument (main program parameter).

### `std::string help()`
**Description:** Returns a help message listing all flags and descriptions.

---

## Contribution
Feel free to submit a pull request if you have suggestions for improving TinyArgs!

## License
TinyArgs is released under the **GNU General Public License v3.0 (GPL-3.0)**.
See [LICENSE](./LICENSE) for more details.

