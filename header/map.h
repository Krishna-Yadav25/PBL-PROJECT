#ifndef MAP_H
#define MAP_H

Pair *newPair(char *);
HashMap *initialise();
void insert(HashMap *, char *);
void sortMap(HashMap *);
void print(HashMap *);

#endif //MAP_H