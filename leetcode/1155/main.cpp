#include <vector>
#include <iostream>


using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    static int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp_matrix(n+1, vector<int>(target, 0));

        int r, s, t;

        for (t=0; t < min(k,target); t++) {
            dp_matrix[0][t] = 1;
        }

        // Para cada quantidade de dados, para cada target, para cada valor possível do dado
        for (r = 0; r < n; r++) {
            for (s = 0; s < target; s++) {
                
                long long acc = 0;
                
                for (t = 1; t <= k && t <= s; t++) {
                    acc = (acc + dp_matrix[r][s-t]) % MOD;
                }

                dp_matrix[r+1][s] = acc;
            }
        } 
        /*
        for (int i = 0; i < n+1; i++)
        {
        for (int j = 0; j < target; j++)
        {
            cout << dp_matrix[i][j] << " ";
        }

        cout << endl;
        }
        */
        
        return dp_matrix[n-1][target-1];
    }
};

int main() {
    
    int sol = Solution::numRollsToTarget(3,6,11);

    cout << sol << "\n";
}