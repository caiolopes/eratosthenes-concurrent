#! /bin/bash
declare MEDS=0
declare MEDD=0
declare MEDC=0
SIZE=$1
THREADS=$2

for run in {1..10}
do
	START=$(date +%s.%N)
	./build/e_seq $SIZE
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDS=$(echo "$MEDS + $DIFF" | bc)

	START=$(date +%s.%N)
	./build/e_data $SIZE $THREADS
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDD=$(echo "$MEDD + $DIFF" | bc)

	START=$(date +%s.%N)
	./build/control $SIZE $THREADS
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDC=$(echo "$MEDC + $DIFF" | bc)

done
# MED=$(echo "$MED/$1" | bc)
echo $MEDS
echo $MEDD
echo $MEDC
