COUNTER=25
STEPS=20
THR=2

while [ "$STEPS" -ne  0 ]
do
	echo $STEPS
	COUNTER=3
	while [ "$COUNTER" -ne 0 ]
	do
		bin/tsdeque_stress -out $HOME/result.txt -wa 4000000 -ra 4000000 -wt $THR -rt $THR --gtest_filter=*queue*
		COUNTER=$(( $COUNTER - 1 ))
	done
	THR=$(( $THR + 1 ))
	STEPS=$(( $STEPS - 1 ))
done