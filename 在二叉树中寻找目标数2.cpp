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
#include<iostream>
#include<vector>
using namespace std;
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//经典的递归问题，回溯算法，进去一个节点，如果以这个节为头的节点以下的都不符合，需要删除该节点
//同时要注意头节点，边界条件
class Solution {
public:
    vector<int> res;
    vector<vector<int>> ress;

    void dfs(TreeNode* root, int targetSum, int sum)
    {

        if (root->left == nullptr && root->right == nullptr && sum == targetSum)
        {
            ress.push_back(res);
            return;
        }

        if (root->left == nullptr && root->right == nullptr) return;

        if (root->left)
        {
            res.push_back(root->left->val);
            sum += root->left->val;
            dfs(root->left, targetSum, sum);
            sum -= root->left->val;
            res.pop_back();
        }

        if (root->right)
        {
            res.push_back(root->right->val);
            sum += root->right->val;
            dfs(root->right, targetSum, sum);
            sum -= root->right->val;
            res.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ress;
        res.push_back(root->val);
        dfs(root, targetSum - root->val, 0);
        return ress;
    }
};