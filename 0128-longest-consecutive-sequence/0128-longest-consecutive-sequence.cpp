class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(st.count(nums[i]-1)==0){
                int count=1,num=nums[i]+1;
                while(st.count(num)!=0){
                    num++;count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};