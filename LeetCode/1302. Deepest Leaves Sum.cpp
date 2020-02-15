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
    
    int MAX_DEPTH=0;
    int result=0;
    map<int,int>sumAtLvl;
    void findDepth(TreeNode* root,int depth){
        sumAtLvl[depth]+= root->val;
        if(root->left==NULL && root-> right==NULL){MAX_DEPTH = max(MAX_DEPTH,depth);}
        
        else if(root->left!=NULL && root-> right!=NULL)
             findDepth(root->left,depth+1),
             findDepth(root->right,depth+1);     
        else if( root-> right!=NULL)
             findDepth(root->right,depth+1);     
        else if( root-> left!=NULL)
             findDepth(root->left,depth+1);  
        
    }

    
    
    int deepestLeavesSum(TreeNode* root) {
        findDepth(root,1);
       
        return sumAtLvl[MAX_DEPTH];
    }
};