class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.size()>0){
                    ans+='(';
                }
                st.push('(');
            }else{
                st.pop();
                if(st.size()>0){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};