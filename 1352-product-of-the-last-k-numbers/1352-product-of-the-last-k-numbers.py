class ProductOfNumbers:

    def __init__(self):
        self.prefixp = [1]
        
        self.zeroloc = 1

    def add(self, num: int) -> None:
        self.zeroloc+=1
        
        self.prefixp.append(self.prefixp[-1]*max(num,1))
        if num == 0:
            self.zeroloc = 1

    def getProduct(self, k: int) -> int:
        deno = self.prefixp[-k-1]
        if k >= self.zeroloc and k < len(self.prefixp):
            print("haha")
            return 0
        return self.prefixp[-1]//deno
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)