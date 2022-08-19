/*
 * @Descroption: LeetCode 1700. 无法吃午餐的学生数量
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:14:31
 * @解题思路:
 * 哈希表记录喜欢吃每种三明治的学生数
 * 按顺序遍历三明治数组，把对应的三明治分给喜欢的学生
 * 当前的三明治没有学生喜欢，那么就得到答案了
 */

class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnt(2);
        for (int student : students) cnt[student]++;  // 吃每种三明治的学生数
        for (int sandwich : sandwiches) {
            if (cnt[sandwich] > 0)  // 有喜欢吃当前三明治的学生
                cnt[sandwich]--;
            else
                break;
        }
        return cnt[0] + cnt[1];
    }
};