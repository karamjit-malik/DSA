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
class BSTIterator {
public:
vector<int> order;
stack<int> s;
    BSTIterator(TreeNode* root)
    {
        function<void(TreeNode*)> inorder = [&](TreeNode* root)
        {
            if (root == nullptr)
            return;
            inorder(root->left);
            order.push_back(root->val);
            inorder(root->right);
        };
        inorder(root);
        reverse(order.begin(),order.end());
        for(int i : order)
        s.push(i);
    }
    int next()
    {
        int top = s.top();
        s.pop();
        return top;
    }
    bool hasNext()
    {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */