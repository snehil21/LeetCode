class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int currSum = 0, n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            currSum+=nums[i];
            int target=currSum-k;
            if(currSum==k){
                count++;
            }
            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }
            mp[currSum]++;
        }
        return count;
    }
};