class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int count=1,num=nums[i]+1;
                while(st.find(num)!=st.end()){
                    num++;count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};