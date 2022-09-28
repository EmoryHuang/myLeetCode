/*
 * @Descroption: LeetCode 905. 按奇偶排序数组
 * @Author: EmoryHuang
 * @Date: 2021-04-27 13:59:36
 * @解题思路:
 * 遍历一遍，设置指针，采用交换的思想，将偶数元素放到前面
 */

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        for (int j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) {
                swap(A[i], A[j]);
                i++;
            }
        return A;
    }
};