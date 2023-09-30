class Solution {
public:
    int myAtoi(string s) {
        double num=0;
        bool neg=false;
        while(s.size() && s[0]==' '){
            s.erase(s.begin(),s.begin()+1);
        }
        if(s[0]=='-'){
            s.erase(s.begin(),s.begin()+1);
            neg=true;
        }
        else if(s[0]=='+'){
            s.erase(s.begin(),s.begin()+1);
        }
        if(!(s[0]>='0' && s[0]<='9')){
            return 0;
        }
        int i=0;
        while((s[i]>='0' && s[i]<='9') && i<s.size()){
            num*=10;
            num+=(s[i]-'0');
            i++;
        }
        if(neg){
            num=-1*num;
        }
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return (int)num;
    }
};