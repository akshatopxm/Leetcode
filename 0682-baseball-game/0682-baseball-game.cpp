class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        for (string op : operations) {

            if (op == "C") {
                st.pop_back();
            }

            else if (op == "D") {
                st.push_back(st.back() * 2);
            }

            else if (op == "+") {
                int n = st.size();
                st.push_back(st[n - 1] + st[n - 2]);
            }

            else {
                st.push_back(stoi(op));
            }
        }

        int ans = 0;

        for (int x : st) {
            ans += x;
        }

        return ans;
    }
};