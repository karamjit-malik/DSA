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
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)
        return 0;
        int len = 1;
        return height(root);
    }
    int height(TreeNode* root)
    {
        if(root == nullptr)
        return 1;
        int left = 0 , right = 0;
        if(root->left)
        left = height(root->left);
        if(root->right)
        right = height(root->right);
        return 1+max(left,right);
    }
};