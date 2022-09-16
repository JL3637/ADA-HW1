#include<stdio.h>
#include<iostream>

void cash(int n, int w, int *price){
    
}

int main(){
    int n, w;
    scanf("%d%d", &n, &w);
    int *price = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &price[i]);
    }

    return 0;
}