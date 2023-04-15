//ע������Ҫ�жϱ����ǲ��ǿգ��վ����ң����յľ�������
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