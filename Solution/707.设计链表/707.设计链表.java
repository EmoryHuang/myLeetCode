/*
 * @Descroption: LeetCode 707. 设计链表
 * @Author: EmoryHuang
 * @Date: 2022-09-23 09:37:55
 * @Method:
 * 链表的基础操作
 */

import java.util.*;

class LinkNode {
    int val;
    LinkNode next;

    public LinkNode(int val) {
        this.val = val;
    }
}

class MyLinkedList {
    int size;
    LinkNode head;

    public MyLinkedList() {
        size = 0;
        head = new LinkNode(0);
    }

    public int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        LinkNode cur = head;
        for (int i = 0; i <= index; i++)
            cur = cur.next;
        return cur.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > size)
            return;
        size++;
        index = index < 0 ? 0 : index;
        LinkNode pred = head;
        for (int i = 0; i < index; i++)
            pred = pred.next;
        LinkNode add = new LinkNode(val);
        add.next = pred.next;
        pred.next = add;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        size--;
        LinkNode pred = head;
        for (int i = 0; i < index; i++)
            pred = pred.next;
        pred.next = pred.next.next;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */