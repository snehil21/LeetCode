class Solution {
private:
    int dp[2001][2001];
    unordered_map<int,int>mp;
    bool solve(int idx,int k,vector<int>&stones){
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        if(idx==stones.size()-1){
            return true;
        }
        bool curr=false,next=false,prev=false;
        if(mp.find(stones[idx]+k)!=mp.end()){
            curr=solve(mp[stones[idx]+k],k,stones);
        }
        if (k > 1 && mp.find(stones[idx] + k - 1) != mp.end()) {
            prev = solve(mp[stones[idx] + k - 1], k - 1, stones);
        }
        if (mp.find(stones[idx] + k + 1) != mp.end()) {
            next = solve(mp[stones[idx] + k + 1], k + 1, stones);
        }
        return dp[idx][k]=(curr||prev||next);
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        return solve(1,1,stones);
    }
};