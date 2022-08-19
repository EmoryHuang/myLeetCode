/*
 * @Descroption: LeetCode 605. 种花问题
 * @Author: EmoryHuang
 * @Date: 2021-04-28 14:00:36
 * @解题思路:
 * 在首尾插入 0，避免对首尾单独讨论，只需要寻找连续 3 个 0 即可
 */

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);  // 首尾插入0
        flowerbed.insert(flowerbed.end(), 0);
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {  // 连续3个0
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};