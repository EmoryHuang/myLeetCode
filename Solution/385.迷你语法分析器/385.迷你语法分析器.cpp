/*
 * @Descroption: LeetCode 385. �����﷨������
 * @Author: EmoryHuang
 * @Date: 2022-04-15 09:07:05
 * @Method:
 * dfs
 * ʹ�� deep ��¼��ǰ����λ�õ���ȣ�ÿ�����������ţ���ȼ� 1�����������ţ���ȼ� 1
 * start ��¼��ʼλ�ã��� start ����ǰλ��֮����ַ���ȡ�����ݹ���ú���
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
   public:
    NestedInteger deserialize(string s) {
        // ���Ϊ����ֱ�ӷ���
        if (s.empty()) return NestedInteger();
        // ���ֻ��һ��
        if (s[0] != '[') return NestedInteger(stoi(s));
        // ���Ϊ [] �򷵻ؿ�
        if (s.size() <= 2) return NestedInteger();
        // deep ��¼���
        int start = 1, deep = 0;
        NestedInteger ans;
        for (int i = 1; i < s.size(); i++) {
            if (deep == 0 && (s[i] == ',' || i == s.size() - 1)) {
                ans.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            }
            else if (s[i] == '[') deep++;
            else if (s[i] == ']') deep--;
        }
        return ans;
    }
};