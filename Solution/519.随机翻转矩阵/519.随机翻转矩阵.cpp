/*
 * @Descroption: LeetCode 519. 随机翻转矩阵
 * @Author: EmoryHuang
 * @Date: 2021-11-25 08:46:52
 * @Method:
 * 随机选取数字作为一维数组的索引位置，使用集合记录翻转过的元素位置，如新选择的位置已经处理过，继续选数
 */

class Solution {
   public:
    int _m, _n;
    unordered_set<int> set;
    Solution(int m, int n) {
        _m = m;
        _n = n;
    }

    vector<int> flip() {
        int index = rand() % (_m * _n);
        while (set.find(index) != set.end()) {
            index = rand() % (_m * _n);
        }
        set.insert(index);
        return {index / _n, index % _n};
    }

    void reset() { set.clear(); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */