/*
 * @Descroption: LeetCode 3. 无重复字符的最长子串
 * @Author: EmoryHuang
 * @Date: 2021-03-16 19:20:36
 * @解题思路: 滑动窗口的思想
 *          创建左右两个指针，固定左指针，移动右指针，通过右指针不断将字符加入到集合中
 *          若集合中已有该字符，则向右移动左指针，将左边的元素移出，记录最长无重复子串的长度，之后重复上述过程即可
 */

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;  //空
        unordered_set<char> st;
        int left = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {  //遍历右指针位置
            //判断当前字符是否在集合内
            while (st.find(s[i]) != st.end()) {  //如果查找失败会返回end(),表明集合中无该元素
                st.erase(s[left]);               //集合中已经有该元素，移动左指针
                left++;                          //左指针向右移动
            }
            ans = max(ans, i - left + 1);  //取最大值
            st.insert(s[i]);               // s[i]不是重复元素，加入集合
        }
        return ans;
    }
};