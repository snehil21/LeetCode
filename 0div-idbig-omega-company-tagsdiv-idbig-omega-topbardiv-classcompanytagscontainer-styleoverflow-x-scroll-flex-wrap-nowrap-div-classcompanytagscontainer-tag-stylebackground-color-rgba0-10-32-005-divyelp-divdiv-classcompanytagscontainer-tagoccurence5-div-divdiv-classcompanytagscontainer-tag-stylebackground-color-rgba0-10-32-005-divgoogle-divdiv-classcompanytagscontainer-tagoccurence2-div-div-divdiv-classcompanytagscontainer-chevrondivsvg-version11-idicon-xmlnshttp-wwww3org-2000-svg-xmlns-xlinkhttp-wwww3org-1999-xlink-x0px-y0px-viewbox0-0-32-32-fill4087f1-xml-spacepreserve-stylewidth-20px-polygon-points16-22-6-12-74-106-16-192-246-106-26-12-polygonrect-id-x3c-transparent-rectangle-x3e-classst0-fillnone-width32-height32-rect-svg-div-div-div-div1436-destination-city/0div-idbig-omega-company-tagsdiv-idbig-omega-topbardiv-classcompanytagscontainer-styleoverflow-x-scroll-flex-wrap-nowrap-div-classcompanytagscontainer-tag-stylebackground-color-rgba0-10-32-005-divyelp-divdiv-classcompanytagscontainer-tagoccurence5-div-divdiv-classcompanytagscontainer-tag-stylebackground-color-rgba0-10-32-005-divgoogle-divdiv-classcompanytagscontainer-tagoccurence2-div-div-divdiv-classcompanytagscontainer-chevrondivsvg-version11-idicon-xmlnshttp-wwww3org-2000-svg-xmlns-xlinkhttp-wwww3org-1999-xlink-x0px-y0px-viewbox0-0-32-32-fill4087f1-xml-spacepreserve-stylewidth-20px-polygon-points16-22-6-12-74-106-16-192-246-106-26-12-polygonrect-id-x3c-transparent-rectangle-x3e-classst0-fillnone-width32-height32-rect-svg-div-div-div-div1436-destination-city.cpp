class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>st;
        for(auto path:paths){
            st.insert(path[0]);
        }
        for(auto path:paths){
            if(st.find(path[1])==st.end()){
                return path[1];
            }
        }
        return "";
    }
};