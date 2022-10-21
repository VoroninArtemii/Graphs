#include "graph.h"

void dialogue(){
	const char *commands[]={"0: Quit", "1. Add vertex", "2. Add edge", "3. Delete vertex", "4. Delete edge", "5. Print", "6. Path\n"};
	printf("\n");
	graph *data=initgraph();
	int res=sizeof(commands)/sizeof(commands[0]);
	while (res){
		char *error="";
		printf("MENU:\n");
        	for (int i=0; i<sizeof(commands)/sizeof(commands[0]); i++){
        		printf("%s\n", commands[i]);
		}
        	printf("Enter number of a command:\n");
		res=sizeof(commands)/sizeof(commands[0]);
        	while(res>=sizeof(commands)/sizeof(commands[0])){
                	printf("%s", error);
                	error="Incorrect symbol! Repeat, please!\n";
                	res=getint();
        	}
        	printf("\n");
		switch (res){
			case 0:
				break;
			case 1:
				addvertex(data);
				break;
			case 2:
				addedge(data);
				break;
			case 3:
				deletevertex(data);
				break;
			case 4:
				deleteedge(data);
				break;
			case 5:
				print(data);
				break;
			case 6:
				path(data);
				break;
		}
	}
	freegraph(data);
}
