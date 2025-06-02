#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    static int minCostClimbingStairs(vector<int>& cost) {

        vector<int> reach(cost.size()+1); // the cost to reach a given place

        reach[0] = 0;
        reach[1] = 0;

        int i;
        for (i=2; i < (cost.size() + 1); i++) {
            reach[i] = min((reach[i-1] + cost[i-1]), (reach[i-2] + cost[i-2]));
        }

        return reach.back();
    }
};

int main() {
    
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    int sol = Solution::minCostClimbingStairs(cost);

    cout << sol << "\n";
}