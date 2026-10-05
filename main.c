#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10
#define MAX_DEPARTMENTS 20

// Structure for tree node
struct Node {
    char name[30];
    struct Node *children[MAX_CHILDREN];
    int childCount;
};

// Create a new node
struct Node* createNode(char name[]) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->childCount = 0;

    return newNode;
}

// Add child to a parent
void addChild(struct Node *parent, struct Node *child) {
    parent->children[parent->childCount] = child;
    parent->childCount++;
}


// ======================================================
// LEVEL ORDER TRAVERSAL WITH TRACE
// ======================================================

void levelOrder(struct Node *root) {

    struct Node *queue[MAX_DEPARTMENTS];

    int front = 0;
    int rear = 0;
    int step = 1;

    queue[rear++] = root;

    printf("\nLEVEL-ORDER TRAVERSAL TRACE\n");
    printf("------------------------------------------------------------\n");
    printf("%-6s %-20s %-20s %-20s\n",
           "Step", "Removed Node", "Children Added", "Output");
    printf("------------------------------------------------------------\n");

    char output[300] = "";

    while (front < rear) {

        struct Node *current = queue[front++];

        strcat(output, current->name);
        strcat(output, " ");

        char childrenAdded[100] = "";

        for (int i = 0; i < current->childCount; i++) {

            queue[rear++] = current->children[i];

            strcat(childrenAdded,
                   current->children[i]->name);

            if (i < current->childCount - 1)
                strcat(childrenAdded, ", ");
        }

        printf("%-6d %-20s %-20s %-20s\n",
               step,
               current->name,
               childrenAdded,
               output);

        step++;
    }

    printf("------------------------------------------------------------\n");
    printf("Final Level-order Traversal:\n");
    printf("%s\n", output);
}


// ======================================================
// LINEAR SEARCH WITH TRACE
// ======================================================

int linearSearch(char departments[][30],
                 int n,
                 char target[],
                 int *comparisons) {

    *comparisons = 0;

    printf("\nLINEAR SEARCH TRACE - %s\n", target);
    printf("-----------------------------------------------\n");
    printf("%-6s %-20s %-15s\n",
           "Step", "Element Checked", "Result");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < n; i++) {

        (*comparisons)++;

        if (strcmp(departments[i], target) == 0) {

            printf("%-6d %-20s %-15s\n",
                   *comparisons,
                   departments[i],
                   "FOUND");

            printf("-----------------------------------------------\n");

            return i;
        }
        else {

            printf("%-6d %-20s %-15s\n",
                   *comparisons,
                   departments[i],
                   "Not Found");
        }
    }

    printf("-----------------------------------------------\n");

    return -1;
}


// ======================================================
// BINARY SEARCH WITH TRACE
// ======================================================

int binarySearch(char departments[][30],
                 int n,
                 char target[],
                 int *comparisons) {

    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    printf("\nBINARY SEARCH TRACE - %s\n", target);
    printf("------------------------------------------------------------\n");
    printf("%-6s %-6s %-6s %-6s %-20s %-20s\n",
           "Step", "Low", "High", "Mid",
           "Element", "Decision");
    printf("------------------------------------------------------------\n");

    while (low <= high) {

        int mid = (low + high) / 2;

        (*comparisons)++;

        int result = strcmp(departments[mid], target);

        if (result == 0) {

            printf("%-6d %-6d %-6d %-6d %-20s %-20s\n",
                   *comparisons,
                   low,
                   high,
                   mid,
                   departments[mid],
                   "FOUND");

            printf("------------------------------------------------------------\n");

            return mid;
        }

        else if (result < 0) {

            printf("%-6d %-6d %-6d %-6d %-20s %-20s\n",
                   *comparisons,
                   low,
                   high,
                   mid,
                   departments[mid],
                   "Search Right");

            low = mid + 1;
        }

        else {

            printf("%-6d %-6d %-6d %-6d %-20s %-20s\n",
                   *comparisons,
                   low,
                   high,
                   mid,
                   departments[mid],
                   "Search Left");

            high = mid - 1;
        }
    }

    printf("------------------------------------------------------------\n");

    return -1;
}


