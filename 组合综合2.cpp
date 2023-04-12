//����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
//
//candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��
//
//ע�⣺�⼯���ܰ����ظ�����ϡ�

//�������⣬�������
//��ģ��
//��������
//��ֹ����
//��������
//ע��ȥ�أ�����������set��ʱ��
//�ܽ���ɣ��������Ժ�����ظ��������ǵ�һ�����Բ�����������ǵ�n������ǰ������ֶ��Ѿ�ʹ���ˣ���������������
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true��˵��ͬһ��֧candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            // Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // ��39.����ܺ͵�����1��������i+1��ÿ��������ÿ�������ֻ��ʹ��һ��
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // ���ȰѸ�candidates����������ͬ��Ԫ�ض�����һ��
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};