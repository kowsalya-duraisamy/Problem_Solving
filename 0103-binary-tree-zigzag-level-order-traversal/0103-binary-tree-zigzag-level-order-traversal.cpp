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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int count = 0;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) return res;
        q.push(root);
        bool leftToRight = true; // Direction flag

        while (!q.empty()) {
            vector<int> v;
            count = q.size();
            while (count != 0) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                --count;
            }
            if (!leftToRight) {
                reverse(v.begin(), v.end()); 
            }
            res.push_back(v);
            leftToRight = !leftToRight; 
        }
        return res;
    }
};
