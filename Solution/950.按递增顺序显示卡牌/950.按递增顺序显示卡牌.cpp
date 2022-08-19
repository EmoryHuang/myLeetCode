/*
 * @Descroption: LeetCode 950. 按递增顺序显示卡牌
 * @Author: EmoryHuang
 * @Date: 2021-06-04 14:40:00
 * @解题思路:
 * 按照模拟的方法，对于题目给我们的规则，可以倒着思考
 * 从大到小对卡牌进行排序
 * 首先将最大的节点放入卡堆（此时卡堆只有一张牌），然后将卡堆底部的牌放到顶部
 * 然后再在卡堆的顶部放上下一张牌
 * 这样，在按照题目规则进行的时候，我们就可以得到递增顺序的卡牌
 */

class Solution {
   public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> q;
        q.push_back(deck.back());  // 最大的节点
        for (int i = n - 2; i >= 0; i--) {
            q.push_front(q.back());  // 队尾元素放到队头
            q.pop_back();
            q.push_front(deck[i]);  // 加入下一个元素
        }
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};