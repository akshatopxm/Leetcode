class Solution {
public:
    int findMaximizedCapital(int k, int w, 
                             vector<int>& profits, 
                             vector<int>& capital) {

        int n = profits.size();

        // Store {capital required, profit}
        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort by required capital
        sort(projects.begin(), projects.end());

        // Max heap -> maximum profit on top
        priority_queue<int> maxProfit;

        int i = 0;

        while (k--) {

            // Add all affordable projects
            while (i < n && projects[i].first <= w) {
                maxProfit.push(projects[i].second);
                i++;
            }

            // No project can be started
            if (maxProfit.empty())
                break;

            // Choose maximum profit
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};