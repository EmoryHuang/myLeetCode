/*
 * @Descroption: LeetCode 641. 设计循环双端队列
 * @Author: EmoryHuang
 * @Date: 2022-08-15 10:02:33
 * @Method:
 * 数组模拟双端队列
 */


class MyCircularDeque {
    int[] q;
    int front = 0, rear = 0;
    int size;

    public MyCircularDeque(int k) {
        q = new int[k + 1];
        size = k + 1;
    }

    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + size) % size;
        q[front] = value;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }
        q[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + size) % size;
        return true;
    }

    public int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    public int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return q[(rear - 1 + size) % size];
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        return front == (rear + 1) % size;
    }
}
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
