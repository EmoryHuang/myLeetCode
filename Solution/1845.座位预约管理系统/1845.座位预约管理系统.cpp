/*
 * @Descroption: LeetCode 1845. ��λԤԼ����ϵͳ
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:03:49
 * @����˼·:
 * ����С�Ѵ洢��λ��Ԥ��ʱ�����Ѷ�Ԫ�أ�ȡ��ʱ�����Ӧ��λ��
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class SeatManager {
   public:
    priority_queue<int, vector<int>, greater<int>> q;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) q.push(i);
    }

    int reserve() {
        int ans = q.top();
        q.pop();
        return ans;
    }

    void unreserve(int seatNumber) { 
        q.push(seatNumber); 
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */