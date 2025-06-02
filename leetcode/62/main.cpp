#include <vector>
#include <iostream>
#include <climits>


using namespace std;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        vector<vector<int>> matriz(m, vector<int>(n, 0));
    


        int i, j;

        for (i=0; i < m; i++) {
            matriz[i][0] = 1;
        }
        for (j=0; j < n; j++) {
            matriz[0][j] = 1;
        }

        for (i=1; i < m; i++) {
            for (j=1; j < n; j++) {
                matriz[i][j] = matriz[i-1][j] + matriz[i][j-1];
            }
        }

        return matriz[m-1][n-1];
    }
};

int main() {
    
    int sol = Solution::uniquePaths(3, 4);

    cout << sol << "\n";
}