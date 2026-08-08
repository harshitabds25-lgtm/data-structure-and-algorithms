class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Convert to long long to avoid overflow when taking abs
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;
        
        // Subtract divisor multiples using bit shifts
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }
        
        return negative ? -result : result;
    }
};
