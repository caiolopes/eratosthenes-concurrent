all:
	gcc sequential.c -o build/sequential
	gcc parallel_control.c -o build/parallel_control -lm -fopenmp
	gcc parallel_data.c -o build/parallel_data -fopenmp

clean:
	rm -rf build/*
