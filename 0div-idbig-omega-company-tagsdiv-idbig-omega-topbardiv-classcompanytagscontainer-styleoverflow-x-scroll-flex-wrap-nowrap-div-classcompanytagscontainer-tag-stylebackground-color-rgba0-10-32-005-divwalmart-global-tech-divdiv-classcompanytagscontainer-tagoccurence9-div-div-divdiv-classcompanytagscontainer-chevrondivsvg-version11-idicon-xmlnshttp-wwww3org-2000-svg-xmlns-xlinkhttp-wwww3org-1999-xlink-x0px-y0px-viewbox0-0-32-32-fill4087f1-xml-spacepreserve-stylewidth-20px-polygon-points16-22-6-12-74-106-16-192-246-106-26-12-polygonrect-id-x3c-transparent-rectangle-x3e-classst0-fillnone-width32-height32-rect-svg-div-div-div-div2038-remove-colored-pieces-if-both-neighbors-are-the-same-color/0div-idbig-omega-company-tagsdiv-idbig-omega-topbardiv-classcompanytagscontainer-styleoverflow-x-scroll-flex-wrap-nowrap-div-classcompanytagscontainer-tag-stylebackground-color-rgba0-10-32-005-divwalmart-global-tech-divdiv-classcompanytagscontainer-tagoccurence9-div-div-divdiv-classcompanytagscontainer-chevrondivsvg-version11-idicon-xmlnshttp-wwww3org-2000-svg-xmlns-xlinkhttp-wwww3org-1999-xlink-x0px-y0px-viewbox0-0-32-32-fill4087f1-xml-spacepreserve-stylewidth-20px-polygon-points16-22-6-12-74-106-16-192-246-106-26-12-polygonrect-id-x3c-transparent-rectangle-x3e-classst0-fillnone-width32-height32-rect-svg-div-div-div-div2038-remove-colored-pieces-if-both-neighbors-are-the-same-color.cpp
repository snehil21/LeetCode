class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA=0,countB=0;
        for(int i=0;i<colors.size();i++){
            int count=0;
            char ch=colors[i];
            while(i<colors.size() && colors[i]==ch){
                i++;
                count++;
            }
            if(ch=='A'){
                countA+=max(0,count-2);
            }else{
                countB+=max(0,count-2);
            }
            i--;
        }
        return countA>countB;
    }
};