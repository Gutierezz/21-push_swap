#!bin/bash

echo 'PUSH SWAP WITH WRONG OR EMPTY INPUT'
valgrind ./push_swap 2>&1 | grep lost
valgrind ./push_swap "1 2 1 3" 2>&1 | grep lost
valgrind ./push_swap "2 2" 2>&1 | grep lost
valgrind ./push_swap "a 2" 2>&1 | grep lost
valgrind ./push_swap 2 - 2>&1 | grep lost
valgrind ./push_swap 2 2 2>&1 | grep lost
valgrind ./push_swap a 2 2>&1 | grep lost
valgrind ./push_swap "2147483649" 2>&1 | grep lost
valgrind ./push_swap "3 4 1" 4 2>&1 | grep lost
valgrind ./push_swap "2 1 4 7 4" "7 8 3 6 4 9" 2>&1 | grep lost
echo 'PUSH SWAP CORRECT INPUT'
valgrind ./push_swap 1 2>&1 | grep lost
valgrind ./push_swap 1 2 3 4 5 2>&1 | grep lost
valgrind ./push_swap 4 3 7 1 2 2>&1 | grep lost
valgrind ./push_swap 1 7 8 2 5 10 22 -3 -25 2>&1 | grep lost
valgrind ./push_swap -4 1024 22 "74 -65 -11 951 23" 42 2>&1 | grep lost
valgrind ./push_swap "1 7 8 -3 12 11 2" "-9 5 15 10 22 -25" 2>&1 | grep lost
echo 'CHECKER WITH WRONG OR EMPTY INPUT'
echo "rr" | valgrind ./checker 2>&1 | grep lost
echo "rra" | valgrind ./checker -v 2>&1 | grep lost
echo "ss" | valgrind ./checker 42 2>&1 | grep lost
echo "" | valgrind ./checker -v 42 2>&1 | grep lost
echo "sa" | valgrind ./checker "1 2 1 3" 2>&1 | grep lost
echo "ra" | valgrind ./checker "2 2" 2>&1 | grep lost
echo "sa" | valgrind ./checker "a 2" 2>&1 | grep lost
echo "pb" | valgrind ./checker "2147483649" 2>&1 | grep lost
echo "sa" | valgrind ./checker 1 7 8 2 5 2 1 10 22 -3 -25 2>&1 | grep lost
echo "sa " | valgrind ./checker "1 2" 2>&1 | grep lost
echo "  sa" | valgrind ./checker 1 2 2>&1 | grep lost
echo "-v" | valgrind ./checker 1 2 2>&1 | grep lost
echo "sss" | valgrind ./checker -v 1 2 2>&1 | grep lost
echo " rrrr" | valgrind ./checker 1 2 2>&1 | grep lost
echo 'CHECKER WITH CORRECT INPUT'
echo "pb" | valgrind ./checker 1 2 3 4 5 2>&1 | grep lost
echo "pb" | valgrind ./checker "4 3 7 1 2" 2>&1 | grep lost
echo "sa" | valgrind ./checker -v 1 2 3 4 5 2>&1 | grep lost
echo "sa" | valgrind ./checker 4 3 7 1 2 2>&1 | grep lost
echo "sa" | valgrind ./checker -v "1 7 8 2 5 10 22 -3 -25" 2>&1 | grep lost
echo "rr" | valgrind ./checker -4 1024 22 74 -65 -11 951 23 42 2>&1 | grep lost
echo "sa" valgrind ./checker -v 1 7 8 -3 12 11 2 -9 5 15 10 22 -25 2>&1 | grep lost
echo "MIXED"
ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $ARG | valgrind ./checker $ARG 2>&1 | grep lost
ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG 2>&1 | grep lost
ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $ARG | valgrind ./checker $ARG 2>&1 | grep lost
ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG 2>&1 | grep lost
