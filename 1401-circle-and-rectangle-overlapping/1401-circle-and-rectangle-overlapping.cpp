class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the nearest point on the rectangle to the center of circle
        int Xmin = max(x1, min(x2, xCenter));
        int Ymin = max(y1, min(y2, yCenter));

        int x = Xmin-xCenter;
        int y = Ymin-yCenter;
 
        if(x*x + y*y <= radius * radius)
        return true;
        return false ;
    }
};