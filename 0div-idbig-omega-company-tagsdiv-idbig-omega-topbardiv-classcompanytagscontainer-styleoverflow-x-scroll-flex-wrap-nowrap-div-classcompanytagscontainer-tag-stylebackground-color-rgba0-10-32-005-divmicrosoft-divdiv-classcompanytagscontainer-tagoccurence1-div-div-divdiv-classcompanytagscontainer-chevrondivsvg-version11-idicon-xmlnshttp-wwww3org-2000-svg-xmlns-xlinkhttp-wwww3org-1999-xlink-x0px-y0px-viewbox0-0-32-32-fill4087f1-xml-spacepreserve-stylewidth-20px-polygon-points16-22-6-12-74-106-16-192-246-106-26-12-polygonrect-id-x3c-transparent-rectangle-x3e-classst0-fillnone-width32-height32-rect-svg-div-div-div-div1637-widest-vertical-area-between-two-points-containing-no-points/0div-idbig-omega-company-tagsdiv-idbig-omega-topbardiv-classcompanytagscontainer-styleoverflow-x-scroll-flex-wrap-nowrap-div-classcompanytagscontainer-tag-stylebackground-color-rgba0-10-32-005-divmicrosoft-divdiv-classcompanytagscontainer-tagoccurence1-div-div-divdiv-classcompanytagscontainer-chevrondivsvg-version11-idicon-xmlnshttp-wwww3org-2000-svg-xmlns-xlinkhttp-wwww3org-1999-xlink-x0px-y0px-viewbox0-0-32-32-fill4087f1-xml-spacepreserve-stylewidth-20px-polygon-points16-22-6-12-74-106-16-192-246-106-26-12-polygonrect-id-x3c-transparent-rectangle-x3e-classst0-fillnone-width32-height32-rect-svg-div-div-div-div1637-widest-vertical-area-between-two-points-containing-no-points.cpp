class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>xDist;
        for(auto point:points){
            xDist.push_back(point[0]);
        }
        sort(xDist.begin(),xDist.end());
        int maxWidth=0;
        for(int i=0;i<xDist.size()-1;i++){
            maxWidth=max(maxWidth,xDist[i+1]-xDist[i]);
        }
        return maxWidth;
    }
};