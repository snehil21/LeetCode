class Solution {
    bool isValid(vector<int>&v,long long mid,int h){
        int hrs=0;
        for(auto it:v){
            hrs+=(it/mid);
            if(it%mid){
                hrs++;
            }
        }
        return hrs<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high=1e14;
        int ans;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};