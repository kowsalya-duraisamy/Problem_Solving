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
    vector<int> rightSideView(TreeNode* root) {
         vector<vector<int>> res;
        vector<int>ans;
        queue<TreeNode*> q;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
           int  count = q.size();
            while (count != 0) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr!=NULL) 
                {
                    v.push_back(curr->val);
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                    --count;
                }
            }
            res.push_back(v);
        }
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][res[i].size()-1]);
        }
        return ans;
    }
};