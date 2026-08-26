class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') ones++;
                if (ones == k) {
                    int len = j - i + 1;
                    string candidate = s.substr(i, len);
                    if (len < minLen || (len == minLen && candidate < best)) {
                        best = candidate;
                        minLen = len;
                    }
                    break; // no need to extend further, length only increases
                }
            }
        }
        return best;
    }
};
