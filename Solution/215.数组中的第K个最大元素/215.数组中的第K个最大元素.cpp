/*
 * @Descroption: LeetCode 215. 数组中的第 K 个最大元素
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:40:36
 * @解题思路:
 * 直接用 sort()，以及先排序的方法就不说了
 *
 * 这里利用快速排序划分的思想，对数组进行划分，只要某次划分的 q 为倒数第 k 个下标的时候，
 * 就已经找到了答案，否则就在前半部分或后半部分进行寻找
 *
 * 第二种方法是通过优先队列 (小根堆)，始终存放是前 k 大的元素，
 * 每添加完一个元素后，都需要判断当前优先队列中的元素个数是否大于 k
 * 若小于或等于 k，则继续添加；若大于 k，此时需要将堆顶元素出队
 */

class Solution {
   public:
    // 方法一：快排思想
    int quickFind(vector<int>& nums, int left, int right, int k) {
        int keyPos = left + rand() % (right - left);  //初始随机位置
        swap(nums[keyPos], nums[left]);
        int start = left, end = right - 1, key = nums[left];
        while (start < end) {
            while (start < end && nums[end] >= key) end--;
            nums[start] = nums[end];
            while (start < end && nums[start] <= key) start++;
            nums[end] = nums[start];
        }
        nums[start] = key;       // start 为划分位置
        if (start == right - k)  //找到第 k 大
            return nums[start];
        else if (start > right - k)
            return quickFind(nums, left, start, k - (right - start));  //在前半部分
        else
            return quickFind(nums, start + 1, right, k);  //在后半部分
    }
    int findKthLargest(vector<int>& nums, int k) { return quickFind(nums, 0, nums.size(), k); }

    // 方法二：优先队列 (小根堆)
    // int findKthLargest(vector<int>& nums, int k) {
    //     int len = nums.size();
    //     if (len == 0 || k > len) return 0;
    //     priority_queue<int, vector<int>, greater<int>> st;
    //     for (int i = 0; i < len; i++) {
    //         st.push(nums[i]);
    //         if (st.size() > k) st.pop();  //超过了k个元素则弹出
    //     }
    //     return st.top();  //取堆顶元素
    // }
};