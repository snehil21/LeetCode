class Solution {
public:
    int mySqrt(int x) {
        int ans,diff=INT_MAX;
        int low=0,high=x;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long val=(mid*mid);
            if(val<=(long long)x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};