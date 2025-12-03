#include <stdio.h>

#include "utils.h"

int main(void)
{
    addStudent(101, 10, 14, "Alice", "Female");
    addStudent(101, 10, 14, "Bob", "Male");
    addStudent(102, 9, 15, "Charlie", "Male");
    addStudent(103, 10, 13, "Daisy", "Female");

    printf("\nSearching for ID 102 \n");
    searchStudent(102);

    printf("\nDeleting ID 103 \n");
    deleteStudent(103);

    printf("\nDisplay Class 10 \n");
    displayByClass(10);

    printf("\nDisplay Class 9 \n");
    displayByClass(9);

    return 0;
}
