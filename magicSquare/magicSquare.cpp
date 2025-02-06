#include <iostream>

using namespace std;

void generateMagicSquare(int n) {
    int** magicSquare = new int*[n];
    for (int i = 0; i < n; ++i) {
        magicSquare[i] = new int[n]();
    }

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            i = 0;
            j = n - 2;
        }
        else {
            if (i < 0) i = n - 1;
            if (j == n) j = 0;
        }
        
        if (magicSquare[i][j]) {
            i += 1;
            j -= 2;
            continue;
        }
        else {
            magicSquare[i][j] = num++;
        }
        
        i--;
        j++;
    }

    cout << "Magic Square of size " << n << ":\n";
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        delete[] magicSquare[i];
    }
    delete[] magicSquare;
}

int main() {
    int n;
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;
    
    if (n % 2 == 1) {
        generateMagicSquare(n);
    }
    else {
        cout << "Size must be an odd number.\n";
    }

    return 0;
}
