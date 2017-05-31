.PHONY: clean help

help: src/help.txt
	@cat src/help.txt


clean:
	rm -rf build/

build: clean
	mkdir build
	gcc  src/pmanager.h src/pmanager.c src/pmanagermain.c -o  build/pmanager
	
	

