#!/bin/bash
# runs 10 loops of send/receive on test.txt compares and outputs
rm bandwidth.txt
touch bandwidth.txt
s=10
for ((i = 0 ; i < $1 ; i++)); do
  if [ "$i" -lt "$s" ]; then
  	printf "test0$i\n"
	  ./receiver output0$i.txt &
	  BACK_PID=$!
  else
	  printf "test$i\n"
	  ./receiver output$i.txt &
	  BACK_PID=$!
	  
  fi
  ./sender test.txt
  wait $BACK_PID
  
done
./compare $1 test.txt
