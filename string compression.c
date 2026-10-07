int compress(char* chars, int charsSize) {
    int write = 0;
    int read = 0;

    while (read < charsSize) {
        char currentChar = chars[read];
        int count = 0;

        // 1. Count consecutive identical characters
        while (read < charsSize && chars[read] == currentChar) {
            read++;
            count++;
        }

        // 2. Write the character
        chars[write++] = currentChar;

        // 3. Write the count if it's greater than 1
        if (count > 1) {
            int start = write; // Mark where the digits begin

            // Extract digits from right to left (e.g., 12 becomes '2', '1')
            while (count > 0) {
                chars[write++] = (count % 10) + '0';
                count /= 10;
            }

            // Reverse the digits back to the correct order (e.g., '2', '1' -> '1', '2')
            int end = write - 1;
            while (start < end) {
                char temp = chars[start];
                chars[start] = chars[end];
                chars[end] = temp;
                start++;
                end--;
            }
        }
    }
    return write;
}
