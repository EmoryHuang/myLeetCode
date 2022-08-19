/*
 * @Descroption: LeetCode 1713. �õ������е����ٲ�������
 * @Author: EmoryHuang
 * @Date: 2021-07-26 13:46:49
 * @Method:
 * Ϊ�˵õ������е����ٲ���������������Ҫ�ĵõ����������е������������
 * �õ��������������֮�����Ǳ����ȷ��������Ҫ��ӵ�Ԫ������
 * ����target�л�����ͬ������֪��ÿ�����ֶ�Ӧ������Ψһ
 * ��������������еȼ���arr��target������ת���󹹳��������������
 */

class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> hash;
        // ��¼target��Ԫ�ص��±�λ��
        for (int i = 0; i < n; i++) hash[target[i]] = i;
        vector<int> com;
        for (int num : arr) {
            // ����ǹ���Ԫ��
            if (hash.find(num) != hash.end()) {
                // �õ����Ԫ����target�е��±�
                int ind = hash[num];
                auto pos = lower_bound(com.begin(), com.end(), ind);
                if (pos != com.end())
                    *pos = ind;
                else
                    com.push_back(ind);
            }
        }
        return n - com.size();
    }
};