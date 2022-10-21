#include "graph.h"

void print(graph *data){
	printf("MATRIX:\n");
        for (int i=0; i<data->size; i++){
		printf("%s ", data->dictionary[i].id);
        }
	printf("\n");
	for (int i=0; i<data->size; i++){
		for (int j=0; j<data->size; j++){
			printf("%d ", (data->matrix[i])[j]);
		}
		printf("\n");
	}
	printf("\n");
}
