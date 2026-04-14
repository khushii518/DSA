#include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Step 1: count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // no non-repeating character
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}
