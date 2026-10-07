char* intToRoman(int num) {
    // 1. Allocate a string buffer in memory. 
    // The longest possible Roman numeral under 4000 is 15 characters long (e.g., 3888 is MMMDCCCLXXXVIII).
    // An allocation of 20 bytes is safe, fast, and completely clean.
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0'; // Start with an empty string

    // 2. Define the matching values and their Roman characters from largest to smallest.
    // We include the subtractive cases (900, 400, 90, 40, 9, 4) to handle rules 2 and 3 natively.
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // 3. Keep subtracting the largest values we can until num becomes 0
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]); // Append the Roman symbol to our string
            num -= values[i];           // Subtract its numeric worth
        }
    }

    return result;
}
