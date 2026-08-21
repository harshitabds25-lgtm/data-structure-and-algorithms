class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Remove redundant coins (multiples of others)
        sort(coins.begin(), coins.end());
        vector<int> filtered;
        for (int c : coins) {
            bool keep = true;
            for (int f : filtered) {
                if (c % f == 0) { // c is redundant
                    keep = false;
                    break;
                }
            }
            if (keep) filtered.push_back(c);
        }

        // Binary search for kth smallest
        long long left = 1, right = 1e18, ans = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            // Count multiples up to mid using inclusion-exclusion
            int n = filtered.size();
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(lcm, (long long)filtered[i]);
                        if (lcm > mid / (filtered[i] / g)) {
                            overflow = true;
                            break;
                        }
                        lcm = lcm / g * filtered[i];
                    }
                }
                if (!overflow) {
                    long long add = mid / lcm;
                    if (__builtin_popcount(mask) % 2) count += add;
                    else count -= add;
                }
            }

            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
