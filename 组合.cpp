//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//
//你可以按 任何顺序 返回答案。

//注意回溯算法的精髓，递归控制树的深度，for控制树的宽度
//
//回溯法三部曲，逐步分析了函数参数、终止条件和单层搜索的过程。
//函数参数 树的宽度n，k是终止条件的参数，startindex 是下一此选择的起始部位
//例如 12345 当前选择了2 那么下一次就选择了3
//终止条件，path的长度为n
//单层推入推出即可
//回溯法解决的问题都可以抽象为树形结构（N叉树），用树形结构来理解回溯就容易多了
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void trackback(int n, int k, int startindex)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = startindex; i <= n; ++i)
        {
            path.push_back(i);
            trackback(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        trackback(n, k, 1);
        return res;
    }
};