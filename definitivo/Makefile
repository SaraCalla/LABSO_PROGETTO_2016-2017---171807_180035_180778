.PHONY: clean help

help: help.txt
	@cat help.txt


clean:
	rm -rf build/
	#rmdir -f build;

build: clean
	mkdir build
	gcc src/caso.h src/pmanager.c src/pmanagermain.c -o  build/pmanager.o 
	
	#compila il file c in questa cartella e rendilo eseguibile
	#touch pmanager;
	#chmod +x pmanager;

assets: build
	
