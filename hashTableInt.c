//
// Created by Noémie on 04/05/2020.
//

#include "hashTableInt.h"

// Creates a hashtable of size "buckets", initializes each position to -1 and items to 0
struct HashTable* createEmptyHashTable(int buckets){
    struct HashTable *ht = malloc(sizeof(struct HashTable));
    if(ht!=NULL) {
        ht->items = 0;
        ht->buckets=buckets;
        ht->table= malloc((buckets)*sizeof(int));
        for (int i = 0; i < buckets; i++) {
            ht->table[i] = -1;
        }
    }
    return ht;
}

// Returns True if no items are in the table, False otherwise
bool isHashTableEmpty(struct HashTable* ht){
    if(ht!=NULL&&hashTableElements(ht)>0){
        return false;
    }
    return true;
}

// Returns the number of items present in the table
int hashTableElements(struct HashTable* ht){
    if(ht!=NULL){
        return ht->items;
    }
    return -1;
}

// Returns the hash of "value"
int hash_function(struct HashTable* ht, int value) {
    if (ht != NULL) {
        return (value % (ht->buckets));
    }
    return -1;
}

// If no collision, inserts "value" in the table and returns True, otherwise False
bool insert(struct HashTable* ht, int value){
    int indice=hash_function(ht,value);
    if(ht->table[indice]==-1){
        ht->table[indice]=value;
        ht->items=ht->items+1;
        return true;
    }
    return false;
}

// Returns True if "value" exists in the table and False otherwise
bool exists(struct HashTable* ht, int value){
    int hashIndex=hash_function(ht,value);
    if(ht->table[hash_function(ht,value)]==value){
        return true;
    }
    //int cur= ht->table[hashIndex];
    /*while(cur<ht->buckets){
        if(ht->table[cur]==value) {
            return true;
        }
        cur++;
    }*/
    return false;
}

// Shows the whole content of the table and its number of items
void printHashTable(struct HashTable* ht){
    if(ht!=NULL) {
        for(int i = 0; i <= (ht->buckets);i++) {
            if (ht->table[i] != -1) {
                printf("%d\n", ht->table[i]);
            }
        }
    }
}

// If present, deletes the item "value" in the table
void deleteItem(struct HashTable* ht, int value){
    if(ht!=NULL) {
        if(exists(ht, value)){
            int indice=hash_function(ht,value);
            ht->table[indice]=-1;
        }
        ht->items=ht->items-1;
    }
}

// Deletes the whole content of the table
void deleteHashTable(struct HashTable* ht){
    for(int i=0;i<ht->buckets;i++){
        ht->table[i]=-1;
    }
    ht->items=0;
    free(ht->table);
    free(ht);
}