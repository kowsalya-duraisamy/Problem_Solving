class Solution:
    def hammingWeight(self, n: int) -> int:
        a=bin(n)[2:]
        count=0
        for char in a:
            if char == '1':
                count+=1
        return count