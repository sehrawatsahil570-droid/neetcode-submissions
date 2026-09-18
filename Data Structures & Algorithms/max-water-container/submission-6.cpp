class Solution {
public:
    int maxArea(vector<int>& heights) {
        int str = 0;
        int end = heights.size() - 1;
        int area = 0;

        while (str < end) {
            int currArea = min(heights[str], heights[end]) * (end - str);

            area = max(area, currArea);

            if (heights[str] < heights[end])
                str++;
            else
                end--;
        }

        return area;
    }
};