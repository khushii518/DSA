//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, flag = 1;

    // Take input
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    i = 0;
    j = strlen(s) - 1;

    // Two-pointer comparison
    while (i < j) {
        if (s[i] != s[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    // Output
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
         
    return 0;
   }
