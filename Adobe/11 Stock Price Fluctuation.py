class StockPrice:

    def __init__(self):
        self.minheap = []
        self.maxheap = []
        self.dict_time = {}
        self.cur = None
        

    def update(self, timestamp: int, price: int) -> None:
        heapq.heappush(self.minheap, (price, timestamp))
        heapq.heappush(self.maxheap, (-price, timestamp))
        self.dict_time[timestamp] = price
        if not self.cur:
            self.cur = timestamp
        elif timestamp > self.cur:
            self.cur = timestamp

        
    def current(self) -> int:
        return self.dict_time[self.cur]

    def maximum(self) -> int:
        maxprice, timestamp = self.maxheap[0]
        while self.dict_time[timestamp] != -maxprice:
            heapq.heappop(self.maxheap)
            maxprice, timestamp = self.maxheap[0]
        return -maxprice


    def minimum(self) -> int:
        minprice, timestamp = self.minheap[0]
        while self.dict_time[timestamp] != minprice:
            heapq.heappop(self.minheap)
            minprice, timestamp = self.minheap[0]
        return minprice



# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()


"""
    Time Complexity : O(n)
    Space Complexity : O(n)
"""    
