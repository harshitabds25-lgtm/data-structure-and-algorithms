#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        // Start checking from k, then 2k, 3k, ...
        for (long long multiple = k; ; multiple += k) {
            if (s.find(multiple) == s.end()) {
                return multiple;
            }
        }
    }
};
