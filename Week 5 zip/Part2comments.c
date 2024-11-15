#include <stdio.h>

// Define a struct to hold student grade information
struct studentGrade {
    int id;     // Student ID
    int grade;  // Student Grade
};

// Function declarations
void inputGrades(struct studentGrade[], int*);
void outputGrades(struct studentGrade[], int);
void sortGradesByID(struct studentGrade[], int);

int main(void) {
    struct studentGrade grades[100]; // Array to store grades and IDs
    int numGrades = 0; // Variable to count the number of grades entered

    // Call the function to input grades
    inputGrades(grades, &numGrades);

    // Call the function to sort grades by student ID
    sortGradesByID(grades, numGrades);

    // Call the function to output sorted grades
    outputGrades(grades, numGrades);

    return 0; // Indicate successful completion
}

// Function to input grades from the user
void inputGrades(struct studentGrade grades[], int* numGrades) {
    int id, grade; // Variables to hold temporary input for ID and grade

    printf("Enter student ID and grade (Enter -1 to stop):\n");
    while (1) {
        printf("ID: ");
        scanf("%d", &id);
        if (id == -1) break; // Exit loop if the user enters -1

        printf("Grade: ");
        scanf("%d", &grade);

        // Store the entered ID and grade in the array
        grades[*numGrades].id = id;
        grades[*numGrades].grade = grade;
        (*numGrades)++; // Increment the number of grades entered
    }
}

// Function to output the grades sorted by student ID
void outputGrades(struct studentGrade grades[], int numGrades) {
    printf("Sorted grades by ID:\n");
    for (int i = 0; i < numGrades; i++) {
        printf("ID: %d, Grade: %d\n", grades[i].id, grades[i].grade);
    }
}

// Function to sort the grades by student ID
void sortGradesByID(struct studentGrade grades[], int numGrades) {
    struct studentGrade temp; // Temporary struct for swapping

    // Nested loop to perform bubble sort
    for (int i = 0; i < numGrades - 1; i++) {
        for (int j = i + 1; j < numGrades; j++) {
            // Swap if the current ID is greater than the next ID
            if (grades[i].id > grades[j].id) {
                temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
    }
}
