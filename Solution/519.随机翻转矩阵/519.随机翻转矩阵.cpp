/*
 * @Descroption: LeetCode 519. �����ת����
 * @Author: EmoryHuang
 * @Date: 2021-11-25 08:46:52
 * @Method:
 * ���ѡȡ������Ϊһά���������λ�ã�ʹ�ü��ϼ�¼��ת����Ԫ��λ�ã�����ѡ���λ���Ѿ������������ѡ��
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