#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::size;

int main() {    
    vector<int> vetor = {1, 2, 2, 12, 213, 31};

    int vetor_size = size(vetor);

    cout << "Size of vector: " << vetor_size << "\n\n";

    for (int i = 0; i < vetor_size; i++) {
        cout << vetor[i] << " ";

        if (i == vetor_size - 1) {
            cout << "\n";
        }
    }

    return 0;
}
