class Solution {
public:
    int maxDepth(string s) {
        int max_depth=0;
        int curr_depth=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                curr_depth++;
            }else if(s[i]==')'){
                max_depth=max(max_depth,curr_depth);
                curr_depth--;
            }
        }
        return max_depth;
    }
};