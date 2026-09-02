class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        // Check if all numbers are already even or odd
        bool allEven = true, allOdd = true;
        for (int x : nums1) {
            if (x % 2 == 0) allOdd = false;
            else allEven = false;
        }
        if (allEven || allOdd) return true;

        // Otherwise, check if we can make them uniform using differences
        // Key observation: nums1[i] - nums1[j] has parity = parity(nums1[i]) ^ parity(nums1[j])
        // If we have at least one even and one odd, we can always construct uniform parity
        bool hasEven = false, hasOdd = false;
        for (int x : nums1) {
            if (x % 2 == 0) hasEven = true;
            else hasOdd = true;
        }

        // If both exist, it's always possible
        return hasEven && hasOdd;
    }
};
