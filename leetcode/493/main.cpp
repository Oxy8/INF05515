#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    pair<vector<long>, int> MergeAndCountSplitInv(const vector<long>& A, const vector<long>& B) {
        vector<long> L; 
        int inv = 0;
        int i = 0, j = 0;
        int nA = A.size(), nB = B.size();

        while (i < nA && j < nB) {

            if (A[i]<= 2* B[j]) {
                i++;         
            } else {
                inv += (nA - i); // All remaining elements in A form inversion with B[j]
                j++;
            }
        }

        i = 0;
        j = 0;

        while (i < nA && j < nB) {
            if (A[i] <= B[j]) {
                L.push_back(A[i]);
                i++;         
            } else {
                L.push_back(B[j]);
                j++;
            }
        }

        while (i < nA) {
            L.push_back(A[i]);
            i++;
        }

        while (j < nB) {
            L.push_back(B[j]);
            j++;
        }

        return {L, inv};
    }

    pair<vector<long>, int> MergeAndCountInversions(const vector<long>& S) {
        int n = S.size();
        if (n <= 1) {
            return {S, 0};
        }

        int mid = n / 2;
        vector<long> A(S.begin(), S.begin() + mid);
        vector<long> B(S.begin() + mid, S.end());

        auto [A_sorted, invA] = MergeAndCountInversions(A);
        auto [B_sorted, invB] = MergeAndCountInversions(B);
        auto [L, invCross] = MergeAndCountSplitInv(A_sorted, B_sorted);

        int totalInversions = invA + invB + invCross;

        return {L, totalInversions};
    }


    int reversePairs(vector<int>& nums) {
        vector<long> S(nums.begin(), nums.end());
        return MergeAndCountInversions(S).second;
    }
};

// Exemplo de uso
int main() {
    vector<int> S;
    int number;

    S = {2,4,3,5,1};

    vector<long> U(S.begin(), S.end());

    auto [sortedArray, totalInversions] = MergeAndCountInversions(U);

    cout << "Numero total de inversoes: " << totalInversions << endl;
    cout << "Array ordenado: ";
    for (int x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
