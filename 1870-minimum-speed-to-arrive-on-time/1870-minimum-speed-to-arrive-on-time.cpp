class Solution {
public:
    bool isValid(vector<int>& dist,int mid,double hour){
        double req=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/mid;
            if(i!=dist.size()-1){
                req+=ceil(d);
            }else{
                req+=d;
            }
        }
        return req<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};