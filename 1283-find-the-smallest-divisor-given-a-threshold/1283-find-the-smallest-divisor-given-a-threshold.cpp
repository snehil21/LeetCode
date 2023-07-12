class Solution {
    bool isValid(vector<int>& nums,int mid,int threshold){
        int divisorSum=0;
        for(auto it:nums){
            divisorSum+=(it/mid);
            if(it%mid)divisorSum++;
        }
        return divisorSum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans,low=1;
        int high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};