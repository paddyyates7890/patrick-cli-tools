all:
	cc src/main.c src/cli/interface.c src/app/app.c -o main


clean:
	rm -f main


