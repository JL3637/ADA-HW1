#include<stdio.h>

void counting(int start, int end, int *num, int n, int *cnt){
    int middle = (start + end - 1) / 2;

    if(start == end){
        *cnt += 2;
        *num += 1;
        return;
    }
    for(int i = middle + 1; i <= end; i++){
        *cnt += 1;
    }
    counting(start, middle, num, n, cnt);
    for(int i = middle + 1; i <= end+1; i++){
        *cnt += 1;
    }
    for(int i = start; i <= middle; i++){
        *cnt += 1;
    }
    counting(middle + 1, end, num, n, cnt);
    for(int i = start; i <= middle; i++){
        if(*num != n){
            *cnt += 1;
        }
    }
}

void divide_conquer(int start, int end, int *num, int n){
    int middle = (start + end - 1) / 2;

    if(start == end){
        printf("PLACE %d\n", start);
        printf("PHOTO\n");
        *num += 1;
        return;
    }
    for(int i = middle + 1; i <= end; i++){
        printf("PLACE %d\n", i);
    }
    divide_conquer(start, middle, num, n);
    for(int i = middle + 1; i <= end+1; i++){
        printf("POP\n");
    }
    for(int i = start; i <= middle; i++){
        printf("PLACE %d\n", i);
    }
    divide_conquer(middle + 1, end, num, n);
    for(int i = start; i <= middle; i++){
        if(*num != n){
            printf("POP\n");
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int num = 0;
    int cnt = 0;
    counting(1, n, &num, n, &cnt);
    printf("%d\n", cnt);
    num = 0;
    divide_conquer(1, n, &num, n);

    return 0;
}