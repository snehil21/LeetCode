//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int dx[8] = {-1,1,0,0,-1, 1, -1, 1};
        int dy[8] = {0,0,-1,1, 1, 1, -1, -1};
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int count=0;
                    for(int k=0;k<8;k++){
                        int nx=i+dx[k],ny=j+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]==0){
                            count++;
                        }
                    }
                    if(count%2==0 && count>0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends