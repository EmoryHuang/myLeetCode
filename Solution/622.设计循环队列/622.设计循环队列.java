/*
 * @Descroption: LeetCode 622. 设计循环队列
 * @Author: EmoryHuang
 * @Date: 2022-08-03 09:17:23
 * @Method:
 * 数组模拟队列
 * 标记队列的头尾
 */

class MyCircularQueue {

  int front = 0, rear = 0;
  int[] queue;

  public MyCircularQueue(int k) {
    queue = new int[k + 1];
  }

  public boolean enQueue(int value) {
    if (isFull()) return false;
    queue[rear] = value;
    rear = (rear + 1) % queue.length;
    return true;
  }

  public boolean deQueue() {
    if (isEmpty()) return false;
    front = (front + 1) % queue.length;
    return true;
  }

  public int Front() {
    if (isEmpty()) return -1;
    return queue[front];
  }

  public int Rear() {
    if (isEmpty()) return -1;
    return queue[(rear - 1 + queue.length) % queue.length];
  }

  public boolean isEmpty() {
    return front == rear;
  }

  public boolean isFull() {
    return (rear + 1) % queue.length == front;
  }
}
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */