# 📚 Library Management System – C++ Console Application

A fully functional **Library Management System** built in C++.  
This program allows users to manage books, issue and recall books, search inventory, and automatically save/load data using file handling.  
It demonstrates arrays, string processing, file I/O, formatted tables, loops, conditions, and modular programming through functions.

---

## 🚀 Features

### ✔ Check Inventory
Displays all books in a clean table with:
- Inventory number  
- Book name  
- Author  
- Status (Available / Issued)  

### ✔ Search Books
Search by:
1. **Book Name**  
2. **Author Name**

Supports:
- Keyword matching  
- Case-insensitive comparison  
- Multiple results  

### ✔ Add New Book
Allows adding:
- Book name  
- Author name  
- Automatically sets status to **Available**  
- Automatically assigns inventory number  

### ✔ Issue a Book
- Search for the book  
- Select by inventory number  
- Updates status to **issued**  
- Rejects issuing an already-issued book  

### ✔ Recall a Book
- Displays issued books matching the keyword  
- Updates status back to **available**  

### ✔ Auto Save & Load Data
The system automatically:
- Saves all book records to `library_data.txt`  
- Loads data on startup  
This ensures no data is lost between program runs.

### ✔ Clean Console & Delays
Uses:
- `clearScreen()` to clear terminal  
- `sleepForSeconds()` to pause output for readability  

---

## 🛠 Technologies Used

- **C++**  
- Arrays (up to 10,000 entries)  
- String manipulation  
- File Handling (`ifstream`, `ofstream`)  
- `iomanip` for formatted output  
- `sstream` for input validation  
- Console utilities (`system("cls")`, `system("clear")`)  
- Delays using `<chrono>` and `<thread>`  

---

## 📦 How to Run

1. Save the code as `code.cpp`  
2. Compile using:  g++ code.cpp -o library
3. Run the program: ./library
The program will automatically create and update.
