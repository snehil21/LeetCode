class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int>ans;
        ans.push_back(1);
        long long curr=1;
        for(long long col=1;col<rowIndex;col++){
            curr*=(rowIndex-col);
            curr/=col;
            ans.push_back((int)curr);
        }
        return ans;
    }
};