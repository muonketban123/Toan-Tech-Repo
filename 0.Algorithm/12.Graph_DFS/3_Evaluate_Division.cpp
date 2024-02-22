// 399. Evaluate Division
// Medium

// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
 

// Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    void dfs(string start, string end, map<string, double> &mval, map<string, vector<string>> &graph, double& val, map<string, int> &vis, bool &found) {
        vis[start] = 1;
        for(auto child : graph[start]) {
            if(!vis[child]) {
                val*= mval[start+","+child];
                if(child == end) {
                    found = true;
                    return;
                } 
                dfs(child, end, mval, graph, val, vis, found);
                if(found == true) {
                    return;
                } else {
                    // neu di sai duong thi phai chia di giong nhu quay lui
                    val /= mval[start+","+child];
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string, double> mval;
        map<string, vector<string>> graph;
        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            mval[u+","+v] = values[i];
            mval[v+","+u] = 1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                ans.push_back(-1);
            } else {
                double val = 1;
                bool found = false;
                map<string, int> vis;
                if(start == end) {
                    found = true;
                } else
                dfs(start, end, mval, graph, val, vis, found);
                if(found == true) {
                    ans.push_back(val);
                } else 
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    vector<double> res = s.calcEquation(equations, values, queries);
    for(auto t : res) {
        cout << t << " ";
    }

}