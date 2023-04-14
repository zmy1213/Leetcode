
//栈实现
//第一次到达该节点就输出
//在押入右节点和左节点  因为是栈的顺序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        TreeNode* t = root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            t = s.top();
            s.pop();
            res.push_back(t->val);

            if (t->right != nullptr)
            {
                s.push(t->right);
            }
            if (t->left != nullptr)
            {
                s.push(t->left);
            }
        }

        return res;
    }
};