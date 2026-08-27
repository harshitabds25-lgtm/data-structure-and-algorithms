class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {0};

        // Count characters of s
        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Use same character if possible
            if (cnt[x] > 0) {
                cnt[x]--;
                ans += target[i];
            }
            else {
                // Try to put the smallest character greater than target[i]
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        ans += char('a' + c);
                        cnt[c]--;

                        // Fill remaining positions in ascending order
                        for (int k = 0; k < 26; k++) {
                            while (cnt[k] > 0) {
                                ans += char('a' + k);
                                cnt[k]--;
                            }
                        }

                        return ans;
                    }
                }

                // Cannot increase at this position,
                // so backtrack to an earlier position
                for (int j = i - 1; j >= 0; j--) {
                    cnt[ans[j] - 'a']++;

                    int prev = ans[j] - 'a';

                    for (int c = prev + 1; c < 26; c++) {
                        if (cnt[c] > 0) {
                            ans.resize(j);

                            ans += char('a' + c);
                            cnt[c]--;

                            // Fill remaining characters in sorted order
                            for (int k = 0; k < 26; k++) {
                                while (cnt[k] > 0) {
                                    ans += char('a' + k);
                                    cnt[k]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        // s itself is equal to target, so find the next permutation
        for (int j = ans.size() - 1; j >= 0; j--) {
            cnt[ans[j] - 'a']++;

            int prev = ans[j] - 'a';

            for (int c = prev + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans.resize(j);
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};