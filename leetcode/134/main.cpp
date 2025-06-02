#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Inicia em um nodo e ve se para chegar no próximo fica negativo. se fica negativo, reseta pra 0 e começa denovo a partir do próximo.
        int size = gas.size();
        
        int i;
        for (i=0; i < size; i++) {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        // duplicamos os vetores para facilitar trabalhar como se fosse um ciclo.

        
        int acc = 0;
        int pointer = 0;
        int initial_element = 0;
        int element_counter = 0;

        while (pointer < (size*2) && element_counter < size) {
            acc += gas[pointer];
            acc -= cost[pointer];

            pointer++;
            if (acc < 0) {
                initial_element = pointer;
                element_counter = 0;
                acc = 0;
            } else {
                element_counter++;
            }
        }

        if (element_counter < size) {
            return -1;
        } else {
            return initial_element;
        }
        

    }
};