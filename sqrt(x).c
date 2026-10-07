int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    long long low = 1, high = x, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == x) {
            return (int)mid;
        } else if (mid * mid < x) {
            ans = mid;      // mid is a valid candidate, keep searching for a bigger one
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return (int)ans;
}
