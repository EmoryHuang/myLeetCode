class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        MOD = 10 ** 9 + 7
        buyOrders, sellOrders = [], []
        for price, amount, type in orders:
            if type == 0:
                while amount and sellOrders and sellOrders[0][0] <= price:
                    if sellOrders[0][1] > amount:
                        sellOrders[0][1] -= amount
                        amount = 0
                        break
                    amount -= heappop(sellOrders)[1]
                if amount:
                    heappush(buyOrders, [-price, amount])
            else:
                while amount and buyOrders and -buyOrders[0][0] >= price:
                    if buyOrders[0][1] > amount:
                        buyOrders[0][1] -= amount
                        amount = 0
                        break
                    amount -= heappop(buyOrders)[1]
                if amount:
                    heappush(sellOrders, [price, amount])
        return (sum(x for _, x in buyOrders) + sum(x for _, x in sellOrders)) % MOD
