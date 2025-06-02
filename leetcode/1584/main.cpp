#include <vector>
#include <iostream>
#include <climits>


using namespace std;

class Solution {
public:
    static int minCostConnectPoints(vector<vector<int>>& points) {
       
        int total_cost = 0;

        vector<bool> connected(points.size(), false);
        vector<int> distances(points.size(), 0); 
        int connected_counter = 0;

        // começa em vértice qualquer (0)
        // conecta com vértice mais perto, e marca este como visitado
        // manter array com menor distancia até os vértices remanescentes, e atualizar de acordo com cada novo vértices que for adicionado.

        connected[0] = true;
        connected_counter++;

        int i;
        for (i=0; i < points.size(); i++) {    
            distances[i] = manhattanDistance(points[i], points[0]);
        }
        while (connected_counter < points.size()) {
            
            int smallest_distance = INT_MAX;
            int smallest_distance_point;
            
            // Primeiro determina qual que é o próximo nodo que devemos adicionar (o mais perto)
            // depois, recalcula distancias com base no novo nodo adicionado
            // repete.
            
            for (i=0; i < points.size(); i++) {
                if (connected[i] == false) {
                    if (distances[i] < smallest_distance) {
                        smallest_distance = distances[i];
                        smallest_distance_point = i;
                    }
                }
            }

            total_cost += smallest_distance;

            for (i=0; i < points.size(); i++) {
                if (manhattanDistance(points[i], points[smallest_distance_point]) < distances[i] && i != smallest_distance_point) {
                    distances[i] = manhattanDistance(points[i], points[smallest_distance_point]);
                }
            }

            connected[smallest_distance_point] = true;
            connected_counter++;
        }
        return total_cost;
    }

    static int manhattanDistance(vector<int> p1, vector<int> p2) {
        return (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]));
    }
};

int main() {
    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };
    int sol = Solution::minCostConnectPoints(points);

    cout << sol << "\n";
}