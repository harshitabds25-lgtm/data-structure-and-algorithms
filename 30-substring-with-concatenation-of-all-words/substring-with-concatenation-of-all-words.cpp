class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (auto &w : words) wordFreq[w]++;

        // Sliding window with different offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordFreq.find(word) != wordFreq.end()) {
                    window[word]++;
                    count++;

                    // Shrink window if word frequency exceeds
                    while (window[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Valid substring found
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
