//注意他是要判断本次是不是空，空就推右，不空的就推左面
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        TreeNode* t = root;
        stack<TreeNode*> s;
        while (t != nullptr || !s.empty())
        {
            if (t != nullptr)
            {
                s.push(t);
                t = t->left;
            }
            else
            {
                t = s.top();
                res.push_back(t->val);
                s.pop();
                t = t->right;
            }
        }
        return res;
    }
};