#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <array>
using namespace std;
template<typename T, int M, int N>
class Matrix{
    private:
        T matrice[M][N];
    public:
        void set(int i, int j, T val){
            if (i<0 || i>M || j<0 || j>N){
                throw out_of_range("out of bounds");
            }
            matrice[i][j] = val;
        }
        T get(int i, int j){
            if (i<0 || i>M || j<0 || j>N){
                throw out_of_range("out of bounds");
            }
            return matrice[i][j];
        }
        template<int P, int Q>
        Matrix<T, M, N> add(Matrix<T,P,Q> matrix){
            static_assert(M==P && N==Q, "Imcompatible dimensions");
            Matrix<T, M,N> res;
            for (int i=0; i<M; ++i){
                for (int j=0; j<N; ++j){
                    res.set(i, j, matrice[i][j]+matrix.get(i,j));
                }
            }
            return res;
        }
};
#endif