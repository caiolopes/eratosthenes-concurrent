all:
	g++ eratosthenes_seq.cpp -o build/e_seq
	gcc eratosthenes_con.c -pthread -o build/e_con	
	g++ trial_division.cpp -o build/td

td:
	./build/td ${N}

e_seq:
	./build/e_seq ${N}

e_con:
	./build/e_con ${N} ${T}

clean:
	rm -rf build/*
