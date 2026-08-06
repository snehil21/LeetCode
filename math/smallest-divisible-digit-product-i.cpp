class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod=1,temp=n;
        while(temp){
            prod*=(temp%10);
            temp/=10;
        }
        int diff=min(prod%t,t-(prod%t));
        return n+diff;
    }
};