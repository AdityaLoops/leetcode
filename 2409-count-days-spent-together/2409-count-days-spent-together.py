class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        add = {
            "01": 0,
            "02": 31,
            "03": 59,
            "04": 90,
            "05": 120,
            "06": 151,
            "07": 181,
            "08": 212,
            "09": 243,
            "10": 273,
            "11": 304,
            "12": 334,
        }


        aa = add[arriveAlice[:2]] + int(arriveAlice[3:])
        al = add[leaveAlice[:2]] + int(leaveAlice[3:])
        ba = add[arriveBob[:2]] + int(arriveBob[3:])
        bl = add[leaveBob[:2]] + int(leaveBob[3:])

        ans = max(0, min(al, bl) - max(aa, ba) +1)
        return ans
