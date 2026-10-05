Organizational Hierarchy and Department Searching

1. Objective

To represent a company's organizational hierarchy using a suitable
tree structure and to compare Linear Search and Binary Search for
locating department names.

2. Organizational Hierarchy

The given hierarchy is:

CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing

A general tree is used to represent the hierarchy because it clearly
represents the parent-child relationship between the departments.

3. Data Structures and Algorithms Used

 Tree
A general tree is used to construct and represent the organizational
hierarchy.

 Queue
A queue is used to perform level-order traversal of the tree.

 Linear Search
Linear Search checks department names sequentially.

 Binary Search
Binary Search is performed on the department names stored in sorted
order.

 4. Level-Order Traversal

The level-order traversal obtained from the program is:

CEO HR Finance IT Development Testing Frontend Backend

 5. Searching

The department names used for searching are:

Backend
CEO
Development
Finance
Frontend
HR
IT
Testing

Three departments were selected for comparison:

1. IT
2. Frontend
3. Testing

 6. Search Comparison

Department    Linear Search    Binary Search
IT            7 comparisons    3 comparisons
Frontend      5 comparisons    3 comparisons
Testing       8 comparisons    4 comparisons

Binary Search required fewer comparisons for all three test cases.

 7. Tree Analysis

Tree Height: 3 edges (4 levels)

The longest path is:

CEO -> IT -> Development -> Frontend

Level-order traversal visits every node once and displays the
organizational hierarchy level by level.

 8. Complexity Analysis

Tree Construction:
Time Complexity: O(n)
Space Complexity: O(n)

Level-order Traversal:
Time Complexity: O(n)
Space Complexity: O(n)

Linear Search:
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)
Space Complexity: O(1)

Binary Search:
Best Case: O(1)
Average Case: O(log n)
Worst Case: O(log n)
Space Complexity: O(1)

 9. Performance Comparison

Linear Search has a worst-case time complexity of O(n), while
Binary Search has a worst-case time complexity of O(log n).

Binary Search is more efficient when the department names are
stored in sorted order.

 10. Conclusion

The general tree is suitable for representing the organizational
hierarchy because it clearly shows the relationship between the
CEO, departments, and sub-departments.

Level-order traversal is suitable for organizational reporting
because it displays the hierarchy level by level.

For department searching, a sorted array with Binary Search is
more efficient than Linear Search because it requires fewer
comparisons and has a lower worst-case time complexity.

Therefore, the combination of a general tree for organizational
representation and a sorted array with Binary Search for department
searching is suitable for this application.

11. Files Included

main.c
output.txt
trace_table.txt
complexity_analysis.txt
comparison_table.txt
README.md