/*
 * @Descroption: LeetCode 1282. 用户分组
 * @Author: EmoryHuang
 * @Date: 2022-08-12 09:11:09
 * @Method:
 * 哈希表记录group大小相同用户的ID
 * 之后贪心地对每个用户进行分组
 */

class Solution {

  public List<List<Integer>> groupThePeople(int[] groupSizes) {
    Map<Integer, List<Integer>> map = new HashMap<>();
    for (int i = 0; i < groupSizes.length; i++) {
      if (!map.containsKey(groupSizes[i])) {
        map.put(groupSizes[i], new ArrayList<>());
      }
      map.get(groupSizes[i]).add(i);
    }
    List<List<Integer>> res = new ArrayList<>();
    for (int key : map.keySet()) {
      List<Integer> list = map.get(key);
      for (int i = 0; i < list.size(); i += key) {
        res.add(list.subList(i, i + key));
      }
    }
    return res;
  }
}
