#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    static int tribonacci(int n) {
        
        vector<int> nth(min(n,3));

        nth[0] = 0;
        nth[1] = 1;
        nth[2] = 1;

        int i;
        for (i=3; i < n; i++) {
            nth[i] = nth[i-1] + nth[i-2] + nth[i-3];
        }

        return nth[n-1];
    }
};

int main() {
    
    int sol = Solution::tribonacci(3);

    cout << sol << "\n";
}