COUNTER=25
STEPS=20
THR=2
echo executionTime,operationWithEmpty,writesAmountPerThread,readsAmountPerThread,writers,readers,emptyOperations,failedOperations,freedNodes
while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=3
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $HOME/result.txt -wa 1000000 -ra 1000000 -wt $THR -rt $THR --gtest_filter=*queue*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done