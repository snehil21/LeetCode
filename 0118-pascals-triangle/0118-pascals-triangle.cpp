class Solution {
    vector<int>generateRow(int row){
        vector<int>v;
        v.push_back(1);
        int ans=1;
        for(int col=1;col<row;col++){
            ans*=(row-col);
            ans/=col;
            v.push_back(ans);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};