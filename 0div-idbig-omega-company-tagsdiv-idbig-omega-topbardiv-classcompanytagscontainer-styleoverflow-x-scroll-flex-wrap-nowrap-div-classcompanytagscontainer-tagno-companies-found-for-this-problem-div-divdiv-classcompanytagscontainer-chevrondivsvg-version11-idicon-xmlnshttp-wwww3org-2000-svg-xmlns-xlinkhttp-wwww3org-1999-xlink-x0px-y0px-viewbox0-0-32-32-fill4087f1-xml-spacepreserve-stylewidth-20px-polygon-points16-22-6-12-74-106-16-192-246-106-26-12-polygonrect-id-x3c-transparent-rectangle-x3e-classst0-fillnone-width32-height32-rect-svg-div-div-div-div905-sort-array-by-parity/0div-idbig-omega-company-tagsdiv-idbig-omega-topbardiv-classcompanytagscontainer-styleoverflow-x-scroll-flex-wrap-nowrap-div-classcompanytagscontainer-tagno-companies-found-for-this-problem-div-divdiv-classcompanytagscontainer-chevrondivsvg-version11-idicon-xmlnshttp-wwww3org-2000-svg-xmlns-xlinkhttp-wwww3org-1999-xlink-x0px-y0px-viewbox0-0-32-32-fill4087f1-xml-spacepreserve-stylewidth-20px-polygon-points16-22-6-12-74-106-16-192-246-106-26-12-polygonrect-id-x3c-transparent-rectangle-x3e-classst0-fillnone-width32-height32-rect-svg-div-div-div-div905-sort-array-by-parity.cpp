class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            if(nums[i]%2 !=0 && nums[j]%2==0 && i<j){
                swap(nums[i],nums[j]);
                i++;j++;
            }else if(nums[i]%2!=0){
                j++;
            }else{
                i++;
            }
        }
        return nums;
    }
};