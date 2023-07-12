class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size(),ans=0;
        int h=0,l=INT_MIN;
        for(int i=0;i<n;i++){
            h+=arr[i];
            l=max(l,arr[i]);
        }
        while(l<=h){
            int mid=(l+h)/2;
            int count=1;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=arr[i];
                if(sum>mid){
                    sum=arr[i];
                    count++;
                }
            }
            if(count<=k){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};