GLOBSTEPS=3
STEPS=$GLOBSTEPS
THR=2
ROOT=$(pwd)
FILE=$ROOT/result.txt
echo executionTime,operationWithEmpty,writesAmountPerThread,readsAmountPerThread,writers,readers,emptyOperations,failedOperations,freedNodes >> $FILE
echo queue >> $FILE
# queue
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $FILE -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*queue*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# stack
STEPS=$GLOBSTEPS
THR=2
echo stack >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*stack*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# deque
STEPS=$GLOBSTEPS
THR=2
echo deque >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*deque*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# queue consumer
echo queue_consumer >> $FILE
STEPS=3
THR=2
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_consumer -out $FILE -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*queue*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# stack consumer
STEPS=$GLOBSTEPS
THR=2
echo stack_consumer >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_consumer -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*stack*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# deque consumer
STEPS=$GLOBSTEPS
THR=2
echo deque_producer >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_producer -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*deque*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# queue producer
echo queue_producer >> $FILE
STEPS=$GLOBSTEPS
THR=2
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_producer -out $FILE -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*queue*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# stack producer
STEPS=$GLOBSTEPS
THR=2
echo stack_producer >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_producer -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*stack*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done
# deque producer
STEPS=$GLOBSTEPS
THR=2
echo deque_producer >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress_producer -out $FILE  -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*deque*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done



