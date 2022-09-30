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

int min(int a, int b){
    if(a - b > 0){
        return b;
    }
    else{
        return a;
    }
}

int count(int *value, int *num, int start, int end){
    if(start == end){
        return value[start];
    }
    int mid = (start + end - 1) / 2;
    int left_min = count(value, num, start, mid);
    int right_min = count(value, num, mid, end);

    for(int i = mid; i >= 0; i--){
        for(int j = mid + 1; j <= end; j++){

        }
    }


}

int main(){
    int n;
    scanf("%d", &n);
    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }
    int num = 0;

    return 0;
}