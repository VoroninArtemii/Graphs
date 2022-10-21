#include "graph.h"

int getint(){
    	int a;
	while(!scanf("%d", &a) || a<0){
		printf("Incorrect symbol! Repeat, please!\n");
		scanf("%*c");
	}
	return a;
}

char *getstring(){
	char *string=(char*)malloc(256);
	scanf("%s", string);
	return string;
}

graph *initgraph(){
	graph *data=malloc(sizeof(graph));
	data->size=0;
	data->dictionary=NULL;
	data->matrix=NULL;
	return data;
}

void addvertex(graph *data){
	printf("Enter vertex:\n");
	char *string=getstring();
	printf("\n");
	for (int i=0; i<data->size; i++){
		if (!strcmp((data->dictionary[i].id), string)){
			printf("Already in the graph!\n\n");
			free(string);
			return;
		}
	}
	data->size++;
	if (!(data->size-1)){
		data->dictionary=(pair*)malloc(sizeof(pair));
		data->dictionary[0].number=0;
		data->dictionary[0].id=string;
		data->matrix=(int**)malloc(sizeof(int*));
		data->matrix[0]=(int*)malloc(sizeof(int));
                data->matrix[0][0]=INT_MAX;
	}else{
                data->dictionary=(pair*)realloc(data->dictionary, data->size*sizeof(pair));
		pair element={data->size-1, string};
		data->dictionary[data->size-1]=element;
		data->matrix=(int**)realloc(data->matrix, data->size*sizeof(int*));
		for (int i=0; i<data->size-1; i++){
			data->matrix[i]=(int*)realloc(data->matrix[i], data->size*sizeof(int));
			data->matrix[i][data->size-1]=INT_MAX;
		}
		data->matrix[data->size-1]=(int*)malloc(data->size*sizeof(int));
               	for (int j=0; j<data->size; j++){
	                data->matrix[data->size-1][j]=INT_MAX;
                }
	}
}

void addedge(graph *data){
	printf("Enter first vertex:\n");
	char *string1=getstring();
	printf("\n");
	printf("Enter second vertex:\n");
	char *string2=getstring();
	printf("\n");
	int weight;
	printf("Enter weight of the edge:\n");
	while(!(weight=getint())){
		printf("Incorrect symbol! Repeat, please!\n");
	}
	printf("\n");
	int v1=-1;
	int v2=-1;
	for (int i=0; i<data->size; i++){
		if (strcmp(data->dictionary[i].id, string1)==0){
			v1=data->dictionary[i].number;
		}
		if (strcmp(data->dictionary[i].id, string2)==0){
			v2=data->dictionary[i].number;
		}
	}
	if (v1==-1 || v2==-1){
		printf("There is no this edge in the graph!\n\n");
		free(string1);
		free(string2);
		return;
	}
	data->matrix[v1][v2]=weight;
	data->matrix[v2][v1]=weight;
	free(string1);
	free(string2);
}

void deleteedge(graph *data){
	printf("Enter first vertex:\n");
	char *string1=getstring();
	printf("\n");
	printf("Enter second vertex:\n");
	char *string2=getstring();
	printf("\n");
	int v1=-1;
	int v2=-1;
	for (int i=0; i<data->size; i++){
		if (strcmp(data->dictionary[i].id, string1)==0){
			v1=data->dictionary[i].number;
		}
		if (strcmp(data->dictionary[i].id, string2)==0){
			v2=data->dictionary[i].number;
		}
	}
	if (v1==-1 || v2==-1){
		printf("There is no this edge in the graph!\n\n");
		free(string1);
		free(string2);
		return;
	}
	data->matrix[v1][v2]=INT_MAX;
	data->matrix[v2][v1]=INT_MAX;
	free(string1);
	free(string2);
}

void deletevertex(graph* data){
	printf("Enter vertex:\n");
	char *string=getstring();
	printf("\n");
	int v=-1;
	int flag=0;
	for (int i=0; i<data->size; i++){
		if (strcmp(data->dictionary[i].id, string)==0){
			v=data->dictionary[i].number;
		}
	}
	if (v==-1){
		printf("There is no this vertex in the graph!\n\n");
		free(string);
		return;
	}
	for (int i=0; i<data->size-1; i++){
		if (i>=v){
			if (i==v){
				flag=1;
				free(data->dictionary[i].id);
				free(data->matrix[i]);
			}
			data->dictionary[i]=data->dictionary[i+1];
			data->dictionary[i].number--;
			data->matrix[i]=data->matrix[i+1];
		}
		for (int j=0; j<data->size-1; j++){
			if (j>=v){
				data->matrix[i][j]=data->matrix[i][j+1];
			}
		}
		data->matrix[i]=(int*)realloc(data->matrix[i], (data->size-1)*sizeof(int));
	}
	if (flag==0){
		free(data->dictionary[v].id);
		free(data->matrix[v]);
	}
	data->dictionary=(pair*)realloc(data->dictionary, (data->size-1)*sizeof(pair));
	data->matrix=(int**)realloc(data->matrix, (data->size-1)*sizeof(int*));
	data->size--;
	free(string);

}

void path(graph* data){
        printf("Enter first vertex:\n");
        char *string1=getstring();
        printf("\n");
        printf("Enter second vertex:\n");
        char *string2=getstring();
        printf("\n");
        int v1=-1;
        int v2=-1;
        for (int i=0; i<data->size; i++){
                if (strcmp(data->dictionary[i].id, string1)==0){
                        v1=data->dictionary[i].number;
                }
                if (strcmp(data->dictionary[i].id, string2)==0){
                        v2=data->dictionary[i].number;
                }
        }
        if (v1==-1 || v2==-1){
                printf("There is no these vertexes in the graph!\n\n");
                free(string1);
                free(string2);
                return;
        }
	int *colour=(int*)calloc(data->size, sizeof(int));
	int length=1;
	int *way=(int*)malloc(sizeof(int)*length);
	way[0]=v1;
	int now=v1;
	while (1){
		int flag=0;
		for (int i=0; i<data->size; i++){
			if (data->matrix[now][i]!=INT_MAX && colour[i]==0){
				length++;
				way=(int*)realloc(way, length*sizeof(int));
				way[length-1]=i;
				colour[now]=1;
				now=i;
				flag=1;
				break;
			}
		}
		if (!flag){
			colour[now]=2;
			for (int i=0; i<data->size; i++){
				if (colour[i]==1){
					length--;
					way=(int*)realloc(way, length*sizeof(int));
					now=i;
					break;
				}
			}
			printf("There is no a path between these two vertex!\n\n");
			free(string1);
			free(string2);
			free(colour);
			free(way);
			return;
		}
		if (now==v2){
			free(string1);
			free(string2);
			free(colour);
			printf("Way:\n");
			for (int i=0; i<length; i++){
				printf("%s ", data->dictionary[way[i]].id);
			}
			free(way);
			printf("\n\n");
			return;
		}
	}
}

void freegraph(graph *data){
	for (int i=0; i<data->size; i++){
        	free(data->matrix[i]);
        }
	free(data->matrix);
	for (int i=0; i<data->size; i++){
		free(data->dictionary[i].id);
	}
	free(data->dictionary);
	free(data);
}
