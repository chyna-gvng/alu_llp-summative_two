#include <stdio.h>          // Line 1
#include <stdlib.h>         // Line 2
#include <string.h>         // Line 3

typedef struct {            // Line 4
    char fullName[100];     // Line 5
    float grade;            // Line 6
} Student;                  // Line 7

void merge(Student arr[], int left, int mid, int right) {       // Line 8
    int n1 = mid - left + 1;                                    // Line 9
    int n2 = right - mid;                                       // Line 10
    
    Student *L = (Student *)malloc(n1 * sizeof(Student));       // Line 11
    Student *R = (Student *)malloc(n2 * sizeof(Student));       // Line 12

    for (int i = 0; i < n1; i++)                                // Line 13
        L[i] = arr[left + i];                                   // Line 14
    for (int j = 0; j < n2; j++)                                // Line 15
        R[j] = arr[mid + 1 + j];                                // Line 16

    int i = 0, j = 0, k = left;                                 // Line 17

    while (i < n1 && j < n2) {                                  // Line 18
        if (L[i].grade >= R[j].grade) {                         // Line 19
            arr[k] = L[i];                                      // Line 20
            i++;                                                // Line 21
        } else {                                                // Line 22
            arr[k] = R[j];                                      // Line 23
            j++;                                                // Line 24
        }
        k++;                                                    // Line 25
    }

    while (i < n1) {            // Line 26
        arr[k] = L[i];          // Line 27
        i++;                    // Line 28
        k++;                    // Line 29
    }

    while (j < n2) {            // Line 30
        arr[k] = R[j];          // Line 31
        j++;                    // Line 32
        k++;                    // Line 33
    }

    free(L);                    // Line 34
    free(R);                    // Line 35
}                               // Line 36

void mergeSort(Student arr[], int left, int right) {            // Line 37
    if (left < right) {                                         // Line 38
        int mid = left + (right - left) / 2;                    // Line 39
        
        mergeSort(arr, left, mid);                              // Line 40
        mergeSort(arr, mid + 1, right);                         // Line 41
        
        merge(arr, left, mid, right);                           // Line 42
    }
}                                                               // Line 43

int main() {                                                    // Line 44
    int n;                                                      // Line 45
    printf("Enter the number of students: ");                   // Line 46
    scanf("%d", &n);                                            // Line 47
    
    Student *students = (Student *)malloc(n * sizeof(Student)); // Line 48
    
    for (int i = 0; i < n; i++) {                               // Line 49
        printf("Enter full name for student %d: ", i + 1);      // Line 50
        scanf(" %[^\n]s", students[i].fullName);                // Line 51
        printf("Enter grade for student %d: ", i + 1);          // Line 52
        scanf("%f", &students[i].grade);                        // Line 53
    }
    
    mergeSort(students, 0, n - 1);                                                         // Line 54
    
    printf("Sorted list of students:\n");                                                  // Line 55
    for (int i = 0; i < n; i++) {                                                          // Line 56
        printf("Full Name: %s, Grade: %.2f\n", students[i].fullName, students[i].grade);   // Line 57
    }

    free(students);         // Line 58
    return 0;               // Line 59
}                           // Line 60
