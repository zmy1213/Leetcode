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
    unordered_map<int, int> index;
    TreeNode* dfs(vector<int>& inorder, vector<int>& preorder, int in_left, int in_right, int pre_left, int pre_right)
    {
        if (in_left > in_right)
            return nullptr;
        TreeNode* node = new TreeNode;
        int in_root = index[preorder[pre_left]];
        int size = in_root - in_left;
        node->val = preorder[pre_left];

        node->left = dfs(inorder, postorder, in_left, in_left + size - 1, pre_left+1, pre_left + size - 1);
        node->right = dfs(inorder, postorder, in_root + 1, in_right, pre_left+size,pre_right);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {

        int i = 0;
        for (const auto& val : preorder)
        {
            index.emplace(inorder[i], i);
            ++i;
        }
        return dfs(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};