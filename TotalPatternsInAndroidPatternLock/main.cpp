#include <iostream>
using namespace std;

#define fora(a,b) for(a=0;a<b;a++)

class matrix {
    long long a[9][9];
    long long freq[9][9][9];

public:
    matrix(){
        int i, j, k;
        fora(i,9) fora(j,9) a[i][j] = 0;
        fora(i,9) fora(j,9) fora(k,9) freq[i][j][k] = 0;
    }

    matrix(long long a[][9]) {
        int i, j, k;
        fora(i,9) fora(j,9) fora(k,9) freq[i][j][k] = 0;
        fora(i,9) fora(j,9) {
            this->a[i][j] = a[i][j];
            freq[i][j][i] = freq[i][j][j] = a[i][j];
        }
    }

    void mul(matrix b) {
        matrix c;
        int i, j, k;
        long long temp;
        fora(i,9) {
            fora(j,9) {
                c.a[i][j] = 0;
                fora(k,9) {
                    temp = (a[i][k]-freq[i][k][j])*(b.a[k][j]-b.freq[k][j][i]);
                    c.a[i][j] += temp;
                    c.freq[i][j][i] += temp;
                    c.freq[i][j][k] += temp;
                    c.freq[i][j][j] += temp;
                }
            }
        }

        fora(i,9) fora(j,9) {
            a[i][j] = c.a[i][j];
            fora(k,9) freq[i][j][k] = c.freq[i][j][k];
        }
    }

    long long sum() {
        long long sum = 0;
        int i, j;
        fora(i,9) fora(j,9) sum = sum + a[i][j];
        return sum;
    }
    void print() {
        int i, j, k;
        cout << endl << "Matrix: " << endl;
        fora(i,9) {
            fora(j,9) cout << a[i][j] << " ";
            cout << endl;
        }

        cout << endl << "Frequency: " << endl;
        fora(i,9) {
            fora(j,9) {
                cout << "[" << (i+1) << "," << (j+1) << "]: ";
                fora(k,9) cout << freq[i][j][k] << " ";
                cout << endl;
            }
        }
        cout << "sum in matrix: " << sum() << endl;
    }

};

int main() {
    long long a[][9] = {{0,1,0,1,1,1,0,1,0},
                        {1,0,1,1,1,1,1,0,1},
                        {0,1,0,1,1,1,0,1,0},
                        {1,1,1,0,1,0,1,1,1},
                        {1,1,1,1,0,1,1,1,1},
                        {1,1,1,0,1,0,1,1,1},
                        {0,1,0,1,1,1,0,1,0},
                        {1,0,1,1,1,1,1,0,1},
                        {0,1,0,1,1,1,0,1,0}};

    long long sum=0, local_sum;
    matrix mat(a), mat1(a);

    int i;
    fora(i,2) {
        mat1.mul(mat);
//        mat1.print();
    }

    fora(i,6) {
        mat1.mul(mat);
//        mat1.print();
        local_sum = mat1.sum();
        sum = sum + local_sum;
        cout << "current sum for " << (i+4) << " : [" << local_sum << "," << sum << "]" << endl;
    }
    cout << "total sum: " << sum << endl;
    return 0;
}
