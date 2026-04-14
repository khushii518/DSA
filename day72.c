#include <stdio.h>

char firstRepChar(char *s) {
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        freq[index]++;

        if (freq[index] == 2) {
            return s[i]; // first repeated character
        }
    }

    return '-'; // indicates no repeated character
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstRepChar(s);

    if (result == '-') {
        printf("-1\n");
    } else {
        printf("%c\n", result);
    }

    return 0;
}
