class Solution {
public:
    // int solve(int idx,int prevIdx,vector<int>& arr,int n,int diff){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     int take=0,nottake;
    //     if(prevIdx==-1 || arr[idx]-arr[prevIdx]==diff){
    //         take=1+solve(idx+1,idx,arr,n,diff);
    //     }
    //     nottake=solve(idx+1,prevIdx,arr,n,diff);
    //     return max(take,nottake);
    // }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        // return solve(0,-1,arr,n,difference);
        unordered_map<int,int>mp;
        int ans=1;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i]-difference)!=mp.end()){
                mp[arr[i]]=mp[arr[i]-difference]+1;
            }else{
                mp[arr[i]]=1;
            }
            ans=max(ans,mp[arr[i]]);
        }
        return ans;
    }
};