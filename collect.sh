COUNTER=3
STEPS=10
THR=2
FILE=$HOME/result.txt
echo executionTime,operationWithEmpty,writesAmountPerThread,readsAmountPerThread,writers,readers,emptyOperations,failedOperations,freedNodes >> $FILE
echo queue >> $FILE
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

COUNTER=3
STEPS=10
THR=2
echo stack >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $HOME/result.txt -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*stack*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done

COUNTER=3
STEPS=10
THR=2
echo deque >> $FILE
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=5
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $HOME/result.txt -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*deque*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done

