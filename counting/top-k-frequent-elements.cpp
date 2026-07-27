class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (k-- && !pq.empty()) {
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};