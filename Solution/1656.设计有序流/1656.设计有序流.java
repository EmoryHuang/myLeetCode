/*
 * @Descroption: LeetCode 1656. 设计有序流
 * @Author: EmoryHuang
 * @Date: 2022-08-16 09:14:08
 * @Method:
 * 数组存储有序流，并维护当前指针
 */


class OrderedStream {

    int idx = 0;
    String[] stream;

    public OrderedStream(int n) {
        stream = new String[n];
    }

    public List<String> insert(int idKey, String value) {
        List<String> res = new ArrayList<String>();
        stream[idKey - 1] = value;
        while (idx < stream.length && stream[idx] != null) {
            res.add(stream[idx++]);
        }
        return res;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */