#include<stdio.h>
#include<stdlib.h>

int optimal(int n, int *price, int *money){
    if(*money < price[0]){
        return *money;
    }



}

void cash(int n, int w, int *price){
    int num = 0;
    for(int i = 1; i <= w; i++){
        num = i;
        for(int j = n-1; j >= 0; j--){
            while(num >= price[j]){
                num = num - price[j];
            }
        }
        printf("%d\n", num);
    }
    return;
}

int main(){
    int n = 0;
    int w = 0;
    scanf("%d%d", &n, &w);
    int *price = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &price[i]);
    }
    cash(n, w, price);

    return 0;
}