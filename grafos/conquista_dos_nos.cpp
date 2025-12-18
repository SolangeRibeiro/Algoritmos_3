#include <iostream>
using namespace std;

int main() {
    int N, M; 
    cin >> N >> M;  // lê o número de cidades (N) e o número de caminhos (M)

    // Criamos uma matriz NxN inicializada com 0
    int matriz[101][101] = {0}; 

    // Lê as M arestas (caminhos entre cidades)
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        
        // Como o grafo é bidirecional, marcamos A->B e B->A como 1
        matriz[A-1][B-1] = 1;
        matriz[B-1][A-1] = 1;
    }

    // Imprime a matriz de adjacência
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
