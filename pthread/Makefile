all:
	gcc parallel_control.c -o build/parallel_control -pthread -lm
	g++ parallel_data.cpp -o build/parallel_data -pthread
	g++ sequential.cpp -o build/sequential

clean:
	rm -rf build/*
