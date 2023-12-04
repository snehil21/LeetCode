class Solution {
public:
    string largestGoodInteger(string num) {
        string res="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string curr="";
                curr+=num[i];
                curr+=num[i+1];
                curr+=num[i+2];
                res=max(curr,res);
            }
        }
        return res;
    }
};