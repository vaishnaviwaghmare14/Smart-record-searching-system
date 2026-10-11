# Smart Record Searching System 

A menu-driven C program developed as an **Analysis of Algorithms (AOA) mini project** based on the **Divide and Conquer** technique.

The system manages student records, creates a sorted copy using Insertion Sort, and performs Iterative Binary Search and Recursive Binary Search. It also compares Binary Search with Linear Search based on the number of comparisons.

## Features

- Add student records.
- Display records in their original input order.
- Create a sorted copy of records using Insertion Sort.
- Perform Iterative Binary Search.
- Perform Recursive Binary Search.
- Perform Linear Search for comparison.
- Display `low`, `high`, and `mid` during Binary Search.
- Count the number of comparisons.
- Handle duplicate student IDs.
- Return the first occurrence of duplicate IDs.
- Compare Binary Search and Linear Search.
- Load predefined unsorted sample records.
- Run 10 built-in test cases.
- Clear all student records.

## Algorithms Used

### 1. Insertion Sort

Insertion Sort arranges student records in ascending order of student ID before Binary Search is performed.

- Best Case: `O(n)`
- Average Case: `O(n²)`
- Worst Case: `O(n²)`
- Space Complexity: `O(1)` auxiliary space, excluding any separate output array.

### 2. Iterative Binary Search

Searches the sorted records by repeatedly dividing the search interval into two halves using a loop.

- Best Case: `O(1)`
- Average Case: `O(log n)`
- Worst Case: `O(log n)`
- Space Complexity: `O(1)`

### 3. Recursive Binary Search

Uses recursive function calls to reduce the search interval by half until the student ID is found or the search interval becomes empty.

- Best Case: `O(1)`
- Average Case: `O(log n)`
- Worst Case: `O(log n)`
- Space Complexity: `O(log n)` due to the recursion stack.

### 4. Linear Search

Checks student records one by one until the required student ID is found or all records have been checked.

- Best Case: `O(1)`
- Average Case: `O(n)`
- Worst Case: `O(n)`
- Space Complexity: `O(1)`

## Duplicate Records

The program supports duplicate student IDs. When multiple records have the same ID, the search algorithms return the **first occurrence in the sorted records**.

Example:

```text
ID = 30

30  Chetan
30  Chetan2
```

The search returns the first matching record according to the program's sorting and duplicate-handling logic.

## Team

| Sr. No. | Team Member 
|---|---|---|
| 1 | Vaishnavi Waghmare |
| 2 | [Team Member 2] | 
| 3 | [Team Member 3] | 
| 4 | [Team Member 4] | 

## Technologies Used

- **Programming Language:** C
- **Core Concepts:** Arrays, Structures, Functions, Loops, Recursion, and Conditional Statements
- **Algorithms:** Insertion Sort, Iterative Binary Search, Recursive Binary Search, and Linear Search
- **Development Environment:** GCC / Code::Blocks / VS Code

## How to Run

### Prerequisites

Install a C compiler such as GCC or MinGW.

### Steps

1. Clone or download this repository.
2. Open the project folder in a terminal.
3. Compile the C source file:

   ```bash
   gcc main.c -o smart_record_search
   ```

4. Run the program.

   **Windows:**

   ```bash
   .\smart_record_search.exe
   ```

   **Linux / macOS:**

   ```bash
   ./smart_record_search
   ```

Replace `main.c` with the actual source filename if it is different.



