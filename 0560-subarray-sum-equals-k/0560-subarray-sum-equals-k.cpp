class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixsum=0,ans=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            prefixsum+=it;
            if(prefixsum==k){
                ans++;
            }
            if(mp.count(prefixsum-k)){
                ans+=mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        return ans;
    }
};