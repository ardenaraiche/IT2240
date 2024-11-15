#include <stdio.h>

struct studentGrade {
    int id;
    int grade;
};
void inputGrades(struct studentGrade[], int*);
void outputGrades(struct studentGrade[], int);
void sortGradesByID(struct studentGrade[], int);
int main(void) {
    struct studentGrade grades[100]; // Array of studentGrade
    int numGrades = 0; // Number of grades entered

    // Input grades
    inputGrades(grades, &numGrades);

    // Sort grades by ID
    sortGradesByID(grades, numGrades);

    // Output sorted grades
    outputGrades(grades, numGrades);

    return 0;
}
void inputGrades(struct studentGrade grades[], int* numGrades) {
    int id, grade;

    printf("Enter student ID and grade (Enter -1 to stop):\n");
    while (1) {
        printf("ID: ");
        scanf("%d", &id);
        if (id == -1) break;

        printf("Grade: ");
        scanf("%d", &grade);

        grades[*numGrades].id = id;
        grades[*numGrades].grade = grade;
        (*numGrades)++;
    }
}
void outputGrades(struct studentGrade grades[], int numGrades) {
    printf("Sorted grades by ID:\n");
    for (int i = 0; i < numGrades; i++) {
        printf("ID: %d, Grade: %d\n", grades[i].id, grades[i].grade);
    }
}
void sortGradesByID(struct studentGrade grades[], int numGrades) {
    struct studentGrade temp;

    for (int i = 0; i < numGrades - 1; i++) {
        for (int j = i + 1; j < numGrades; j++) {
            if (grades[i].id > grades[j].id) {
                temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
    }
}
