class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) // Check if the points vector is empty
            return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort based on the end points
        });
        
        int arrows = 1;
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] <= end) {
                continue; // Current balloon is within the range of the previous arrow
            } else {
                arrows++; // Need another arrow
                end = points[i][1]; // Update end point
            }
        }
        
        return arrows;
    }
};