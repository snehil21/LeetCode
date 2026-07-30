class Solution {
public:
    int res;
    void solve(int curr, int idx, string s) {
        if(curr<=0 || curr>26){
            return;
        }
        if (idx == s.size()) {
            if (curr > 0 && curr <= 26) {
                res++;
            }
            return;
        }
        int take = INT_MIN;
        int value = curr * 10 + (s[idx] - '0');
        solve(value, idx + 1, s);
        solve(s[idx] - '0', idx + 1, s);
    }
    int numDecodings(string s) {
        this->res = 0;
        solve(s[0]-'0', 1, s);
        return res;
    }
};