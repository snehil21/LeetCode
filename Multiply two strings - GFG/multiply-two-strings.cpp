//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool flag=true;
       if(s1[0]=='-' && s2[0]=='-'){
           s1.erase(s1.begin()+0);
           s2.erase(s2.begin()+0);
       }
       else if(s1[0]=='-' && s2[0]!='-'){
           s1.erase(s1.begin()+0);
           flag=false;
       }
       else if(s2[0]=='-' && s1[0]!='-'){
           s2.erase(s2.begin()+0);
           flag=false;
       }
       if(s1=="0" || s2=="0") return "0";
       vector<int>res(s1.size()+s2.size(),0);
       for(int i=s1.size()-1;i>=0;i--){
           for(int j=s2.size()-1;j>=0;j--){
               res[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
               res[i+j]+=res[i+j+1]/10;
               res[i+j+1]%=10;
           }
       }
       int i=0;
       while(i<res.size()&&res[i]==0){
           i++;
       }
       string ans="";
       while(i<res.size()){
           ans+=res[i++]+'0';
       }
       if(flag==false) return "-"+ans;
       return ans;
    }

};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends