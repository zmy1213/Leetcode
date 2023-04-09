//
//给你二叉树的根结点 root ，请你将它展开为一个单链表：
//
//展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
//展开后的单链表应该与二叉树 先序遍历 顺序相同。


//简单的做法，使用前序遍历将数的节点储存到向量中，然后给right 节点幅值即可，注意左子节点为空 空间复杂度O（n）
//复杂的做法：如果其左子节点不为空，则在其左子树中找到最右边的节点，作为前驱节点，将当前节点的右子节点赋给前驱节点的右子节点，
//然后将当前节点的左子节点赋给当前节点的右子节点，并将当前节点的左子节点设为空。对当前节点处理结束后，继续处理链表中的下一个节点，直到所有节点都处理结束


class Solution {
public:
    vector<TreeNode*> res;
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        res.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root);
        TreeNode* t = root;
        for (int i = 1; i < res.size(); ++i)
        {
            t->left = nullptr;
            t->right = res[i];
            t = t->right;
        }
    }
};

//复杂
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
