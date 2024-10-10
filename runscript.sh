#!/bin/zsh
for i in $(seq 4 13); do
  for j in $(seq 0 20);do
    ./a.out $i 100000 0 >> ./tests/ultraTests/teste_$i-$j
    # ./src/main < ./tests/ultraTests/teste_$i-$j >> ./tests/ultraTimes/teste_$i
  done
done
