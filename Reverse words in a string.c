#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);  // output buffer
    int idx = 0;                             // write position in result
    int i = len - 1;                         // scan from the end of s

    while (i >= 0) {
        // Skip trailing/multiple spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i < 0) break;  // reached the start, no more words

        int end = i;  // end of current word

        // Move left until we hit a space or the start
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        int start = i + 1;  // start of current word

        // Add a single space before this word, unless it's the first word written
        if (idx != 0) {
            result[idx++] = ' ';
        }

        // Copy the word s[start..end] into result
        for (int j = start; j <= end; j++) {
            result[idx++] = s[j];
        }
    }

    result[idx] = '\0';
    return result;
}
