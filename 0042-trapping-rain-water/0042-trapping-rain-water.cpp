class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        int n = height.size();

        vector<int> LeftMax(n), RightMax(n);

        LeftMax[0] = height[0];
        RightMax[n - 1] = height[n - 1];

        // Fill LeftMax
        for (int i = 1; i < n; i++) {
            LeftMax[i] = max(LeftMax[i - 1], height[i]);
        }

        // Fill RightMax
        for (int i = n - 2; i >= 0; i--) {
            RightMax[i] = max(RightMax[i + 1], height[i]);
        }

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += min(LeftMax[i], RightMax[i]) - height[i];
        }

        return sum;
    }
};