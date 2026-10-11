#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int   id;
    char  name[50];
    float marks;
} Record;

Record rec[MAX];      
int    n = 0;

Record sorted[MAX];   
int    ns = 0;

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int readInt(const char *prompt) {
    int x;
    printf("%s", prompt);
    while (scanf("%d", &x) != 1) {
        printf("  Invalid input! Enter a whole number: ");
        clearBuffer();
    }
    return x;
}

float readFloat(const char *prompt) {
    float x;
    printf("%s", prompt);
    while (scanf("%f", &x) != 1) {
        printf("  Invalid input! Enter a number: ");
        clearBuffer();
    }
    return x;
}

void insertionSort(Record a[], int count) {
    for (int i = 1; i < count; i++) {
        Record key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].id > key.id) {
            a[j + 1] = a[j];          
            j--;
        }
        a[j + 1] = key;
    }
}

int isSorted(Record a[], int count) {
    for (int i = 1; i < count; i++)
        if (a[i - 1].id > a[i].id)
            return 0;
    return 1;
}

int prepareSortedCopy(void) {
    if (n == 0) {
        printf("No records to search.\n");
        return 0;
    }
    ns = n;
    for (int i = 0; i < n; i++)
        sorted[i] = rec[i];

    if (isSorted(sorted, ns)) {
        printf("[Data is already in ascending order - sorting not needed]\n");
    } else {
        insertionSort(sorted, ns);
        printf("[Binary search needs sorted data -> insertion sort applied on a copy;"
               " original input order unchanged]\n");
    }
    return 1;
}

void showRecords(Record a[], int count, const char *title) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n%s\n", title);
    printf("%-6s %-6s %-20s %-8s\n", "Index", "ID", "Name", "Marks");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++)
        printf("%-6d %-6d %-20s %-8.2f\n",
               i, a[i].id, a[i].name, a[i].marks);
}

void addRecords(void) {
    int space = MAX - n;
    if (space <= 0) {
        printf("Storage full!\n");
        return;
    }

    int count = readInt("How many records do you want to enter? ");
    while (count < 1 || count > space) {
        printf("  Enter a number between 1 and %d: ", space);
        count = readInt("");
    }

    for (int i = 1; i <= count; i++) {
        printf("\n--- Record %d of %d ---\n", i, count);
        rec[n].id = readInt("Enter ID    : ");
        printf("Enter Name  : ");
        scanf(" %49[^\n]", rec[n].name);
        rec[n].marks = readFloat("Enter Marks : ");
        n++;
    }
    printf("\n%d record(s) added (stored in input order). Total records = %d\n", count, n);
}

void loadSample(void) {
    int   ids[]   = {40, 10, 70, 20, 50, 30, 60, 30, 80};
    char *names[] = {"Dev", "Asha", "Gita", "Bala", "Esha",
                     "Chetan", "Farid", "Chetan2", "Hari"};
    float marks[] = {71, 88.5, 64, 92, 55.5, 77, 83, 69, 90};

    n = 0;
    for (int i = 0; i < 9; i++) {
        rec[n].id = ids[i];
        strcpy(rec[n].name, names[i]);
        rec[n].marks = marks[i];
        n++;
    }
    printf("9 UNSORTED sample records loaded (ID 30 is duplicated).\n");
}

int binarySearchIter(Record a[], int count, int key, int *cmp, int trace) {
    int low = 0, high = count - 1, result = -1, step = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*cmp)++;

        if (trace)
            printf("  Step %d : low=%d  high=%d  mid=%d  (ID at mid = %d)\n",
                   step, low, high, mid, a[mid].id);
        step++;

        if (a[mid].id == key) {
            result = mid;          
            high = mid - 1;
        } else if (a[mid].id < key) {
            low = mid + 1;         
        } else {
            high = mid - 1;        
        }
    }
    return result;
}

int binarySearchRec(Record a[], int low, int high, int key,
                    int *cmp, int trace, int call) {
    if (low > high) {              
        if (trace)
            printf("  Call %d : low=%d  high=%d  -> range empty\n", call, low, high);
        return -1;
    }

    int mid = low + (high - low) / 2;
    (*cmp)++;

    if (trace)
        printf("  Call %d : low=%d  high=%d  mid=%d  (ID at mid = %d)\n",
               call, low, high, mid, a[mid].id);

    if (a[mid].id == key) {
        int left = binarySearchRec(a, low, mid - 1, key, cmp, trace, call + 1);
        return (left != -1) ? left : mid;
    }
    else if (a[mid].id < key)
        return binarySearchRec(a, mid + 1, high, key, cmp, trace, call + 1);
    else
        return binarySearchRec(a, low, mid - 1, key, cmp, trace, call + 1);
}

int linearSearch(Record a[], int count, int key, int *cmp) {
    for (int i = 0; i < count; i++) {
        (*cmp)++;
        if (a[i].id == key)
            return i;
    }
    return -1;
}

void printResult(const char *label, Record a[], int idx, int cmp) {
    if (idx == -1)
        printf("%s : NOT FOUND | comparisons = %d\n", label, cmp);
    else
        printf("%s : FOUND at index %d -> ID=%d, Name=%s, Marks=%.2f | comparisons = %d\n",
               label, idx, a[idx].id, a[idx].name, a[idx].marks, cmp);
}

