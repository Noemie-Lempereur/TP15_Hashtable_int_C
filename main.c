#include <stdio.h>
#include "hashTableInt.h"

int main() {
    struct HashTable *ht =createEmptyHashTable(50);
    insert(ht,18);
    printHashTable(ht);
    return 0;
}
