#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Conjunto independente
grafo linear
Para ser Conjunto independente precisamos que dois vértices não sejam adjacentes.
Precisamos achar com peso máximo.
podemos sacrificar cobrir algumas arestas desde que consigamos pesos altos, então não intercala.
*/

void conjunto_independente_maximo(const std::vector<int>& pesos) {   

    int n = pesos.size();


    std::vector<int> dp(n);
    dp[0] = pesos[0];
    dp[1] = std::max(pesos[0], pesos[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i-1], pesos[i] + dp[i-2]);
    }


    std::cout << "Peso máximo: " << dp[n - 1] << std::endl;

    for (int i = n - 1; i >= 0; ) {
        
        if (i == 0) {
            std::cout << "Aresta: " << i << " peso: " << pesos[i] << std::endl;
            break; 
        }
        if (dp[i] > dp[i-1]) {
            std::cout << "Aresta: " << i << " peso: " << pesos[i] << std::endl;
            i -= 2; 
        } else {
            i -= 1; 
        }
    }
}

int main() {
    std::vector<int> pesos = {5, 2, 10, 8, 3};
    // 5 pesos são 6 nodos
    conjunto_independente_maximo(pesos);

    std::cout << "\n\n\n\n\n\n";

    std::vector<int> pesos2 = {50, 2, 10, 38, 3};
    // testando pulo de dois vértices.
    conjunto_independente_maximo(pesos2);

    return 0;
}