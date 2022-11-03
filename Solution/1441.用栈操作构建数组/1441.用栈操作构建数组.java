/*
 * @Descroption: LeetCode 1441. 用栈操作构建数组
 * @Author: EmoryHuang
 * @Date: 2022-10-15 10:19:35
 * @Method:
 * 遍历数组，若在数组中，则`Push`，否则先`Push`再`Pop`
 */

class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<String>();
        int count = 1;
        for (int i = 0; i < target.length; count++){
            if (target[i] == count){
                i++;
                ans.add("Push");
            }else{
                ans.add("Push");
                ans.add("Pop");
            }
        }
        return ans;
    }
}