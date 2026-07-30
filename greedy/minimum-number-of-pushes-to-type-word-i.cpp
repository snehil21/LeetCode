class Solution {
public:
    int minimumPushes(string word) {
        int res = 0, iteration = 1, n = word.size();
        while (n) {
            res += iteration * min(n, 8);
            n -= min(n, 8);
            iteration++;
        }
        return res;
    }
};