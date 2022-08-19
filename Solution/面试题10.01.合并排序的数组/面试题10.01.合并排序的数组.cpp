/*
 * @Descroption: 面试题 10.01. 合并排序的数组
 * @Author: EmoryHuang
 * @Date: 2021-07-18 15:05:28
 * @解题思路:
 * 一个简单的方法就是将数组 B 放进数组 A 的尾部，然后直接排序
 * 再进一步的话可以使用双指针，从左向右比较数组中元素的大小，将元素放到新的数组中
 * 当然，由于 A 后面有足够的空间，因此可以使用逆向双指针
 */

class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i == -1)
                A[tail--] = B[j--];
            else if (j == -1)
                A[tail--] = A[i--];
            else if (A[i] > B[j])
                A[tail--] = A[i--];
            else
                A[tail--] = B[j--];
        }
    }
};