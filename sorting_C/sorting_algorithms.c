//
//  sorting_algorithms.c
//  sorting_algorithms
//
//  Created by Mert Kaya on 2019-11-30.
//  Copyright © 2019 Mert Kaya. All rights reserved.
//

#include "sorting_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void printList(int* list, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", *list);
        list++;
    }
    printf("\n");
}

void _merge(int* lst, int start, int mid, int end){
    int *a = (int*) malloc(sizeof(int) * (mid - start));
    int *a_keep = a;
    
    int size_a = mid - start;
    int a_index = 0;
    int b_index = mid;
    int lst_index = start;
    
    int i;
    for (i = 0; i < mid - start; i++){
        a[i] = lst[start + i];
    }
    while(a_index < size_a && b_index < end){
        if (*a > lst[b_index]){
            lst[lst_index] = lst[b_index];
            b_index++;
        }else{
            lst[lst_index] = *a;
            a++;
            a_index++;
        }
        lst_index++;
    }
    if (a_index < size_a){
        while (a_index < size_a){
            lst[lst_index] = *a;
            a++;
            a_index++;
            lst_index++;
        }
    }
    free(a_keep);
}

void merge_sort(int* list, int start, int end){
    if (end-start < 2){
        return;
    }
    int mid = (end + start) / 2;
    merge_sort(list, start, mid);//left
    merge_sort(list, mid, end);//right
    _merge(list, start, mid, end);
}

void _swap(int* list, int small_i, int big_i){
    int temp = list[small_i];
    list[small_i] = list[big_i];
    list[big_i] = temp;
}

int _partition(int* list, int start, int end){
    int pivot = list[start];
    int *list_keep = list;
    list = &(list[start+1]);
    
    int small_i = 0;
    int big_i = end - start - 2;
    
    bool small_inc = false;
    
    while (big_i > small_i){
        small_inc = false;
        
        if (list[small_i] < pivot){
            small_i++;
            small_inc = true;
        }else{
            _swap(list, small_i, big_i);
            big_i--;
        }
    }

    if (!small_inc){
        small_i++;
    }
    list = list_keep;
    _swap(list, start, small_i + start);
    return small_i + start;
}

void quick_sort(int *list, int start, int end){
    if (end - start < 2){
        return;
    }
    
    int pivot_i = _partition(list, start, end);
    quick_sort(list, start, pivot_i);
    quick_sort(list, pivot_i + 1, end);
}
