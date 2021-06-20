/*
 * @Descroption: LeetCode 1600. ��λ�̳�˳��
 * @Author: EmoryHuang
 * @Date: 2021-06-20 12:34:00
 * @����˼·:
 * ʹ�ö�����ķ�ʽ�洢������ϵ��
 * �� kingName ��Ϊ���ڵ㣬ÿ�����һ���� parentName �� childName �ı�
 * ʹ�� set ��¼��������
 * ����ʱ��ʹ��ǰ������ķ�ʽ���ң�
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