void sortAndShow(void) {
    if (!prepareSortedCopy()) return;
    showRecords(sorted, ns, "SORTED COPY (original input is unchanged):");
}

void searchIterative(void) {
    if (!prepareSortedCopy()) return;
    int key = readInt("Enter ID to search: ");
    int cmp = 0;

    printf("\nIterative Binary Search trace (on sorted copy):\n");
    int idx = binarySearchIter(sorted, ns, key, &cmp, 1);
    printResult("Result", sorted, idx, cmp);
    printf("(For duplicate IDs, the first occurrence is returned.)\n");
}

void searchRecursive(void) {
    if (!prepareSortedCopy()) return;
    int key = readInt("Enter ID to search: ");
    int cmp = 0;

    printf("\nRecursive Binary Search trace (on sorted copy):\n");
    int idx = binarySearchRec(sorted, 0, ns - 1, key, &cmp, 1, 1);
    printResult("Result", sorted, idx, cmp);
    printf("(For duplicate IDs, the first occurrence is returned.)\n");
}

void compareSearches(void) {
    if (!prepareSortedCopy()) return;
    int key = readInt("Enter ID to search: ");
    int c1 = 0, c2 = 0, c3 = 0;

    int i1 = binarySearchIter(sorted, ns, key, &c1, 0);
    int i2 = binarySearchRec(sorted, 0, ns - 1, key, &c2, 0, 1);
    int i3 = linearSearch(rec, n, key, &c3);        

    printf("\n--- Comparison for ID %d (n = %d records) ---\n", key, n);
    printResult("Binary (iterative) [sorted copy]", sorted, i1, c1);
    printResult("Binary (recursive) [sorted copy]", sorted, i2, c2);
    printResult("Linear search      [original   ]", rec,    i3, c3);
    printf("(Index shown is the position in the array that was searched.)\n");
}

typedef struct {
    const char *name;
    int  data[6];     
    int  count;       
    int  key;         
    int  expected;    
} TestCase;

void runTestCases(void) {
    TestCase tests[] = {
        
        {"First element",           {50, 20, 40, 10, 30},  5, 10,  0},
        {"Middle element",          {50, 20, 40, 10, 30},  5, 30,  2},
        {"Last element",            {50, 20, 40, 10, 30},  5, 50,  4},
        {"Absent key",              {50, 20, 40, 10, 30},  5, 35, -1},
        {"Single item - present",   {42},                  1, 42,  0},
        {"Single item - absent",    {42},                  1,  7, -1},
        {"Duplicates (first idx)",  {30, 10, 30, 20, 30},  5, 30,  2},
        {"Empty list",              {0},                   0,  5, -1},
        {"Even number of items",    {8, 3, 6, 1},          4,  6,  2},
        {"Reverse-sorted input",    {5, 4, 3, 2, 1},       5,  1,  0}
    };
    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("\n================ TEST SUITE ================\n");
    printf("%-3s %-24s %-5s %-8s %-8s %-8s %-6s\n",
           "No", "Test case", "Key", "Expected", "Iter", "Recur", "Result");
    printf("----------------------------------------------------------------------\n");

    for (int t = 0; t < total; t++) {
        Record a[6];
        for (int i = 0; i < tests[t].count; i++) {
            a[i].id = tests[t].data[i];
            strcpy(a[i].name, "Test");
            a[i].marks = 0;
        }

        insertionSort(a, tests[t].count);       

        int c1 = 0, c2 = 0;
        int r1 = binarySearchIter(a, tests[t].count, tests[t].key, &c1, 0);
        int r2 = binarySearchRec(a, 0, tests[t].count - 1, tests[t].key, &c2, 0, 1);

        int ok = (r1 == tests[t].expected && r2 == tests[t].expected);
        if (ok) passed++;

        printf("%-3d %-24s %-5d %-8d %-8d %-8d %-6s\n",
               t + 1, tests[t].name, tests[t].key,
               tests[t].expected, r1, r2, ok ? "PASS" : "FAIL");
    }

    printf("----------------------------------------------------------------------\n");
    printf("Passed %d / %d test cases.\n", passed, total);
}

int main(void) {
    int choice;

    do {
        printf("\n======= SMART RECORD SEARCHING SYSTEM =======\n");
        printf(" 1. Add records \n");
        printf(" 2. Display records \n");
        printf(" 3. Show sorted copy \n");
        printf(" 4. Binary search - Iterative \n");
        printf(" 5. Binary search - Recursive \n");
        printf(" 6. Compare Binary vs Linear search\n");
        printf(" 7. Load unsorted sample data\n");
        printf(" 8. Run test cases\n");
        printf(" 9. Clear all records\n");
        printf(" 0. Exit\n");
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: addRecords(); break;
            case 2: showRecords(rec, n, "ORIGINAL INPUT ORDER:"); break;
            case 3: sortAndShow();      break;
            case 4: searchIterative();  break;
            case 5: searchRecursive();  break;
            case 6: compareSearches();  break;
            case 7: loadSample();       break;
            case 8: runTestCases();     break;
            case 9: n = 0; printf("All records cleared.\n"); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
