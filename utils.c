#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

student *head = NULL;

void addStudent(int id, int classNumber, int age, char *name, char *gender)
{
    student *s = malloc(sizeof(student));
    if (!s)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    s->id = id;
    s->classNumber = classNumber;
    s->age = age;
    strcpy(s->name, name);
    strcpy(s->gender, gender);
    s->next = head;
    head = s;

    printf("\nStudent %s added successfully!\n", name);
}

void deleteStudent(int id)
{
    student *prev = NULL, *curr = head;

    while (curr && curr->id != id)
    {
        prev = curr;
        curr = curr->next;
    }

    if (!curr)
    {
        printf("\nStudent with ID %d not found.\n", id);
        return;
    }

    if (prev)
        prev->next = curr->next;

    free(curr);
    printf("\nStudent with ID %d deleted.\n", id);
}

void searchStudent(int id)
{
    student *curr = head;

    while (curr)
    {
        if (curr->id == id)
        {
            printf("\nStudent Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nClass: %d\n",
                   curr->id,
                   curr->name,
                   curr->age,
                   curr->gender,
                   curr->classNumber);
            return;
        }
        curr = curr->next;
    }

    printf("\nStudent with ID %d not found.\n", id);
}

void displayByClass(int classNum)
{
    student *curr = head;
    int count = 0;

    printf("\nStudents in Class %d:\n", classNum);
    while (curr)
    {
        if (curr->classNumber == classNum)
        {
            printf("ID: %d | Name: %s | Age: %d | Gender: %s\n", curr->id, curr->name, curr->age, curr->gender);
            count++;
        }
        curr = curr->next;
    }
    // printf("\n");

    if (!count)
        printf("\nNo students found in Class %d.\n", classNum);
}
