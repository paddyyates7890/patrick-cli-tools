files = src/cli/interface.c src/app/app.c src/app/help.c src/test/test.c src/cli/devtoolinterface.c src/app/devtool.c src/app/scripts.c src/cli/scriptsinterface.c src/files/fileLib.c

all:
	cc src/main.c $(files) -o main


clean:
	rm -f main


