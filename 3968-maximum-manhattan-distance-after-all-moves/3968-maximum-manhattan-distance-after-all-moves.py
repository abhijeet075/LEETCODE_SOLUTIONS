class Solution(object):
    def maxDistance(self, moves):
        """
        :type moves: str
        :rtype: int
        """
        X,Y,Z = 0,0,0

        for m in moves:
            if m=="U":
                Y+=1
            elif m=="D":
                Y-=1
            elif m=="R":
                X+=1
            elif m=="L":
                X-=1
            else:
                Z+=1
        return abs(X) +abs(Y)+Z

        