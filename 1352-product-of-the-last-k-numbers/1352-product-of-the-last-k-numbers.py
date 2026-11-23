class ProductOfNumbers:

    def __init__(self):
        self.prefixp = [1]
        self.prefixs = [0]

    def add(self, num: int) -> None:
        self.prefixs.append(num)
        self.prefixp.append(self.prefixp[-1]*max(num,1))

    def getProduct(self, k: int) -> int:
        deno = self.prefixp[-k-1]
        if 0 in self.prefixs[-k:]:
            return 0
        return self.prefixp[-1]//deno
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)