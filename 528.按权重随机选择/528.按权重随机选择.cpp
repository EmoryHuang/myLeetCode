/*
 * @Descroption: LeetCode 528. ��Ȩ�����ѡ��
 * @Author: EmoryHuang
 * @Date: 2021-08-30 22:10:30
 * @Method:
 * ǰ׺�� + ����
 * ÿ��Ԫ�ش���һ��Ȩ�أ�����Խ���Ԫ�أ�����Ȩ��Խ��
 * ����ʹ��ǰ׺����������ΪȨ�طֲ�����
 * �������ǰ׺�������в���
 * ͨ�������������ٶ�λ��������±꼴��
 */

class Solution {
   public:
    vector<int> pre;
    Solution(vector<int>& w) {
        pre.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) pre.push_back(pre.back() + w[i]);
    }

    int pickIndex() {
        int n = pre.size();
        int seed = rand() % pre.back();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (pre[mid] > seed)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */