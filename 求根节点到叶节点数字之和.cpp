//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//每条从根节点到叶节点的路径都代表一个数字：
//
//例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//计算从根节点到叶节点生成的 所有数字之和 。
//
//叶节点 是指没有子节点的节点。


//解题思路:这个题目也是明显的递归，不过和普通的遍历递归不一样，这个是对节点进行左右递归，将左面的递归总和加上右面的递归总共和
//且每次的结果乘10传递给下个结果
//中止条件是叶子节点或节点不存在
class Solution {
public:
    int dfs(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return 0;
        if (!root->left && !root->right)
            return 10 * sum + root->val;
        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};