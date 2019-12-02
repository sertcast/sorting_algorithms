//
//  sorting_algorithms.h
//  sorting_algorithms
//
//  Created by Mert Kaya on 2019-11-30.
//  Copyright © 2019 Mert Kaya. All rights reserved.
//

#ifndef sorting_algorithms_h
#define sorting_algorithms_h

#include <stdio.h>

#endif /* sorting_algorithms_h */
/**
Sorts a part of a given list. This function mutates the list given.

Preconditions:
   0 <= start < end <= length of the list
*/
void merge_sort(int* list, int start, int end);

void quick_sort(int *list, int start, int end);

void printList(int* list, int size);
