#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int find_min(int a, int b){
    if(a > b){
        return b;
    }
    else{
        return a;
    }
}

void count_num(int *value, int start, int end, int *num){
    if(start == end){
        return;
    }
    int mid = (start + end - 1) / 2;
    int min = find_min(value[mid], value[mid+1]);
    int *left_need_right_pair = (int *)calloc(100001, sizeof(int));
    int *right_need_left_pair = (int *)calloc(100001, sizeof(int));
    int left_index = 0;
    int right_index = 0;
    int left_or_right = 1;
    while(left_index + right_index < (end - start + 1)){
        if(left_or_right == -1){
            if(right_index < end - mid){
                right_index++;
                if(min <= value[mid + right_index]){
                    if(value[mid + right_index] - min > 0){
                        right_need_left_pair[value[mid + right_index] - min]++;
                    }
                    if(value[mid + right_index] + min <= 100000){
                        right_need_left_pair[value[mid + right_index] + min]++;
                    }
                    *num += left_need_right_pair[value[mid + right_index]];
                }
            }
            left_or_right = 1;
        }
        else{
            if(left_index < mid - start + 1){
                left_index++;
                if(min <= value[mid - (left_index - 1)]){
                    if(value[mid - (left_index - 1)] - min > 0){
                        left_need_right_pair[value[mid - (left_index - 1)] - min]++;
                    }
                    if(value[mid - (left_index - 1)] + min <= 100000){
                        left_need_right_pair[value[mid - (left_index - 1)] + min]++;
                    }
                    *num += right_need_left_pair[value[mid - (left_index - 1)]];
                }
            }
            left_or_right = -1;
        }
    }

    free(left_need_right_pair);
    free(right_need_left_pair);

    count_num(value, start, mid, num);
    count_num(value, mid + 1, end, num);
}

int main(){
    int n;
    scanf("%d", &n);
    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }
    int num = 0;
    count_num(value, 0, n-1, &num);
    printf("%d", num);

    return 0;
}