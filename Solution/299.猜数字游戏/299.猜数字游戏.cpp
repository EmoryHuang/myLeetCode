/*
 * @Descroption: LeetCode 299. 猜数字游戏
 * @Author: EmoryHuang
 * @Date: 2021-07-30 13:47:49
 * @Method:
 * 使用一个哈希表存储数字是否出现
 * 若guess中的数不是公牛，则 hash 减一
 * 若secret中的数不是公牛，则 hash 加一
 *
 * 如果当前位置为正，则说明一定有来自secret中未匹配的字符
 * 如果当前位置为负，则说明一定有来自guess中未匹配的字符
 */

class Solution {
   public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> hash(10);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                a++;
            else {
                // 如果当前位置为负，则说明一定有来自guess中未匹配的字符
                if (hash[secret[i] - '0'] < 0) b++;
                // 若secret中的数不是公牛，则 hash 加一
                hash[secret[i] - '0']++;
                // 如果当前位置为正，则说明一定有来自secret中未匹配的字符
                if (hash[guess[i] - '0'] > 0) b++;
                // 若guess中的数不是公牛，则 hash 减一
                hash[guess[i] - '0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};