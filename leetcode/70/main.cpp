#include <vector>
#include <iostream>
#include <climits>


using namespace std;

class Solution {
public:
    static int climbStairs(int n) {
        
        if (n == 1) {return 1;}
        
        vector<int> steps(n);
        
        steps[0] = 1;
        steps[1] = 2;
        
        int i;
        for (i=2; i < n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n-1];     
    }
};

int main() {
    
    int sol = Solution::climbStairs(3);

    cout << sol << "\n";
}