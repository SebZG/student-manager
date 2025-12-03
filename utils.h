#ifndef UTILS_H
#define UTILS_H

#include <stddef.h> // for NULL definition

typedef struct Student {
  int id;
  int classNumber;
  int age;
  char name[50];
  char gender[10];
  struct Student *next;
} student;

extern student *head;

void addStudent(int id, int classNumber, int age, char *name, char *gender);
void deleteStudent(int id);
void searchStudent(int id);
void displayByClass(int classNum);

#endif // UTILS_H
