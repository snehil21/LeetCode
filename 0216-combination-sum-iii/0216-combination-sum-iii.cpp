class Solution {
public:
  vector<vector<int>>ans;
    void solve(int idx,vector<int>&v,int n,int k){
        if(n==0 && k==v.size()){
            ans.push_back(v);
        }
        for(int i=idx;i<=9;i++){
            if(i<=n){
                v.push_back(i);
                solve(i+1,v,n-i,k);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int K, int N) {
        vector<int>v;
        solve(1,v,N,K);
        return ans;
    }
};