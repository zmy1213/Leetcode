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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right)
    {
        if (in_left > in_right)
            return nullptr;
        TreeNode* node = new TreeNode;
        int in_root = index[postorder[post_right]];
        int size = in_root - in_left;
        node->val = postorder[post_right];

        node->left = dfs(inorder, postorder, in_left, in_left + size - 1, post_left, post_left + size - 1);
        node->right = dfs(inorder, postorder, in_root + 1, in_right, post_left + size, post_right - 1);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int i = 0;
        for (const auto& val : postorder)
        {
            index.emplace(inorder[i], i);
            ++i;
        }
        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};