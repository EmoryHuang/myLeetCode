/*
 * @Descroption: LeetCode 68. 文本左右对齐
 * @Author: EmoryHuang
 * @Date: 2021-09-09 19:53:55
 * @Method:
 * 模拟
 * 维护每行的单词，一直往 row 中添加单词，直到不能添加为止
 * 若是最后一行，则左对齐；若这一行只有一个单词，则左对齐
 * 若是其他情况，计算出 当前行空格长度spaceWidth，当前行单词个数cnt
 * 单词平均间隔 avgSpace = spaceWidth // (cnt - 1)
 * 额外单词间隔 extraSpace = spaceWidth % (cnt - 1)
 * 我们只需要在前 extraSpace 个单词添加 avgSpace + 1 个空格
 */

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), i = 0;
        vector<string> ans;
        while (i < n) {
            vector<string> row;
            // 向 row 中填充单词
            int cur = words[i].size();
            row.push_back(words[i++]);
            // 一直往 row 中添加单词，直到不能添加为止
            // 注意单词之间有空格，需要加 1
            while (i < n && cur + 1 + words[i].size() <= maxWidth) {
                cur += 1 + words[i].size();
                row.push_back(words[i++]);
            }

            // 若是最后一行，则左对齐
            if (i == n) {
                string s, tmp;
                for (int j = 0; j < row.size() - 1; j++) tmp += row[j] + ' ';
                tmp += row.back();
                s = tmp + string(maxWidth - tmp.size(), ' ');
                ans.push_back(s);
                break;
            }
            // 若这一行只有一个单词，则左对齐
            int cnt = row.size();
            if (cnt == 1) {
                string s;
                s += row[0] + string(maxWidth - row[0].size(), ' ');
                ans.push_back(s);
                continue;
            }

            // 其余情况
            int wordWidth = cur - (cnt - 1);          // 当前行单词长度
            int spaceWidth = maxWidth - wordWidth;    // 当前行空格长度
            int avgSpace = spaceWidth / (cnt - 1);    // 单词平均间隔
            int extraSpace = spaceWidth % (cnt - 1);  // 额外单词间隔
            string s;
            for (int j = 0; j < row.size(); j++) {
                s += row[j];
                if (j == cnt - 1) break;
                // 单词平均间隔
                s += string(avgSpace, ' ');
                // 前 extraSpace 个单词添加 avgSpace + 1 个空格
                if (extraSpace-- > 0) s += ' ';
            }
            ans.push_back(s);
        }
        return ans;
    }
};