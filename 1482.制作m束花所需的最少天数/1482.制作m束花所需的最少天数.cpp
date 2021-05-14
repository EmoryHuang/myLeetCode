class Solution {
   public:
    bool makeBloom(vector<int>& bloomDay, int day, int m, int k) {
        int bloom = 0;  // ��������
        int num = 0;    // ����������
        for (int i = 0; i < bloomDay.size() && num < m; i++) {
            if (bloomDay[i] <= day) {
                bloom++;  // ����
                if (bloom == k) {
                    num++;
                    bloom = 0;
                }
            } else  // ���������Ļ�
                bloom = 0;
        }
        return num >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            int day = low + (high - low) / 2;
            if (makeBloom(bloomDay, day, m, k))  //��� day ���ܹ����� m �仨
                high = day;                      //�������Ҹ�С��ֵ
            else
                low = day + 1;
        }
        return low;
    }
};