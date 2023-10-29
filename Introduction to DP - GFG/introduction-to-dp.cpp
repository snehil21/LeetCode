//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int solve(int n, vector<int>&dp){
        if(n<=1) return n%1000000007;
        if(dp[n]!=-1) return dp[n]%1000000007;
        return dp[n] = solve(n-1, dp)%1000000007+solve(n-2, dp)%1000000007;
    }
    long long int topDown(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp)%1000000007;
    }
    long long int bottomUp(int n) {
        vector<int>dp1(n+1, 0);
        dp1[0] = 0, dp1[1] = 1;
        for(int i=2; i<=n; i++){
            dp1[i] = (dp1[i-1]%1000000007+dp1[i-2]%1000000007)%1000000007;
        }
        return dp1[n]%1000000007;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends