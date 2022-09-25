#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void push(int *stack, int *stack_top, int data){
    *stack_top += 1;
    stack[*stack_top] = data;
}

int find_min(int *arr, int n){
    int min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] <= min){
            min = arr[i];
        }
    }
    return min;
}

void optimal(int n, int *price, int *money, int *money_top, int w){
    for(int i = 1; i < price[0]; i++){
        push(money, money_top, i);
    }
    for(int i = price[0]; i <= w; i++){
        int option_num = 0;
        for(int j = 0; j < n; j++){
            if(i >= price[j]){
                option_num++;
            }
            else{
                break;
            }
        }
        int *options = (int *)malloc(sizeof(int) * option_num);
        for(int j = 0; j < option_num; j++){
            options[j] = i - price[j];
        }
        if(options[option_num - 1] == 0){
            push(money, money_top, 0);
        }
        else{
            int *x = (int *)malloc(sizeof(int) * option_num);
            for(int j = 0; j < option_num; j++){
                x[j] = money[options[j] - 1];
            }
            push(money, money_top, find_min(x, option_num));
            free(x);
        }
        free(options);
    }
    return;
}

void cash(int n, int w, int *price, int *money){
    int num = 0;
    for(int i = 1; i <= w; i++){
        num = i;
        for(int j = n-1; j >= 0; j--){
            num = num % price[j];
        }
        printf("%d\n", num - money[i-1]);
    }
    return;
}

int main(){
    int n = 0;
    int w = 0;
    scanf("%d%d", &n, &w);
    int *price = (int *)malloc(sizeof(int) * n);
    int *money = (int *)malloc(sizeof(int) * w);
    int money_top = -1;
    for(int i = 0; i < n; i++){
        scanf("%d", &price[i]);
    }
    sort(price, price + n);
    n = unique(price, price + n) - price;
    if(w < price[0]){
        for(int i = 1; i <= w; i++){
            push(money, &money_top, i);
        }
    }
    else{
        optimal(n, price, money, &money_top, w);
    }
    cash(n, w, price, money);

    return 0;
}