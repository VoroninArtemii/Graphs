#ifndef __graph__
#define __graph__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct pair{
	int number;
	char *id;
}pair;

typedef struct graph{
	int **matrix;
	int size;
	pair *dictionary;
}graph;

void dialogue();
void addvertex(graph*);
void addedge(graph*);
void freegraph(graph*);
void print(graph*);
void path(graph*);
void deletevertex(graph*);
void deleteedge(graph*);
int getint();
char *getstring();
graph *initgraph();

#endif
