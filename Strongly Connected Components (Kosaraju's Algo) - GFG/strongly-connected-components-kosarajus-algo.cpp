//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfsT(int node,vector<bool>&vis,vector<vector<int>>& adj){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfsT(i,vis,adj);
            }
        }
    }
    private:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>& adj,stack<int>&st){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        st.push(node);
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            vis[i]=false;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                scc++;
                dfsT(i,vis,adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends