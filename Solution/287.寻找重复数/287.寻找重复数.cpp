/*
 * @Descroption: LeetCode 287. Ѱ���ظ���
 * @Author: EmoryHuang
 * @Date: 2021-05-22 15:38:00
 * @����˼·:
 * ����һ����ϣ��
 *
 * ������������ָ��
 * ��Ϊ���ظ����ֵĳ���, ����������߱�Ȼ�ǳɻ���,
 * ������ھ����ظ���Ԫ��, ������Ѱ��������ڵ�˼·����
 */

class Solution {
   public:
    // ����һ����ϣ��
    // int findDuplicate(vector<int>& nums) {
    //     map<int, int> mp;
    //     for (int num : nums) {
    //         mp[num]++;
    //         if (mp[num] == 2) return num;
    //     }
    //     return -1;
    // }

    // ������������ָ��
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                slow = 0;
                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return slow;
            }
        }
    }
};