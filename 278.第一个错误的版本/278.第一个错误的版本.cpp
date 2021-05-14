/*
 * @Descroption: LeetCode 278. ��һ������İ汾
 * @Author: EmoryHuang
 * @Date: 2021-05-10 17:54:36
 * @����˼·:
 * ���ַ�Ѱ����˵�
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};