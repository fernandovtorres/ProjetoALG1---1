#!/bin/zsh

for i in `ls ./tests/`; do
  ./src/main < ./tests/$(basename $i) >> ./results.txt
done
