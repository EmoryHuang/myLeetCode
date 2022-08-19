/*
 * @Descroption: 剑指 Offer 40. 最小的k个数
 * @Author: EmoryHuang
 * @Date: 2021-07-12 21:00:48
 * @解题思路:
 * 方法一：排序
 * 直接排序选取前 k 个元素
 * 方法二：堆
 * 建立堆，使堆中元素小于 k
 * 方法三：二分思想
 * 小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边
 */

class Solution {
   public:
    // 方法一：排序
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     sort(arr.begin(), arr.end());
    //     return vector<int>(arr.begin(), arr.begin() + k);
    // }

    // 方法二：堆
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     priority_queue<int> q;
    //     for (int num : arr) {
    //         q.push(num);
    //         if (q.size() > k) q.pop();
    //     }
    //     vector<int> ans;
    //     for (int i = 0; i < k; i++) {
    //         ans.push_back(q.top());
    //         q.pop();
    //     }
    //     return ans;
    // }

    // 方法三：二分思想
    int partition(vector<int> &arr, int l, int r) {
        // 随机划分
        int i = rand() % (r - l + 1) + l;
        swap(arr[l], arr[i]);
        int pivot = arr[l];
        int left = l, right = r;
        while (left < right) {
            while (left < right && arr[right] >= pivot) right--;
            while (left < right && arr[left] <= pivot) left++;
            if (left < right) swap(arr[left], arr[right]);
        }
        swap(arr[left], arr[l]);
        return left;
    }
    void selected(vector<int> &arr, int l, int r, int k) {
        if (l >= r) return;
        int pos = partition(arr, l, r);
        if (k == pos)
            return;
        else if (k > pos)
            selected(arr, pos + 1, r, k);
        else
            selected(arr, l, pos - 1, k);
    }
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        selected(arr, 0, arr.size() - 1, k);
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(arr[i]);
        return ans;
    }
};