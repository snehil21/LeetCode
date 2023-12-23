class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,bool>mp;
        int x=0,y=0;
        mp[{x,y}]=true;
        for(auto it:path){
            if(it=='N'){
                y+=1;
            }else if(it=='S'){
                y-=1;
            }else if(it=='E'){
                x+=1;
            }else{
                x-=1;
            }
            if(mp[{x,y}]){
                return true;
            }
            mp[{x,y}]=true;
        }
        return false;
    }
};