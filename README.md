# Smart Record Searching System using Binary Search

## Overview

The Smart Record Searching System is an AOA mini-project based on the
Divide and Conquer technique.

The system stores records, sorts them when required, and demonstrates
Iterative Binary Search, Recursive Binary Search, and Linear Search.

## Features

- Add records in unsorted order
- Display original records
- Create and display a sorted copy
- Iterative Binary Search
- Recursive Binary Search
- Linear Search
- Display `low`, `high`, and `mid` during Binary Search
- Count comparisons
- Handle duplicate records
- Compare Binary Search with Linear Search
- Built-in test cases

## Algorithms Used

### 1. Insertion Sort
Used to prepare a sorted copy of the records before applying Binary Search.

**Time Complexity:** O(n²)

### 2. Iterative Binary Search
Searches for a record by repeatedly dividing the search interval into two halves.

**Time Complexity:** O(log n)

### 3. Recursive Binary Search
Uses recursion to divide the search interval into smaller halves.

**Time Complexity:** O(log n)

### 4. Linear Search
Checks records sequentially until the required record is found.

**Time Complexity:** O(n)

## Technologies Used

- C
- GCC Compiler
- Git
- GitHub

## Project Structure

```text
Smart-record-searching-system/
│
├── docs/
│   ├── report.pdf
│   └── output/
│
├── src/
│   └── main.c
│
├── .gitignore
└── README.md
