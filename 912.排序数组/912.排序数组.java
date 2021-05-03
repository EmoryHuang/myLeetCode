class Solution {
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void HeapSort(int[] nums) {
        int n = nums.length;
        BuildMaxHeap(nums, n);
        for (int i = n - 1; i > 0; i--) {
            swap(nums, 0, i);
            n--;
            Heapify(nums, 0, n);
        }
    }

    public void BuildMaxHeap(int[] nums, int n) {
        for (int i = n / 2-1; i >= 0; i--)
            Heapify(nums, i, n);
    }

    public void Heapify(int[] nums, int i, int n) {
        int left = 2 * i + 1; // 左孩子
        int right = 2 * i + 2; // 右孩子
        int max = i;
        // 寻找最大值
        if (left < n && nums[left] > nums[max])
            max = left;
        if (right < n && nums[right] > nums[max])
            max = right;
        if (max != i) { // 若根节点不是最大元素
            swap(nums, i, max); // 交换
            Heapify(nums, max, n); // 调整堆
        }
    }

    public int[] sortArray(int[] nums) {
        HeapSort(nums);
        return nums;
    }
}