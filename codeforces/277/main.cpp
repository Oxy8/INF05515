/*
n = numero de pessoas
m = numero de linguas

Vamos considerar o pior caso com sendo o caso quando todas pessoas falam todas linguas.

Construimos vetores onde são guardados cada uma das pessoas que falam cada lingua. (n*m) no pior caso

Iteramos cada vetor de linguagens e adicionamos arestas conectando todos os membros entre si (n*m) no pior caso

iteramos cada pessoas, executando BFS em cada uma.
Poderíamos considerar que como complexidade de BFS é O(V+E) e ele é executado V vezes (cada pessoa é um vértices).
então a complexidade seria O(n*(n+E)), mas o BFS só executa um número equivalente ao numero de grafos disjuntos
presentes, então só iteraria por todos os nodos se só rodasse 1 vez também. a soma da complexidade de todos os bfs
executados será O(V+E). No pior dos casos, O(V+E) corresponde a O(n+n*m)

Então a complexidade final é, no pior dos casos
= O(n+n*m + n*m + n*m)
= O(n+3*n*m)
= O(n*m)
*/



#include <iostream>
#include <vector>
#include <queue>

void bfs(int start_node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    std::queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> lang_to_employees(m + 1);
    bool any_languages_known = false;

    for (int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        if (k > 0) {
            any_languages_known = true;
        }
        for (int j = 0; j < k; ++j) {
            int lang;
            std::cin >> lang;
            lang_to_employees[lang].push_back(i);
        }
    }

    if (!any_languages_known) {
        std::cout << n << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> adj(n + 1);
    for (int lang = 1; lang <= m; ++lang) {
        for (size_t i = 1; i < lang_to_employees[lang].size(); ++i) {
            int u = lang_to_employees[lang][0]; 
            int v = lang_to_employees[lang][i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }


    std::vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components++;
            bfs(i, adj, visited);
        }
    }

    std::cout << components - 1 << std::endl;

    return 0;
}

