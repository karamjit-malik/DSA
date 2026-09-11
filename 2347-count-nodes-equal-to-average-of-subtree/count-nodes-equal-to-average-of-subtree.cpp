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
struct Pair
{
    int x, y;

    Pair(int x, int y) : x(x), y(y) {}

    Pair operator+(const Pair& p2)
    {
        return Pair(x + p2.x, y + p2.y);
    }
};

class Solution 
{
    int ans = 0;

    Pair solve(TreeNode* root) 
    {
        if (!root) 
        {
            return Pair(0, 0);
        }

        Pair L = solve(root->left);
        Pair R = solve(root->right);

        Pair curr = L + R + Pair(root->val, 1);

        if (curr.x / curr.y == root->val) 
        {
            ans++;
        }
        return curr;
    }

public:
    int averageOfSubtree(TreeNode* root) 
    {
        solve(root);
        return ans;
    }
};