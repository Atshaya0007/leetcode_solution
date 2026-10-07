char* reverseVowels(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    
    while (i < j) {
        // Move i forward if it's not a vowel
        if (!strchr("aeiouAEIOU", s[i])) {
            i++;
        } 
        // Move j backward if it's not a vowel
        else if (!strchr("aeiouAEIOU", s[j])) {
            j--;
        } 
        // Both are vowels, so swap them
        else {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    return s;
}
