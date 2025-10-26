#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "map.h"

typedef struct Pair {
    char key[100];
    int value;
}Pair;

typedef struct HashMap {
    Pair **list;
    int capacity, length;
}HashMap;

Pair *newPair(char *key) {
    Pair *this = (Pair *)malloc(sizeof(Pair));
    strcpy(this->key, key) ;
    this->value = 1;
    return this;
}

HashMap *initialise() {
    HashMap *this = (HashMap *)malloc(sizeof(HashMap));
    this->capacity = 100;
    this->length = 0;
    this->list = (Pair **)calloc(this->capacity, sizeof(Pair *));
    return this;
}

void insert(HashMap *map, char *key) {
    if (map->length == map->capacity) return;   
    for (int i=0; i<map->length; i++) {
        if (!strcmp(map->list[i]->key, key)) {
            map->list[i]->value++;
            return;
        }
    }
    map->list[map->length] = newPair(key);
    map->length++;
}

void sortMap(HashMap *map) {
    if (map->length == 0 || map->length == 1) return;
    for (int i=0; i<map->length-1; i++) {
        for (int j=i+1; j<map->length; j++) {
            if (map->list[i]->value < map->list[j]->value) {
                Pair *temp = map->list[i];
                map->list[i] = map->list[j];
                map->list[j] = temp;
            }
        }
    }
}

void print(HashMap *map) {
    for (int i=0; i<map->length; i++) {
        printf("[%s : %d]\n", map->list[i]->key, map->list[i]->value);
    }
}
