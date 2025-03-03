#include <iostream>
using namespace std;
int** transpose_matrice(int** matrix,int n,int m);
int main(){
    int n, m;
    cout<<"enter the number of rows"<<endl;
    cin>>n;
    cout<<"enter the number of columns"<<endl;
    cin>>m;
    int** matrix = new int*[n];
    for (int i=0; i<n; ++i) matrix[i] = new int[m];
    int count = 0;
    for (int i=0; i<n;++i){
        for (int j=0; j<m;++j){
            matrix[i][j] = count;
            count++;
        }
    }
    int** res = transpose_matrice(matrix, n, m);
    cout<<"la matrice originale"<<endl;
    for (int i=0; i<n;++i){
        for (int j=0; j<m;++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"la matrice transpose"<<endl;
    for (int i=0; i<m;++i){
        for (int j=0; j<n;++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<n; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}
int** transpose_matrice(int** matrix, int n, int m){
    int** transpose = new int*[m];
    for (int i=0; i<m; ++i) transpose[i] = new int[n];
    for (int i=0; i<m;++i){
        for (int j=0; j<n;++j){
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}