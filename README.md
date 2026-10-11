# Smart Record Searching System using Binary Search

A menu-driven C program developed as an **Analysis of Algorithms (AOA) mini project** based on the **Divide and Conquer** technique.

The system stores student records, creates a sorted copy of the records, and performs **Iterative Binary Search** and **Recursive Binary Search**. It also compares Binary Search with Linear Search.

---

## Features

- Add student records
- Display records in original input order
- Create a sorted copy of records using Insertion Sort
- Iterative Binary Search
- Recursive Binary Search
- Linear Search
- Display `low`, `high`, and `mid` during Binary Search
- Count the number of comparisons
- Handle duplicate IDs
- Return the first occurrence of duplicate IDs
- Compare Binary Search with Linear Search
- Load predefined unsorted sample records
- Run 10 built-in test cases
- Clear all records

---

## Algorithms Used

### Insertion Sort

Used to sort the records by student ID before performing Binary Search.

- Best Case: `O(n)`
- Average Case: `O(n²)`
- Worst Case: `O(n²)`

### Iterative Binary Search

Searches the sorted records by repeatedly reducing the search interval by half.

- Best Case: `O(1)`
- Average Case: `O(log n)`
- Worst Case: `O(log n)`
- Space Complexity: `O(1)`

### Recursive Binary Search

Uses recursion to divide the search interval into smaller halves.

- Best Case: `O(1)`
- Average Case: `O(log n)`
- Worst Case: `O(log n)`
- Space Complexity: `O(log n)`

### Linear Search

Searches records sequentially from the beginning until the required ID is found.

- Best Case: `O(1)`
- Average Case: `O(n)`
- Worst Case: `O(n)`

---

## Duplicate Records

The program supports duplicate student IDs.

When duplicate IDs are present, the **first occurrence** is returned.

Example:

```text
ID = 30

30  Chetan
30  Chetan2
