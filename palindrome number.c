bool isPalindrome(int x) {
    // Negative numbers are never palindromes (because of the '-' sign)
    if (x < 0) {
        return false;
    }

    int original = x;
    long reversed = 0;   // use long to avoid overflow when reversing

    while (x > 0) {
        reversed = (reversed * 10) + (x % 10);
        x = x / 10;
    }

    return original == reversed;
}
