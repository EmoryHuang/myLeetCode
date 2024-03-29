/*
 * @Descroption: LeetCode 341. 扁平化嵌套列表迭代器
 * @Author: EmoryHuang
 * @Date: 2021-03-23 09:50:36
 * @解题思路: 题目的意思就是列表的嵌套，还要用它给的函数，DFS 即可
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
   public:
    vector<int> ans;
    int index = 0;
    NestedIterator(vector<NestedInteger> &nestedList) { DFS(nestedList); }

    int next() { return ans[index++]; }

    bool hasNext() {
        if (index == ans.size())
            return false;
        else
            return true;
    }

    void DFS(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger())
                ans.push_back(nestedList[i].getInteger());  //若为整数则加入
            else
                DFS(nestedList[i].getList());  //若不是整数则继续DFS
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */