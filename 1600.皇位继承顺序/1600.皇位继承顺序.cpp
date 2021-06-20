/*
 * @Descroption: LeetCode 1600. 皇位继承顺序
 * @Author: EmoryHuang
 * @Date: 2021-06-20 12:34:00
 * @解题思路:
 * 使用多叉树的方式存储亲属关系，
 * 以 kingName 作为根节点，每次添加一条从 parentName 到 childName 的边
 * 使用 set 记录死亡的人
 * 查找时，使用前序遍历的方式查找，
 */

class ThroneInheritance {
   public:
    string king;
    set<string> st;
    map<string, vector<string>> mp;
    ThroneInheritance(string kingName) { king = kingName; }

    void birth(string parentName, string childName) { mp[parentName].push_back(childName); }

    void death(string name) { st.insert(name); }

    void preorder(vector<string> &ans, string name) {
        if (st.count(name) == 0) ans.push_back(name);
        if (mp.count(name) != 0)
            for (auto childname : mp[name]) preorder(ans, childname);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        preorder(ans, king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */