/*
 * @Descroption: LeetCode 229. ������ II
 * @Author: EmoryHuang
 * @Date: 2021-10-22 09:19:40
 * @Method:
 * ����һ����ϣ��
 * ʹ�ù�ϣ���¼Ԫ������
 *
 * ��������Ħ��ͶƱ��
 * �� 169. ����Ԫ�� ����
 * ���ִ������� n / k �������ֻ�� k - 1 ��
 *
 * Ħ��ͶƱ��: ÿ�δ�������ѡ����������ͬ������ɾ���������Ϊ������������
 * ���ʣ��һ�����ֻ򼸸���ͬ�����֣����ǳ��ִ��������ܡ���������һ����Ǹ�
 */

class Solution {
   public:
    // ����һ����ϣ��
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans;
    //     unordered_map<int, int> hash;
    //     for (int num : nums) hash[num]++;
    //     unordered_map<int, int>::iterator it = hash.begin();
    //     for (; it != hash.end(); it++)
    //         if (it->second > n / 3) ans.push_back(it->first);
    //     return ans;
    // }

    // ��������Ħ��ͶƱ��
    vector<int> majorityElement(vector<int>& nums) {
        // ���ִ������� n / k �������ֻ�� k - 1 ��
        int a = 0, b = 0;
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (c1 != 0 && num == a)
                c1++;
            else if (c2 != 0 && num == b)
                c2++;
            else if (c1 == 0)
                a = num, c1++;
            else if (c2 == 0)
                b = num, c2++;
            else
                c1--, c2--;
        }
        // �ٽ���һ�α��������
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == a)
                c1++;
            else if (num == b)
                c2++;
        }
        vector<int> ans;
        if (c1 > nums.size() / 3) ans.push_back(a);
        if (c2 > nums.size() / 3) ans.push_back(b);
        return ans;
    }
};