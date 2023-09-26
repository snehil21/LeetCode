//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        bool isChildofRoot(int child,int root,vector<int>&parent){
            if(parent[child]==root || root==child)return true;
            if(parent[child]==-1)return false;
            return isChildofRoot(parent[child],root,parent);
        }
        vector<string> isInSubtree(vector<vector<int>> &g,int n,int m,vector<vector<int>> queries)
        {
            vector<int>parent(n+1,-1);
            //marking parent
            queue<pair<int,int>>q;
            vector<int>vis(n+1,0);
            q.push({1,-1});
            while(!q.empty()){
                int child=q.front().first;
                int p=q.front().second;
                q.pop();
                parent[child]=p;
                vis[child]=1;
                for(int i:g[child]){
                    if(!vis[i]){
                        q.push({i,child});
                    }
                }
            }
            vector<string>ans;
            for(int i=0;i<m;i++){
                int child=queries[i][0],root=queries[i][1];
                if(isChildofRoot(child,root,parent)){
                    ans.push_back("YES");
                }else{
                    ans.push_back("NO");
                }
            }
            return ans;
        }
};

// 4 1

//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int q;
        cin>>q;
        vector <vector<int>> queries(q,vector<int> (2));
        for(auto &j:queries)
            cin>>j[0]>>j[1];
        
        Solution s;
        vector<string> ans=s.isInSubtree(g,n,q,queries);
        for(auto j:ans)
            cout<<j<<endl;
    }
    return 0;
}
// } Driver Code Ends