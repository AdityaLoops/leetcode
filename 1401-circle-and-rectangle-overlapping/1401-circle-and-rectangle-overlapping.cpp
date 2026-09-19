class Solution {
public:
    bool checkOverlap(int radius, int xc, int xy, int x1, int y1, int x2, int y2) {
        int closestx = max(x1, min(xc, x2));
        int closesty = max(y1, min (xy, y2));
        int dx = xc - closestx;
        int dy = xy - closesty;
        return dx*dx + dy* dy <= radius*radius;
        

    }
};