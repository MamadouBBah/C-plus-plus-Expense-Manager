

#  C++ Expense Tracker

A command-line expense tracking application built in C++ that allows users to record, manage, and analyze personal spending with persistent file storage.

---

##  Overview

This project is a lightweight **expense management system** designed to demonstrate core software engineering principles in C++, including object-oriented design, file persistence, and modular architecture.

The application runs in the terminal and allows users to add, edit, delete, and review expenses while maintaining data between sessions using file I/O.

---

##  Features

*  Add new expenses (description, amount, category)
* View all recorded expenses
* Edit existing expenses by index
* Delete expenses by index
*  Calculate total spending
*  Persistent storage using file I/O (load/save system)
*  Session continuity across program runs

---

##  Architecture

The project follows a modular, multi-file C++ structure:

```
ExpenseTracker/
│
├── Expense.h / Expense.cpp
│   └── Defines the Expense data model
│
├── ExpenseManager.h / ExpenseManager.cpp
│   └── Handles all business logic (CRUD operations, totals, file I/O)
│
└── main.cpp
    └── CLI interface and user interaction loop
```

### Design Approach

* **Separation of concerns**

  * Data model (Expense)
  * Logic layer (ExpenseManager)
  * Interface layer (main CLI)
* Uses STL containers (`std::vector`, `std::string`)
* Encapsulates state management inside a dedicated manager class

---

## 💾 Data Persistence

Expenses are stored in a local file using C++ file streams (`fstream`).

* Data is loaded automatically on startup
* Users are prompted to save changes before exiting
* Ensures data persists between program runs

---

## 🧪 Technical Concepts Demonstrated

* Object-Oriented Programming (classes, encapsulation)
* File I/O (reading/writing structured data)
* Dynamic data structures (`std::vector`)
* Input handling (`cin`, `getline`, buffer management)
* String parsing and formatting (`stringstream`)
* Multi-file compilation using `g++`

---

## 🚧 Challenges & Solutions

### 1. Header / Source Mismatch Errors

**Problem:** Functions declared in headers were not properly defined or linked.
**Solution:** Aligned all function declarations with implementations across `.h` and `.cpp` files.

---

### 2. Input Handling Bugs

**Problem:** Mixing `cin >>` and `getline` caused skipped inputs.
**Solution:** Implemented input buffer clearing and standardized input handling flow.

---

### 3. File Path / Persistence Issues

**Problem:** Save/load behavior was inconsistent due to relative path confusion.
**Solution:** Standardized file location relative to executable directory.

---

### 4. Compilation / Linking Errors

**Problem:** Multi-file compilation required correct inclusion order and g++ commands.
**Solution:** Debugged step-by-step compilation and ensured proper header guards and linking.

---

### 5. Menu Flow Logic Issues

**Problem:** Edge cases in CLI navigation caused unexpected behavior.
**Solution:** Refined control flow and validated user input more strictly.

---

##  Future Improvements

* CSV / JSON export and import
* Search and filter by category or keyword
* Monthly and yearly spending analytics
* Multi-currency support
* GUI version (Qt or web-based interface)
* Database integration (SQLite)

---

##  Project Status

> **Stable portfolio-ready version**

This project is complete in its current form and serves as a demonstration of foundational C++ software engineering skills.

Focus has shifted from feature expansion to **code quality, documentation, and presentation.**

---

##  Build & Run

```bash
g++ main.cpp Expense.cpp ExpenseManager.cpp -o ExpenseTracker
./ExpenseTracker
```

---

## 👨‍💻 Author

Built as part of a C++ portfolio development journey focusing on:

* Systems thinking
* OOP design
* File-based persistence
* Clean modular architecture

---
