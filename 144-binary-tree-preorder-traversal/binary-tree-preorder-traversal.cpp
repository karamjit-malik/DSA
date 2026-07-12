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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        TreeNode* temp = root;
        if(root == nullptr)
        return {};
        stack<TreeNode*> q;
        q.push(temp);
        while(!q.empty())
        {
            TreeNode* curr = q.top();
            q.pop();
            ans.push_back(curr->val);
            if (curr->right != NULL)
            q.push(curr->right);
            if (curr->left != NULL)
            q.push(curr->left);
        }
        return ans;
    }
};