//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)return -1;
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        vector<vector<int>>vis(N,vector<int>(M,0));
        vis[0][0]=1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int num=q.front().second;
            q.pop();
            if(x==X && y==Y){
                return num;
            }
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1 && vis[nx][ny]==0){
                    q.push({{nx,ny},num+1});
                    vis[nx][ny]=1;
                }
            }
        }
      return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends