class Solution {
public:
    int dx[8] = {-1,0,0,1};
    int dy[8] = {0,1,-1,0};
    bool dfs(int row,int col,int ind,vector<vector<char> >& board,string            word,vector<vector<int>>&vis){
        if(ind == word.size()) {
            return true; 
        }
        
        int n = board.size(); 
        int m = board[0].size();
        vis[row][col] = 1; 
        for(int i = 0; i < 4; i++) {
            int nrow = row + dx[i]; 
            int ncol = col + dy[i]; 
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == 0 && board[nrow][ncol] == word[ind]) {
                if(dfs(nrow, ncol, ind+1, board, word, vis)) {
                    return true; 
                }
            }
        }
        vis[row][col] = 0; 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(board[i][j]==word[0] && !vis[i][j]){
	                if(dfs(i,j,1,board,word,vis)){
	                    return true;
	                }
	            }
	        }
	    }
        return false;
    }
};