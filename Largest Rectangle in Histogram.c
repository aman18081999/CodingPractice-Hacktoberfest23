class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stk;
        int n = heights.size();

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;

            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int height = stk.top().second;
                stk.pop();
                maxArea = max(maxArea, (i - index) * height);
                start = index;
            }

            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            stk.pop();
            maxArea = max(maxArea, (n - index) * height);
        }

        return maxArea;
    }
};
