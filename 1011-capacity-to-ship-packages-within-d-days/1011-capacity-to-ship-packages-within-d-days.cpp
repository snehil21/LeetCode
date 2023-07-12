class Solution {
    bool isValid(vector<int>& weights,int mid,int days){
        int count=1,currWeight=0;;
        for(auto it:weights){
            currWeight+=it;
            if(currWeight>mid){
                currWeight=it;
                count++;
            }
        }
        return count<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0;
        for(auto it:weights){
            high+=it;
            low=max(low,it);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};