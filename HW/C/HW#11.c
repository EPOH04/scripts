#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 30

// Define the Student structure
struct Student {
    char name[MAX_NAME_LENGTH];
    float gpa;
};

// Function to compare students by GPA (ascending order)
int compare_by_gpa(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return (studentA->gpa > studentB->gpa) - (studentA->gpa < studentB->gpa);
}

// Function to compare students by name (reverse-alphabetical order)
int compare_by_name(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return strcmp(studentB->name, studentA->name); // Reverse alphabetical order
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Input student details
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i + 1);
        getchar(); // to consume any extra newline character
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove the newline character

        printf("Enter GPA of student %d: ", i + 1);
        scanf("%f", &students[i].gpa);
    }

    // Sort by GPA in ascending order
    qsort(students, numStudents, sizeof(struct Student), compare_by_gpa);

    // Output sorted students by GPA
    printf("\nStudents sorted by GPA (ascending):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, GPA: %.2f\n", students[i].name, students[i].gpa);
    }

    // Sort by name in reverse-alphabetical order
    qsort(students, numStudents, sizeof(struct Student), compare_by_name);

    // Output sorted students by name (reverse-alphabetical)
    printf("\nStudents sorted by name (reverse-alphabetical):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, GPA: %.2f\n", students[i].name, students[i].gpa);
    }

    return 0;
}
