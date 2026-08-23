class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, right = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') qLeft++;
            else left += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') qRight++;
            else right += num[i] - '0';
        }

        if ((qLeft + qRight) % 2)
            return true;

        return 2 * (left - right) + 9 * (qLeft - qRight) != 0;
    }
};