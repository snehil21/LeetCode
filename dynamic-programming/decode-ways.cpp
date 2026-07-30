class Solution {
    vector<int> memo;

    int solve(int i, const string& s) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int ways = solve(i + 1, s);

        if (i + 1 < s.size()) {
            int value = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (value >= 10 && value <= 26) {
                ways += solve(i + 2, s);
            }
        }

        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        memo.assign(s.size(), -1);
        return solve(0, s);
    }
};