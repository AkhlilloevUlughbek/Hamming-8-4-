# Hamming_84

A C++ implementation of the **Hamming (8,4) error-correcting code**. This project demonstrates encoding, decoding, and error detection/correction using Hamming codes.

## 🚀 Features
- **Encoding**: Converts 4-bit data into 8-bit Hamming code.
- **Decoding**: Detects and corrects single-bit errors.
- **Error Detection**: Identifies and fixes errors during transmission.

## 📂 Project Structure
```
Hamming_84/
├── header/
│   └── hamming1.h        # Header file with function declarations
├── src/
│   └── hamming1.cpp      # Implementation of Hamming (8,4) algorithms
├── main.cpp              # Main program to run encoding/decoding
├── CMakeLists.txt        # Build configuration using CMake
└── README.md             # Project documentation
```

## ⚙️ Build Instructions
1. **Clone the repository:**
   ```bash
   git clone https://github.com/AkhlilloevUlughbek/Hamming_84.git
   cd Hamming_84
   ```

2. **Build using CMake:**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. **Run the program:**
   ```bash
   ./prog
   ```

## 🧮 Example Usage
```bash
Enter 4-bit data: 1101
Encoded Hamming code: 11010110
Received code with error (optional): 10010110
Corrected code: 11010110
Decoded data: 1101
```

## 📚 Theory Behind Hamming (8,4)
- **Hamming (8,4)** adds 4 parity bits to 4 data bits, allowing single-bit error correction and double-bit error detection.
- **Parity Bits** are placed at positions 1, 2, 4, and 8.
- The code can detect and correct single-bit errors using the syndrome calculation.


## 👤 Author
**Ulughbek Akhlilloev**  
[GitHub Profile](https://github.com/AkhlilloevUlughbek)
