class Solution {
public:
    int maxi = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        maxsum(root);
        return maxi;
    }
    int maxsum(TreeNode* root)
    {
        if(root == nullptr)
        return 0;
        int left = max(0, maxsum(root->left));
        int right = max(0, maxsum(root->right));
        maxi = max(maxi, root->val + left + right);
        return root->val + max(left, right);
    }
};