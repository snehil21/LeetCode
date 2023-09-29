class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing=false,decreasing=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                increasing=true;
            }else if(nums[i]<nums[i-1]){
                decreasing=true;
            }
            if(decreasing&&increasing){
                return false;
            }
        }
        return !(decreasing&&increasing);
    }
};