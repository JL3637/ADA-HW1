#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int diff(int a, int b){
    if(a - b > 0){
        return a - b;
    }
    else{
        return b - a;
    }
}

int count(int *value, int n){
    int num = 0;
    for(int i = 0; i < n-1; i++){
        int min = value[i] < value[i+1] ? value[i] : value[i+1];
        for(int j = i+1; j < n; j++){
            if(value[j] < min){
                min = value[j];
            }
            if(diff(value[i], value[j]) == min){
                num++;
            }
        }
    }

    return num;
}

int main(){
    int n;
    scanf("%d", &n);
    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }
    printf("%d", count(value, n));

    return 0;
}