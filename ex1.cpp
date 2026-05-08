#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArrayIngenuo(const vector<int>& nums) {
    int max_soma = nums[0];
    for (size_t i = 0; i < nums.size(); ++i) {
        int soma_atual = 0;
        for (size_t j = i; j < nums.size(); ++j) {
            soma_atual += nums[j];
            max_soma = max(max_soma, soma_atual);
        }
    }
    return max_soma;
}

// Algoritmo de Kadane
int maxSubArrayKadane(const vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

// Algoritmo de Kadane adaptado
struct ResultadoSubvetor {
    int soma;
    int inicio;
    int fim;
};

ResultadoSubvetor kadaneComIndices(const vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];
    int inicio = 0, fim = 0, temp_inicio = 0;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > max_ending_here + nums[i]) {
            max_ending_here = nums[i];
            temp_inicio = i;
        } else {
            max_ending_here += nums[i];
        }

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            inicio = temp_inicio;
            fim = i;
        }
    }
    return {max_so_far, inicio, fim};
}

int main() {
    vector<int> nums = {-2, 3, 5, -1, 4, -5};
    cout << "--- Exercicio 1: Maxima Soma de Subvetor ---\n";
    cout << "Soma (Ingenua O(n^2)): " << maxSubArrayIngenuo(nums) << "\n";
    cout << "Soma (Kadane O(n)): " << maxSubArrayKadane(nums) << "\n";
    
    ResultadoSubvetor res = kadaneComIndices(nums);
    cout << "Kadane com Indices -> Soma: " << res.soma 
         << ", Inicio: " << res.inicio << ", Fim: " << res.fim << "\n";
    return 0;
}
