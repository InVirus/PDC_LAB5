#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateCombinations() {
    char B[] = { 'x', 'y', 'z' };
    char C[] = { '0', '1' };       
    char A[] = { 'a', 'b', 'c' };  

    vector<string> D;

    for (int ib = 0; ib < 3; ++ib) {
        for (int ic = 0; ic < 2; ++ic) {
            for (int ia = 0; ia < 3; ++ia) {
                D.push_back(string(1, B[ib]) + C[ic] + A[ia]);
            }
        }
    }

    return D;
}

int main() {
    vector<string> combinations = generateCombinations();
    cout << "B x C x A: \n";
    for (size_t i = 0; i < combinations.size(); ++i) {
        cout << combinations[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
    return 0;
}
