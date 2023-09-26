//User function Template for C++
class Solution
{
    public:
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    void dfs(int i, int j, vector<vector<int> > &grid, vector<vector<bool> > &visited, int val)     {
        grid[i][j]=val;
        visited[i][j]=true;
        int n = grid.size();
        for(int k=0; k<4; k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y] && !visited[x][y]){
                dfs(x, y, grid, visited, val);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        vector<vector<bool> > visited(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    dfs(i, j, grid, visited, ++cnt);
                }
            }
        }
        vector<int> freq(cnt+1, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
                if(grid[i][j])ans = max(ans, freq[grid[i][j]]);
            }
        }

        for(int i=0 ; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0; k<4; k++){
                        int x=i+dir[k][0],y=j+dir[k][1];
                        if(x>=0 && x<n && y>=0 && y<n){
                            if(grid[x][y]){
                                st.insert(grid[x][y]);
                            }
                        }
                    }
                    int curr = 1;
                    for (auto it = st.begin(); it != st.end(); it++)curr+=freq[*it];
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};