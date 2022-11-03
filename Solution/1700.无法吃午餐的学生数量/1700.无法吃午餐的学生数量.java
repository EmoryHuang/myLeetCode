/*
 * @Descroption: LeetCode 1700. 无法吃午餐的学生数量
 * @Author: EmoryHuang
 * @Date: 2022-10-19 09:15:55
 * @Method:
 * 哈希表记录喜欢吃每种三明治的学生数
 * 按顺序遍历三明治数组，把对应的三明治分给喜欢的学生
 */


class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int s : students)
            cnt.put(s, cnt.getOrDefault(s, 0) + 1);
        for (int s : sandwiches) {
            if (cnt.getOrDefault(s, 0) > 0)
                cnt.put(s, cnt.get(s) - 1);
            else
                break;
        }
        return cnt.getOrDefault(1, 0) + cnt.getOrDefault(0, 0);
    }
}