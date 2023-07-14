class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size();
        string temp="";
        int start=n-1,end=0;;
        while(s[start]==' '){
            start--;
        }
        while(s[end]==' '){
            end++;
        }
        for(int i=start;i>=end;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                if(temp!=""){
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    ans+=" ";
                }
                temp="";
            }
        }
        if(temp!=""){
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        return ans;
    }
};