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
    int res=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dbt(root);
        return res;
    }
private:
    int dbt(TreeNode* root){
        if(root==NULL) return 0;
        int lp=dbt(root->left);
        int rp=dbt(root->right);
        res=max(res,lp+rp);
         return 1+max(lp,rp);;
    }
};