char* multiply(char* num1, char* num2) {
    // Edge case: if either string is "0", the product is "0"
    if (num1[0] == '0' || num2[0] == '0') {
        return "0"; 
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total_len = len1 + len2;
    
    // Create an array for intermediate math, initialized to zeroes
    int* res = (int*)calloc(total_len, sizeof(int));

    // Multiply every digit combination from right to left
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }

    // Allocate exact space for the final string result (+1 for '\0')
    char* result_str = (char*)malloc((total_len + 1) * sizeof(char));
    int start = 0, idx = 0;
    
    // Skip any unneeded leading zeroes
    while (start < total_len && res[start] == 0) {
        start++;
    }

    // Convert digit integers to string characters
    while (start < total_len) {
        result_str[idx++] = res[start++] + '0';
    }
    result_str[idx] = '\0'; // Null terminator

    free(res);
    return result_str;
}
