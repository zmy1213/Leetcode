//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

//解析，这是一个数组创建二叉搜索树，这种创建二叉搜索树的数要联想到递归
//由于要保证高度平衡，所以得保证树两边的节点数量要一样，所以要选择中间的数值
//因此每个节点都是其对接数组长度的中点
//注意边界条件，传递的是size()，以及传递的是s,mid,mid+1,e
//s>=e因此不会选择最右面的点

class Solution {
public:
    TreeNode *dfs(vector<int> nums,int s,int e)
    {
        if(s>=e) return nullptr;
        int mid = (s+e) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = dfs(nums,s,mid);
        root->right = dfs(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return dfs(nums,0,nums.size());
    }
};