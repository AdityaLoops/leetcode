class Solution:
    def checkString(self, s: str) -> bool:
        seenb = False
        for x in s:
            if x =='b':
                seenb = True
            if x == 'a' and seenb:
                return False
        return True