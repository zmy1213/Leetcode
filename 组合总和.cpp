//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。


//这是一个经典的组合问题，
//因为本题没有组合数量要求，仅仅是总和的限制，所以递归没有层数的限制，只要选取的元素总和超过target，就返回！
//套回溯的模板即可
//注意不能重复 223 232所得也要把当所在数组的位置传递给函数

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void trackback(vector<int>& candidates, int target, int cur_index)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }


        for (int i = cur_index; i < candidates.size(); ++i)
        {
            if (target - candidates[i] >= 0)
            {
                path.push_back(candidates[i]);
                trackback(candidates, target - candidates[i], i);
                path.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        trackback(candidates, target, 0);
        return res;
    }
};