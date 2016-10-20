compile: song_table.h song_table.c song_list.h song_list.c 
	gcc song_list.h
	gcc song_table.h
	gcc -c -g song_list.c
	gcc -c -g song_table.c
	gcc -c -g main.c
	gcc -g song_table.o song_list.o main.o

run: a.out
	./a.out

clean:
	rm *.gch
	rm *.dSYM
