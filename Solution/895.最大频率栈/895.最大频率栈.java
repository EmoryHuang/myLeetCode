/*
 * @Descroption: LeetCode 895. 最大频率栈
 * @Author: EmoryHuang
 * @Date: 2022-11-30 09:33:50
 * @Method:
 * 使用两个哈希表分别存储每个数字出现的频率以及每个频率的数字
 */

class FreqStack {
    Map<Integer, Integer> freq;
    Map<Integer, Deque<Integer>> group;
    int maxFreq;

    public FreqStack() {
        freq = new HashMap<Integer, Integer>();
        group = new HashMap<Integer, Deque<Integer>>();
        maxFreq = 0;
    }

    public void push(int val) {
        freq.put(val, freq.getOrDefault(val, 0) + 1);
        group.putIfAbsent(freq.get(val), new ArrayDeque<>());
        group.get(freq.get(val)).push(val);
        maxFreq = Math.max(maxFreq, freq.get(val));
    }

    public int pop() {
        int val = group.get(maxFreq).peek();
        freq.put(val, freq.get(val) - 1);
        group.get(maxFreq).pop();
        if (group.get(maxFreq).isEmpty()) {
            maxFreq--;
        }
        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */