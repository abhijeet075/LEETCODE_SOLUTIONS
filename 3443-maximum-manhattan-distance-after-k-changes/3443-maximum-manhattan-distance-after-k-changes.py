class Solution(object):
    def maxDistance(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """


        x,y,md =0,0,0
        for i in range(1,len(s)+1):
            if s[i-1] == "N":
                y+=1
            elif s[i-1] =="S":
                y-=1
            elif s[i-1] =="E":
                x+=1
            elif s[i-1] =="W":
                x-=1
            md =max(md,min(i,abs(x)+abs(y) + (2*k)))
        return md