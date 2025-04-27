#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<long, size_t>> MergeAndCountSplitInv(const vector<pair<long, size_t>>& A, const vector<pair<long, size_t>>& B, vector<int>& count) {
        // <pair<long, size_t>> é o vetor de entrada com o índice orginal de cada elemento.
        // índice serve para indicar posição na array count corretamente.
        
        
        vector<pair<long, size_t>> L; 
        int i = 0, j = 0;
        int nA = A.size(), nB = B.size();

        while (i < nA && j < nB) {

            // Todos elementos na array B possuem índice maior que os elementos da array A.

            if (B[j].first < A[i].first) {
                // se o elemento de B for menor, então podemos ir para o próximo elemento de B.
                j++;                         
            } else {
                // se não, se o elemento de B for maior ou igual, então contabilizamos todos os elementos anteriores
                // de B como menores que o elemento de A atual e vamos para o próximo elemento de A
                count[A[i].second] += j;
                i++;
            }
        }
        
        // Se chegarmos no fim de B, mas não tivermos percorrido todo A,
        // então todos elementos de B são menores que A.
        while (i < nA) {
            count[A[i].second] += j;
            i++;
        }

        i = 0;
        j = 0;

        while (i < nA && j < nB) {
            if (A[i].first <= B[j].first) {
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


        // count será atualizada porque foi passada como referência, retornamos apenas L (subarray ordenada)
        return L;
    }

    vector<pair<long, size_t>> MergeAndCountInversions(const vector<pair<long, size_t>>& S, vector<int>& count) {
        int n = S.size();
        if (n <= 1) {
            return S;
        }

        int mid = n / 2;
        vector<pair<long, size_t>> A(S.begin(), S.begin() + mid);
        vector<pair<long, size_t>> B(S.begin() + mid, S.end());

        auto A_sorted = MergeAndCountInversions(A, count);
        auto B_sorted = MergeAndCountInversions(B, count);
        auto L = MergeAndCountSplitInv(A_sorted, B_sorted, count);


        return L;
    }


    vector<int> countSmaller(vector<int>& nums) {

        vector<pair<long, size_t>> pairs;
        pairs.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            pairs.emplace_back(nums[i], i);
        }
        
        vector<int> count(nums.size(), 0);

        MergeAndCountInversions(pairs, count);
        return count;
    }
};

// Exemplo de uso
int main() {
    vector<int> nums;

    nums = {5,2,6,1};

    vector<pair<long, size_t>> pairs;
    pairs.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
        pairs.emplace_back(nums[i], i);
    }        
    
    vector<int> count(nums.size(), 0);

    Solution solution;
    auto sortedArray = solution.MergeAndCountInversions(pairs, count);

    cout << "Array ordenado: ";
    for (const auto& x : sortedArray) {
        cout << x.first << ", ";
    }
    cout << endl;

    cout << "Count: ";
    for (const auto& x : count) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}
