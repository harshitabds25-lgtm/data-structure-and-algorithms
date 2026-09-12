class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // each interval: l, r, w, original index
        vector<array<long long,4>> iv(n);
        for (int i = 0; i < n; i++) {
            iv[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(iv.begin(), iv.end(), [](const array<long long,4>& a, const array<long long,4>& b){
            return a[1] < b[1];
        });
        vector<long long> rArr(n);
        for (int i = 0; i < n; i++) rArr[i] = iv[i][1];

        // dp[i][k] = {score, sorted list of original indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5, {0LL, {}})
        );

        auto better = [](const pair<long long, vector<int>>& a,
                          const pair<long long, vector<int>>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; // lexicographically smaller wins
        };

        for (int i = 1; i <= n; i++) {
            long long l = iv[i-1][0];
            long long w = iv[i-1][2];
            int origIdx = (int)iv[i-1][3];

            // count of intervals with r < l (non-overlapping predecessors)
            int cnt = upper_bound(rArr.begin(), rArr.end(), l - 1) - rArr.begin();

            dp[i][0] = {0LL, {}};
            for (int k = 1; k <= 4; k++) {
                pair<long long, vector<int>> skip = dp[i-1][k];

                pair<long long, vector<int>> base = dp[cnt][k-1];
                pair<long long, vector<int>> take;
                take.first = base.first + w;
                take.second = base.second;
                auto pos = lower_bound(take.second.begin(), take.second.end(), origIdx);
                take.second.insert(pos, origIdx);

                dp[i][k] = better(skip, take) ? skip : take;
            }
        }

        return dp[n][4].second;
    }
};