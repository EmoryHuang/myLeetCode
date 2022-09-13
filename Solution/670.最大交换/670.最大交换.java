/*
 * @Descroption: LeetCode 670. 最大交换
 * @Author: EmoryHuang
 * @Date: 2022-09-13 10:31:30
 * @Method:
 * 方法一：暴力遍历
 * 寻找当前字符后面的最大值，若最大值不为当前字符，则进行交换
 * 
 * 方法二：贪心
 * 从右向左遍历，将右边较大的数字与左边较小的数字交换
 */


class Solution {
    // 方法一：暴力遍历
    // public int maximumSwap(int num) {
    //     char[] ch = String.valueOf(num).toCharArray();
    //     int n = ch.length;
    //     int max = num;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             swap(ch, i, j);
    //             max = Math.max(max, Integer.parseInt(new String(ch)));
    //             swap(ch, i, j);
    //         }
    //     }
    //     return max;
    // }

    // 方法二：贪心
    public int maximumSwap(int num) {
        char[] ch = String.valueOf(num).toCharArray();
        int n = ch.length;
        int maxid = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (ch[i] > ch[maxid]) {
                maxid = i;
            } else if (ch[i] < ch[maxid]) {
                idx1 = i;
                idx2 = maxid;
            }
        }
        if (idx1 >= 0) {
            swap(ch, idx1, idx2);
            return Integer.parseInt(new String(ch));
        } else
            return num;
    }

    public void swap(char[] charArray, int i, int j) {
        char tmp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = tmp;
    }
}