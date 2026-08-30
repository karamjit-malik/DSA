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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(root == nullptr)
        return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> adder;
            while(sz--)
            {
                TreeNode* top = q.front();
                q.pop();
                adder.push_back(top->val);
                if(top->left!=nullptr)
                q.push(top->left);
                if(top->right)
                q.push(top->right);
            }
            res.push_back(adder);
        }
        return res;
    }
};