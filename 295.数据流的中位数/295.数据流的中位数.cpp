/*
 * @Descroption: LeetCode 295. ����������λ��
 * @Author: EmoryHuang
 * @Date: 2021-08-27 13:41:18
 * @Method:
 * ʹ���������ȶ��У��ѣ���ά���������������ݣ�
 * ά���������������ݵ����ȶ��У��ѣ�Ϊ l��ά���������Ұ�����ݵ����ȶ��У��ѣ�Ϊ r
 * l Ϊ����ѣ�r ΪС����
 * ��������Ԫ������Ϊż����l �� r ��С��ͬ����ʱ��̬��λ��Ϊ���߶Ѷ�Ԫ�ص�ƽ��ֵ��
 * ��������Ԫ������Ϊ������l �� r ��һ����ʱ��̬��λ��Ϊ l �ĶѶ�ԭ����
 */

class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int> l;                             // �����
    priority_queue<int, vector<int>, greater<int>> r;  // С����
    MedianFinder() {}

    void addNum(int num) {
        // ���lΪ�գ�����numС�ڵ�����벿�����ֵ
        if (l.empty() || l.top() >= num) {
            l.push(num);
            // �����Ҳ��ֵ��������ָ�������1
            if (r.size() + 1 < l.size()) {
                // ����벿�ֵ����ֵ�ŵ��Ұ벿��
                r.push(l.top());
                l.pop();
            }
        } else {
            r.push(num);
            if (r.size() > l.size()) {
                l.push(r.top());
                r.pop();
            }
        }
    }

    double findMedian() {
        if (l.size() == r.size()) return (l.top() + r.top()) / 2.0;
        return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */