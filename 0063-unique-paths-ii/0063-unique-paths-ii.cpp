class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&obs,vector<vector<int>>&dp){
        if(i<m && j<n && obs[i][j]==1) return 0; 
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>= n)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=solve(i+1,j,m,n,obs,dp);
        int left=solve(i,j+1,m,n,obs,dp);
        return dp[i][j]=left+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,obs,dp);
    }
};