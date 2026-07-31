class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++) {
            v.push_back({freq[i], (char)('a' + i)});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += v[i].first * (ceil(i / 8) + 1);
        }
        return res;
    }
};