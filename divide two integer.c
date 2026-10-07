int divide(int dividend, int divisor) {
    // Special case: overflow when dividend = INT_MIN and divisor = -1
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine sign of result
    int negative = ((dividend < 0) != (divisor < 0));

    // Work with absolute values using long to avoid overflow (esp. for INT_MIN)
    long absDividend = labs((long)dividend);
    long absDivisor = labs((long)divisor);

    long quotient = 0;

    while (absDividend >= absDivisor) {
        long temp = absDivisor;
        long multiple = 1;

        // Double 'temp' (the chunk of divisor) as long as it still fits
        while (absDividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        // Subtract this largest chunk, and add its multiple to quotient
        absDividend -= temp;
        quotient += multiple;
    }

    if (negative) {
        quotient = -quotient;
    }

    return (int)quotient;
}
