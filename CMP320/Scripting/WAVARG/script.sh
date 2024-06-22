#!/bin/bash

args=("$@") # store any args in this list

sed -e 's/\\x1b\[[0-9;]*[mK]//g' -e 's/\r//g' -e 's/\\n//g' ${args[0]} > ${args[1]} # resultsX.txt > temp_resultsX.txt
tr -d '\r\x1b' < ${args[1]} > ${args[0]} # temp_resultsX.txt > resultsX.txt
sed -i 's/\\r\\r\\\[A\\r//g' ${args[0]} # resultsX.txt
sed 's/                                                                                                                  /\n/g' ${args[0]} > ${args[2]} # resultsX.txt > final_resultsX.txt
sed 's/                          /\n/g' ${args[2]} > ${args[3]} # final_results.txt > finalfinalresultsX.txt