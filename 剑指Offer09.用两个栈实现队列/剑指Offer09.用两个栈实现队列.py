'''
Descroption: ��ָ Offer 09. ������ջʵ�ֶ���
Author: EmoryHuang
Date: 2021-06-29 19:51:00
����˼·:
ʹ������ջ��һ��ջ�룬һ��ջ��
����Ԫ��ʱ����Ԫ�ط��� s_in
ɾ��Ԫ��ʱ��
    �� s_out �ǿգ��򵯳�s_out��
    �� s_out Ϊ�գ���� s_in �еĶ���ȫ������ s_out �У�����s_out��
    �� s_out, s_in ��Ϊ�գ����� -1
'''


class CQueue:

    def __init__(self):
        self.s_in = []
        self.s_out = []

    def appendTail(self, value: int) -> None:
        self.s_in.append(value)

    def deleteHead(self) -> int:
        if not self.s_out:  # �� s_out Ϊ��
            if not self.s_in:  # �� s_in Ϊ��
                return -1
            while self.s_in:  # �� s_in �еĶ���ȫ������ s_out ��
                self.s_out.append(self.s_in.pop())
        return self.s_out.pop()

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
