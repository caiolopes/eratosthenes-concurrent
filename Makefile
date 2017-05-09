all:
	g++ eratosthenes_seq.cpp -o build/e_seq 
	g++ trial_division.cpp -o build/td

td:
	./build/td ${N}

e_seq:
	./build/e_seq ${N}

clean:
	rm -rf build/*
