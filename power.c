double myPow(double x, int n) {
    long long N = n; // Use long long to handle INT_MIN (-2147483648) safely
    if (N < 0) {
        N = -N;
    }

    double result = 1.0;
    double current_product = x;

    // Binary Exponentiation
    while (N > 0) {
        if (N % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
        N /= 2;
    }

    // Invert the final result only ONCE to preserve precision
    if (n < 0) {
        return 1.0 / result;
    }

    return result;
}

