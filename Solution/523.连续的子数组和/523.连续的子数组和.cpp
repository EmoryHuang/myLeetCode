/*
 * @Descroption: LeetCode 523. �������������
 * @Author: EmoryHuang
 * @Date: 2021-06-02 11:45:00
 * @����˼·:
 * Ԥ����ǰ׺������ pre��Ȼ��ٶ� [i, j] �����ǵ�Ŀ�����䣬��ô�У�
 * sum[j] - sum[i - 1] = n * k
 * Ҫʹ�����߳� k ���Ϊ��������Ҫ���� sum[j] �� sum[i - 1] �� k ȡ����ͬ
 *
 * ʹ�ù�ϣ������ֹ�������
 * �����ǰ�����ڹ�ϣ�����Ѿ����ڣ������������С����Ϊ 2�������
 * �����ǰ�����ڹ�ϣ���в����ڣ��򽫵�ǰ�����͵�ǰ�±� i �ļ�ֵ�Դ����ϣ����
 */

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = (pre + nums[i]) % k;  // ǰ׺�͵�����
            // ����ͬ��ǰ׺�ͣ������������С����Ϊ 2
            if (mp.count(pre) != 0 && i - mp[pre] > 1)
                return true;
            else if (mp.count(pre) == 0)
                mp[pre] = i;  // ��¼��������״γ��ֵ�λ��
        }
        return false;
    }
};