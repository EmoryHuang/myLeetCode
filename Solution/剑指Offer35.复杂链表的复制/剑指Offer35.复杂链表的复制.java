/*
 * @Descroption: 剑指 Offer 35. 复杂链表的复制
 * @Author: EmoryHuang
 * @Date: 2023-07-24 09:50:40
 * @Method:
 * 回溯 + 哈希表
 * 使用哈希表存储出现过的节点
 * 如果当前节点已经被拷贝过，那么就直接返回
 * 如果当前节点的 next 和 random 都没有被创建，就递归地进行创建
 */

import java.util.*;

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    Map<Node, Node> cache = new HashMap<>();

    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        if (!cache.containsKey(head)) {
            Node copy = new Node(head.val);
            cache.put(head, copy);
            copy.next = copyRandomList(head.next);
            copy.random = copyRandomList(head.random);
        }
        return cache.get(head);
    }
}