/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=0;
    pair<int,int>dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto lsubtree=dfs(root->left);
        auto rsubtree=dfs(root->right);
        int sum=lsubtree.first + rsubtree.first +root->val;
        int nodes=1+lsubtree.second+rsubtree.second;
        if(nodes!=0 && sum/nodes==root->val){
            res++;
        }
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};