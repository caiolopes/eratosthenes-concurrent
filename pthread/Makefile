all:
	gcc sequential.c -o build/sequential
	gcc control.c -pthread -lm -o build/control
	g++ eratosthenes_seq.cpp -o build/e_seq
	g++ eratosthenes_data.cpp -o build/e_data -pthread

clean:
	rm -rf build/*
