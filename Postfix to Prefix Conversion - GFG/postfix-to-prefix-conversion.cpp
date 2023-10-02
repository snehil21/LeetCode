//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  bool isOperand(char ch){
      return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
  }
  public:
    string postToPre(string postfix) {
        stack<string>st;
        for(int i=0;i<postfix.size();i++){
            if(isOperand(postfix[i])){
                st.push(string(1, postfix[i]));
            }else{
                string first=st.top();st.pop();
                string second=st.top();st.pop();
                st.push(postfix[i]+second+first);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends