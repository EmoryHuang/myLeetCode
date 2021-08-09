/*
 * @Descroption: LeetCode 1524. ��Ϊ��������������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-08-09 19:29:25
 * @Method:
 * ǰ׺��
 * ͳ�Ƶ�ǰǰ׺�͵���ǰ׺������ż���ĸ���
 * ���±� i ��λ�õ�ǰ׺����ż��ʱ����Ϊ�������������������Ϊ����ǰ׺�͵����� odd
 * ���±� i ��λ�õ�ǰ׺��������ʱ����Ϊ�������������������Ϊż��ǰ׺�͵����� even
 */

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        int ans = 0, sum = 0;
        for (int num : arr) {
            sum += num;
            ans = (ans + (sum % 2 == 0 ? odd : even)) % 1000000007;
            if (sum % 2 == 0)
                even++;
            else
                odd++;
        }
        return ans % 1000000007;
    }
};