class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        int mn = nums1[0];

        for (int x : nums1) {
            if (x % 2 != 0)
                allEven = false;

            mn = min(mn, x);
        }

        // If all numbers are even, keep them as they are.
        if (allEven)
            return true;

        // Otherwise, the smallest number must be odd.
        return mn % 2 != 0;
    }
};