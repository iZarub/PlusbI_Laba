#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using std::vector;
using std::cout;
using std::cin;



struct matrix {
    float** arr;
    int M;

    matrix(int M) {

        arr = (float**)malloc(M * sizeof(float**));
        for (int i = 0; i < M; ++i) {
            arr[i] = (float*)malloc(M * sizeof(float*));
        }


        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                float a;
                cin >> a;
                arr[i][j] = a;

            }

        }
    }


    matrix(int M, int) {
        arr = (float**)malloc(M * sizeof(float**));
        for (int i = 0; i < M; ++i) {
            arr[i] = (float*)malloc(M * sizeof(float*));
        }
    }



    ~matrix() {
        for (int i = 0; i < M; i++) {
            free(arr[i]);
        
        }
        free(arr);
    }


    void GetMatrix() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cout << arr[i][j] << " ";
            }
            cout << std::endl;
        }
    }


    void GetMulti(matrix m2) {
        matrix m3(m2.M, 1);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; i++) {
                m3.arr[i][j] = this->arr[i][j]
            
            
            }
        
        
        
        }



    
    
    }

};


int main(){
    int M;
    cin >> M;
    matrix m1(M);
    matrix m2(M);

}
