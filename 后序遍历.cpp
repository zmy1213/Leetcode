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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        TreeNode* t = root;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(t);
        while (!s1.empty())
        {
            t = s1.top();
            s2.push(t);
            s1.pop();
            if (t->left != nullptr)
            {
                s1.push(t->left);
            }
            if (t->right != nullptr)
            {
                s1.push(t->right);
            }
        }

        while (!s2.empty())
        {
            t = s2.top();
            res.push_back(t->val);
            s2.pop();
        }
        return res;
    }
};