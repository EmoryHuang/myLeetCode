/*
 * @Descroption: LeetCode 3. ���ظ��ַ�����Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-03-16 19:20:36
 * @����˼·: �������ڵ�˼��
 *          ������������ָ�룬�̶���ָ�룬�ƶ���ָ�룬ͨ����ָ�벻�Ͻ��ַ����뵽������
 *          �����������и��ַ����������ƶ���ָ�룬����ߵ�Ԫ���Ƴ�����¼����ظ��Ӵ��ĳ��ȣ�֮���ظ��������̼���
 */

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;  //��
        unordered_set<char> st;
        int left = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {  //������ָ��λ��
            //�жϵ�ǰ�ַ��Ƿ��ڼ�����
            while (st.find(s[i]) != st.end()) {  //�������ʧ�ܻ᷵��end(),�����������޸�Ԫ��
                st.erase(s[left]);               //�������Ѿ��и�Ԫ�أ��ƶ���ָ��
                left++;                          //��ָ�������ƶ�
            }
            ans = max(ans, i - left + 1);  //ȡ���ֵ
            st.insert(s[i]);               // s[i]�����ظ�Ԫ�أ����뼯��
        }
        return ans;
    }
};