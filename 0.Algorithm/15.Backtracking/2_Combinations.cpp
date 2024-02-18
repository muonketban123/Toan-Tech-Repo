#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    void backTrack(int &n, int &k, vector<vector<int>>& res, vector<int>& ds, int c) {
        if(ds.size() == k) {
            res.push_back(ds);
            return;
        }

        for(int i = c; i <= n; i++) {
            ds.push_back(i);
            backTrack(n, k, res, ds, i +1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ds;
        backTrack(n, k, res, ds, 1);
        return res;

    }
};

int main() {
    int n = 4, k = 2;
    Solution s;
    vector<vector<int>> res = s.combine(n, k);
    for(auto t : res) {
        cout << "{ ";
        for(auto g : t) {
            cout << g << " ";
        }
        cout << " }";
    }
}