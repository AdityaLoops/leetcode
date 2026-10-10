class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        ans = []
        intervals.sort(key=lambda x: x[0])
        prevstart = intervals[0][0]
        prevend = intervals[0][1]
        i=1
        for i in range(len(intervals)):
            currstart = intervals[i][0]
            currend = intervals[i][1]
            if prevend >= currstart:          
                prevend = max(prevend, currend)
            else:
                ans.append([prevstart, prevend])
                prevstart = intervals[i][0]
                prevend = intervals[i][1]
        ans.append([prevstart, prevend])
        return ans
            