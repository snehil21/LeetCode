//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int node,vector<bool>&vis,vector<int>adj[]){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
    public:
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>vis(V,false);
	    int motherVertex;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj);
	            motherVertex=i;
	        }
	    }
	    for(int i=0;i<V;i++){
	        vis[i]=false;
	    } 
	    dfs(motherVertex,vis,adj);
	    for(auto it:vis){
	        if(!it){
	            return -1;
	        }
	    }
	    return motherVertex;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends