/*
 * @Descroption: LeetCode 282. �����ʽ��������
 * @Author: EmoryHuang
 * @Date: 2021-10-16 09:23:55
 * @Method:
 * ����
 * ʹ�û��ݿ������п��ܵĲ����������� '+', '-', '*'
 * ����˷�ʱ���������ȼ������⣬��Ҫ��¼��һ���Ĳ�������ʹ�� pre ��¼
 */

class Solution {
   public:
    vector<string> ans;
    int n;
    void dfs(string path, int idx, long long cur, long long pre, string num, int target) {
        if (idx == n) {
            if (cur == target) ans.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++) {
            // ���ֲ����� 0 ��ͷ
            if (num[idx] == '0' && i > idx) break;
            // �����õ����ܵ�����
            string c = num.substr(idx, i - idx + 1);
            long long numc = stoll(c);
            if (idx == 0)
                dfs(path + c, i + 1, numc, numc, num, target);
            else {
                dfs(path + '+' + c, i + 1, cur + numc, numc, num, target);
                dfs(path + '-' + c, i + 1, cur - numc, -numc, num, target);
                // ����˷�ʱ���������ȼ������⣬��Ҫ��¼��һ���Ĳ�������ʹ�� pre ��¼
                dfs(path + '*' + c, i + 1, cur - pre + pre * numc, pre * numc, num, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        n = num.size();
        dfs("", 0, 0, 0, num, target);
        return ans;
    }
};