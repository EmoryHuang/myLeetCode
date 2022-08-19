/*
 * @Descroption: LeetCode 380. O(1) ʱ����롢ɾ���ͻ�ȡ���Ԫ��
 * @Author: EmoryHuang
 * @Date: 2022-04-13 08:52:57
 * @Method:
 * ���� + ��ϣ��
 * ����洢Ԫ�أ���ϣ��洢��Ӧ���±�
 * ɾ������ʱ���䳤��������һ��Ԫ���ƶ�����ɾ��Ԫ�ص��±괦��Ȼ��ɾ���䳤��������һ��Ԫ�ء�
 */

class RandomizedSet {
   public:
    vector<int> nums;
    unordered_map<int, int> hash;
    RandomizedSet() {}

    bool insert(int val) {
        if (hash.count(val) != 0) return false;
        hash[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (hash.count(val) == 0) return false;
        int index = hash[val];
        int last = nums.back();
        nums[index] = last;
        hash[nums[index]] = index;
        nums.pop_back();
        hash.erase(val);
        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */