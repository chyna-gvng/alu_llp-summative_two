#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void findLCS(char *text1, char *text2, char *lcs) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int L[len1 + 1][len2 + 1];

    // Building the LCS table
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = MAX(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // Debugging: Print the LCS table
    printf("LCS table:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }

    // Following the LCS table to find the LCS
    int index = L[len1][len2];
    lcs[index] = '\0';  // Set the terminating null character

    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs[index - 1] = text1[i - 1];  // Include this character in the LCS
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    char text1[1000], text2[1000];

    printf("Enter the first text: ");
    fgets(text1, sizeof(text1), stdin);
    text1[strcspn(text1, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the second text: ");
    fgets(text2, sizeof(text2), stdin);
    text2[strcspn(text2, "\n")] = '\0';  // Remove trailing newline

    char lcs[1000];  // Adjust size as necessary

    findLCS(text1, text2, lcs);

    printf("Longest common subsequence: %s\n", lcs);

    return 0;
}
