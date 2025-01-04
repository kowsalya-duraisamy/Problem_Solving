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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int count=0;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            count=q.size();
            while(count!=0){
               // vector<int>v;
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                --count;
            }
            res.push_back(v);
        }
        return res;
    }
};