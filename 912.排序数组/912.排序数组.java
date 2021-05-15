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
        int left = 2 * i + 1; // ����
        int right = 2 * i + 2; // �Һ���
        int max = i;
        // Ѱ�����ֵ
        if (left < n && nums[left] > nums[max])
            max = left;
        if (right < n && nums[right] > nums[max])
            max = right;
        if (max != i) { // �����ڵ㲻�����Ԫ��
            swap(nums, i, max); // ����
            Heapify(nums, max, n); // ������
        }
    }

    public int[] sortArray(int[] nums) {
        HeapSort(nums);
        return nums;
    }
}