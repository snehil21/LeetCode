class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startingrow=0,startingcol=0;
        int row=matrix.size(),col=matrix[0].size();
        int count=row*col;
        int endingrow=row-1,endingcol=col-1;
        vector<int>res;
        while(count){
            for(int i=startingcol;count&&i<=endingcol;i++){
                res.push_back(matrix[startingrow][i]);
                count--;
            }
            startingrow++;
            for(int i=startingrow;count&&i<=endingrow;i++){
                res.push_back(matrix[i][endingcol]);
                count--;
            }
            endingcol--;
            for(int i=endingcol;count && i>=startingcol; i--)
            {
                res.push_back(matrix[endingrow][i]);
                count--;
            }
            endingrow--;
            for(int i=endingrow;count && i>=startingrow; i--)
            {
                res.push_back(matrix[i][startingcol]);
                count--;
            }
            startingcol++;
        }
        return res;
    }
};