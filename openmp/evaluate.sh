#! /bin/bash
declare MEDS=0
declare MEDD=0
declare MEDC=0
SIZE=$1
THREADS=$2
NTEST=$3

for run in $(seq 1 $NTEST)
do
	START=$(date +%s.%N)
	./build/sequential $SIZE
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDS=$(echo "$MEDS + $DIFF" | bc)

	START=$(date +%s.%N)
	./build/parallel_data $SIZE $THREADS
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDD=$(echo "$MEDD + $DIFF" | bc)

	START=$(date +%s.%N)
	./build/parallel_control $SIZE $THREADS
	END=$(date +%s.%N)
	DIFF=$(echo "$END - $START" | bc)
	MEDC=$(echo "$MEDC + $DIFF" | bc)

done
MEDS=$(echo "scale=9; $MEDS/$NTEST" | bc -l)
MEDD=$(echo "scale=9; $MEDD/$NTEST" | bc -l)
MEDC=$(echo "scale=9; $MEDC/$NTEST" | bc -l)

echo "Mean sequential: 		$MEDS"
echo "Mean data parallelism: 		$MEDD"
echo "Mean control parallelism: 	$MEDC"

SPEEDUPD=$(echo "scale=9; $MEDS/$MEDD" | bc -l)
SPEEDUPC=$(echo "scale=9; $MEDS/$MEDC" | bc -l)
EFD=$(echo "scale=9; $SPEEDUPD/$THREADS" | bc -l)
EFC=$(echo "scale=9; $SPEEDUPC/$THREADS" | bc -l)

echo "SpeedUp data: 			$SPEEDUPD"
echo "SpeedUp control: 		$SPEEDUPC"
echo "Efficiency data: 		$SPEEDUPD"
echo "Efficiency control: 		$SPEEDUPC"
