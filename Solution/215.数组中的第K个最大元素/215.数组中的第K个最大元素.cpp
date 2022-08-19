/*
 * @Descroption: LeetCode 215. �����еĵ� K �����Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:40:36
 * @����˼·:
 * ֱ���� sort()���Լ�������ķ����Ͳ�˵��
 *
 * �������ÿ������򻮷ֵ�˼�룬��������л��֣�ֻҪĳ�λ��ֵ� q Ϊ������ k ���±��ʱ��
 * ���Ѿ��ҵ��˴𰸣��������ǰ�벿�ֻ��벿�ֽ���Ѱ��
 *
 * �ڶ��ַ�����ͨ�����ȶ��� (С����)��ʼ�մ����ǰ k ���Ԫ�أ�
 * ÿ�����һ��Ԫ�غ󣬶���Ҫ�жϵ�ǰ���ȶ����е�Ԫ�ظ����Ƿ���� k
 * ��С�ڻ���� k���������ӣ������� k����ʱ��Ҫ���Ѷ�Ԫ�س���
 */

class Solution {
   public:
    // ����һ������˼��
    int quickFind(vector<int>& nums, int left, int right, int k) {
        int keyPos = left + rand() % (right - left);  //��ʼ���λ��
        swap(nums[keyPos], nums[left]);
        int start = left, end = right - 1, key = nums[left];
        while (start < end) {
            while (start < end && nums[end] >= key) end--;
            nums[start] = nums[end];
            while (start < end && nums[start] <= key) start++;
            nums[end] = nums[start];
        }
        nums[start] = key;       // start Ϊ����λ��
        if (start == right - k)  //�ҵ��� k ��
            return nums[start];
        else if (start > right - k)
            return quickFind(nums, left, start, k - (right - start));  //��ǰ�벿��
        else
            return quickFind(nums, start + 1, right, k);  //�ں�벿��
    }
    int findKthLargest(vector<int>& nums, int k) { return quickFind(nums, 0, nums.size(), k); }

    // �����������ȶ��� (С����)
    // int findKthLargest(vector<int>& nums, int k) {
    //     int len = nums.size();
    //     if (len == 0 || k > len) return 0;
    //     priority_queue<int, vector<int>, greater<int>> st;
    //     for (int i = 0; i < len; i++) {
    //         st.push(nums[i]);
    //         if (st.size() > k) st.pop();  //������k��Ԫ���򵯳�
    //     }
    //     return st.top();  //ȡ�Ѷ�Ԫ��
    // }
};