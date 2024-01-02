#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
    double sum=0, sumsd=0, sumgm = 1, sumhm=0;
    B[4]=A[0];
    B[5]=A[0];
    for(int i=0; i<N; i++){
        sum += A[i];
        B[0] = sum/N;
    }
    for(int i=0; i<N; i++){
        sumsd += pow(A[i]-B[0],2);
        B[1] = pow(sumsd/N,0.5);
    }
    for(int i=0; i<N; i++){
        sumgm *= A[i];
        B[2] = pow(sumgm,1.0/N);
    }
    for(int i=0; i<N; i++){
        sumhm += 1.0/A[i];
        B[3] = N/sumhm;
    }
    for(int i=0; i<N; i++){
        if(B[4]<A[i]) B[4]=A[i];
    }
    for(int i=0; i<N; i++){
        if(B[5]>A[i]) B[5]=A[i];
    }
}