// ======================================================
// MAIN FUNCTION
// ======================================================

int main() {

    // ==================================================
    // PART A - TREE CONSTRUCTION
    // ==================================================

    struct Node *CEO = createNode("CEO");

    struct Node *HR = createNode("HR");
    struct Node *Finance = createNode("Finance");
    struct Node *IT = createNode("IT");

    struct Node *Development = createNode("Development");
    struct Node *Testing = createNode("Testing");

    struct Node *Frontend = createNode("Frontend");
    struct Node *Backend = createNode("Backend");


    // Construct hierarchy

    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    addChild(IT, Development);
    addChild(IT, Testing);

    addChild(Development, Frontend);
    addChild(Development, Backend);


    printf("============================================\n");
    printf("       ORGANIZATIONAL HIERARCHY\n");
    printf("============================================\n");

    printf("\nHierarchy:\n");
    printf("CEO\n");
    printf("|-- HR\n");
    printf("|-- Finance\n");
    printf("|-- IT\n");
    printf("    |-- Development\n");
    printf("        |-- Frontend\n");
    printf("        |-- Backend\n");
    printf("    |-- Testing\n");


    // Level-order traversal
    levelOrder(CEO);


    // ==================================================
    // PART B - SEARCHING
    // ==================================================

    // Sorted array required for Binary Search

    char departments[][30] = {
        "Backend",
        "CEO",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    int n = 8;

    int linearComparisons;
    int binaryComparisons;


    // ==================================================
    // SEARCH 1 - IT
    // ==================================================

    printf("\n\n============================================\n");
    printf("SEARCH 1: IT\n");
    printf("============================================\n");

    linearSearch(departments, n, "IT",
                 &linearComparisons);

    binarySearch(departments, n, "IT",
                 &binaryComparisons);

    printf("\nComparison Summary:\n");
    printf("Linear Search : %d comparisons\n",
           linearComparisons);

    printf("Binary Search : %d comparisons\n",
           binaryComparisons);


    // ==================================================
    // SEARCH 2 - FRONTEND
    // ==================================================

    printf("\n\n============================================\n");
    printf("SEARCH 2: Frontend\n");
    printf("============================================\n");

    linearSearch(departments, n, "Frontend",
                 &linearComparisons);

    binarySearch(departments, n, "Frontend",
                 &binaryComparisons);

    printf("\nComparison Summary:\n");
    printf("Linear Search : %d comparisons\n",
           linearComparisons);

    printf("Binary Search : %d comparisons\n",
           binaryComparisons);


    // ==================================================
    // SEARCH 3 - TESTING
    // ==================================================

    printf("\n\n============================================\n");
    printf("SEARCH 3: Testing\n");
    printf("============================================\n");

    linearSearch(departments, n, "Testing",
                 &linearComparisons);

    binarySearch(departments, n, "Testing",
                 &binaryComparisons);

    printf("\nComparison Summary:\n");
    printf("Linear Search : %d comparisons\n",
           linearComparisons);

    printf("Binary Search : %d comparisons\n",
           binaryComparisons);


    // ==================================================
    // COMPLEXITY ANALYSIS
    // ==================================================

    printf("\n\n============================================\n");
    printf("          COMPLEXITY ANALYSIS\n");
    printf("============================================\n");

    printf("Tree Construction        : O(n)\n");
    printf("Level-order Traversal     : O(n)\n");
    printf("Linear Search             : O(n)\n");
    printf("Binary Search             : O(log n)\n");

    printf("\nSpace Complexity:\n");
    printf("Tree                     : O(n)\n");
    printf("Level-order Queue        : O(n)\n");
    printf("Linear Search            : O(1)\n");
    printf("Binary Search            : O(1)\n");


    // ==================================================
    // CONCLUSION
    // ==================================================

    printf("\n\n============================================\n");
    printf("              CONCLUSION\n");
    printf("============================================\n");

    printf("The general tree is suitable for representing\n");
    printf("the organizational hierarchy.\n");

    printf("Level-order traversal displays the hierarchy\n");
    printf("level by level.\n");

    printf("Binary Search is more efficient than Linear\n");
    printf("Search when department names are sorted.\n");

    return 0;
}