// 207. Course Schedule
// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool hasCycle(vector<vector<int>> &graph, int course, vector<int>& vis, vector<int> &onStack) {
        if(vis[course])
            return false;
        vis[course] = 1;
        onStack[course] = 1;
        for(int next : graph[course]) {
            if(onStack[next] || hasCycle(graph, next, vis, onStack)) 
                return true;
        }
        onStack[course] = 0;
        return false;
    }
    bool isCycle(vector<vector<int>> &graph, int numCourses) {
        vector<int> vis(numCourses, 0);
        vector<int> onStack(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if(!vis[i] && hasCycle(graph, i, vis, onStack)) {
                return true;
            }
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>> & prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        return !isCycle(graph, numCourses);
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    Solution s;
    bool res = s.canFinish(numCourses, prerequisites);
    if(res)
        cout << "ok " << endl;
    else 
        cout << "not ok " << endl;

}