/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    int result=0;
    
    void solve(TreeNode* root,int gpV,int pV){
        if(gpV%2==0)result+=root->val;
        
        if(root->left!=NULL)solve(root->left,pV,root->val);
        if(root->right!=NULL)solve(root->right,pV,root->val);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        solve(root,1,1);
        return result;
    }
};