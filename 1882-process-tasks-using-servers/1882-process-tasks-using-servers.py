import heapq
class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        n = len(servers)
        m = len(tasks)
        free = []
        busy= []
        ans =[]

        for id, ser in enumerate(servers):
            heapq.heappush(free, (ser,id) )
        

        for i, time in enumerate(tasks):
            while busy and busy[0][0] <=i:
                tm, serv, idx = heapq.heappop(busy)
                heapq.heappush(free, (serv,idx))

            if free:
                ser, id = heapq.heappop(free)
                heapq.heappush(busy, (i+time, ser, id))
                ans.append(id)
                
            elif  busy[0][0] <=max(i, busy[0][0]):
                tm, serv , idx = heapq.heappop(busy)
                heapq.heappush(busy, (tm+time, serv, idx))
                ans.append(idx)
                
        return ans





