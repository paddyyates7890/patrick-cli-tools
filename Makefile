files = src/cli/interface.c src/app/app.c src/app/help.c

all:
	cc src/main.c $(files) -o main


clean:
	rm -f main


