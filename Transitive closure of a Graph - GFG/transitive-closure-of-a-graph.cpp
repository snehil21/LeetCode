//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>>adj(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>>res(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            vector<int>vis(N,0);
            dfs(i,vis,adj);
            for(int j=0;j<N;j++){
                if(vis[j]){
                    res[i][j]=1;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends