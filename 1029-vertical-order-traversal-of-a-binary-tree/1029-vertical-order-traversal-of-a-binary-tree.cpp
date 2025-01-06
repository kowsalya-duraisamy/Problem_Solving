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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>>mp;
        queue <pair<TreeNode*,int>>q;
        q.push({root,0});
        int s,col,level=0;
        TreeNode*curr;
        while(!q.empty()){
            s=q.size();
            while(s--){
                curr=q.front().first;
                col=q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left,col-1});
                if(curr->right) q.push({curr->right,col+1});
                mp[col][level].insert(curr->val);
            }
            level++;
        }
        for(auto &coldata:mp){
            vector<int> temp;
            for(auto&rowdata:coldata.second){
                for(auto&val:rowdata.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};