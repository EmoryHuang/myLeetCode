/*
 * @Descroption: ��ָ Offer 40. ��С��k����
 * @Author: EmoryHuang
 * @Date: 2021-07-12 21:00:48
 * @����˼·:
 * ����һ������
 * ֱ������ѡȡǰ k ��Ԫ��
 * ����������
 * �����ѣ�ʹ����Ԫ��С�� k
 * ������������˼��
 * С�ڵ��ڷֽ�ֵ pivot ��Ԫ�صĶ��ᱻ�ŵ��������ߣ����ڵĶ��ᱻ�ŵ�������ұ�
 */

class Solution {
   public:
    // ����һ������
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     sort(arr.begin(), arr.end());
    //     return vector<int>(arr.begin(), arr.begin() + k);
    // }

    // ����������
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

    // ������������˼��
    int partition(vector<int> &arr, int l, int r) {
        // �������
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