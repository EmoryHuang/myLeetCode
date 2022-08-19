/*
 * @Descroption: LeetCode 380. O(1) 时间插入、删除和获取随机元素
 * @Author: EmoryHuang
 * @Date: 2022-04-13 08:52:57
 * @Method:
 * 数组 + 哈希表
 * 数组存储元素，哈希表存储对应的下标
 * 删除操作时将变长数组的最后一个元素移动到待删除元素的下标处，然后删除变长数组的最后一个元素。
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