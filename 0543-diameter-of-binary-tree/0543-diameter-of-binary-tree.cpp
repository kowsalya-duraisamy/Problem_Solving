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
    int dia;
public:
    int getWidth(TreeNode* root){
        if(root==nullptr) return 0;
        int lw=getWidth(root->left);
        int rw=getWidth(root->right);
        dia=max(dia, lw+rw);
        return max(lw, rw)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=0;
        getWidth(root);
        return dia;
    }
};