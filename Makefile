clean:
	rm -rf main *.o
main: main.c view.c controller.c model.c
	gcc-11 main.c view.c controller.c model.c -o main
