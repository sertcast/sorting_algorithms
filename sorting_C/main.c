//
//  main.c
//  sorting_C
//
//  Created by Mert Kaya on 2019-11-30.
//  Copyright © 2019 Mert Kaya. All rights reserved.
//

#include "sorting_algorithms.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {0, 0, 100, 50, -5, 70, 101, 50, 0, 0};
    
    merge_sort(a, 2, 8);
    
    printList(a, (int)sizeof(a)/4);
    return 0;
}
