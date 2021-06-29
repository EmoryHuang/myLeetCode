/*
 * @Descroption: ��ָ Offer 11. ��ת�������С����
 * @Author: EmoryHuang
 * @Date: 2021-06-29 20:39:00
 * @����˼·:
 * ���ַ�
 * ����м��Ԫ�ر��ұߵ�Ԫ��С����ô���㣬�� r = mid����Ϊ mid ��������СԪ��
 * ����м��Ԫ�ر��ұߵ�Ԫ�ش���ô�� l = mid + 1����Ϊ mid ����������СԪ��
 * ����м��Ԫ�ص����ұߵ�Ԫ�أ���ô�� r--����С��Χ
 */

class Solution {
   public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (numbers[mid] < numbers[r])
                r = mid;
            else if (numbers[mid] > numbers[r])
                l = mid + 1;
            else
                r--;
        }
        return numbers[l];
    }
};