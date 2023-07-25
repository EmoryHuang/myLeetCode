/*
 * @Descroption: LeetCode 1268. 搜索推荐系统
 * @Author: EmoryHuang
 * @Date: 2023-07-22 10:13:15
 * @Method:
 * 前缀树
 */

import java.util.*;

class Solution {
    class Trie {
        Trie[] children;
        boolean isEnd;
        PriorityQueue<String> queue;

        public Trie() {
            children = new Trie[26];
            queue = new PriorityQueue<>((o1, o2) -> o2.compareTo(o1));
        }
    }

    Trie root;
    List<List<String>> ans;

    void insert(String word) {
        Trie node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (node.children[index] == null) {
                node.children[index] = new Trie();
            }
            node = node.children[index];
            node.queue.offer(word);
            if (node.queue.size() > 3) {
                node.queue.poll();
            }
        }
        node.isEnd = true;
    }

    void search(String prefix) {
        Trie node = root;
        boolean exist = true;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix.charAt(i) - 'a';
            if (!exist || node.children[index] == null) {
                exist = false;
                ans.add(new ArrayList<>());
                continue;
            }
            node = node.children[index];
            List<String> tmp = new ArrayList<>();
            while (!node.queue.isEmpty()) {
                tmp.add(node.queue.poll());
            }
            Collections.reverse(tmp);
            ans.add(tmp);
        }
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        root = new Trie();
        ans = new ArrayList<>();
        for (String s : products) {
            insert(s);
        }
        search(searchWord);
        return ans;
    }
}