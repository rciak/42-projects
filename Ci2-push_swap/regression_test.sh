#! /bin/bash

echo
echo "***************************************************"
echo "Building manual-test and renaming it to ./push_swap"
# Perplexity helped with wrongly placed > /dev/null (having no effect on make when placed at the end)
make DEBUG_VALGRIND=1 manual-test > /dev/null; cp 42-eva-lua/Ci2-push_swap-crtests/manual_test_push_swap .; mv manual_test_push_swap push_swap 
echo "Executing tests ...  "
echo '--'

./push_swap 1   |./checker_linux             1 
./push_swap 1 2     |./checker_linux           1 2 
./push_swap 2 1     |./checker_linux           2 1 
./push_swap 1 2 3       |./checker_linux         1 2 3 
./push_swap 2 3 1       |./checker_linux         2 3 1 
./push_swap 3 1 2       |./checker_linux         3 1 2 
./push_swap 3 2 1       |./checker_linux         3 2 1 
./push_swap 2 1 3       |./checker_linux         2 1 3 
./push_swap 1 3 2       |./checker_linux         1 3 2 
./push_swap 1 2 3 4         |./checker_linux       1 2 3 4 
./push_swap 1 2 4 3         |./checker_linux       1 2 4 3 
./push_swap 1 3 2 4         |./checker_linux       1 3 2 4 
./push_swap 1 3 4 2         |./checker_linux       1 3 4 2 
./push_swap 1 4 2 3         |./checker_linux       1 4 2 3 
./push_swap 1 4 3 2         |./checker_linux       1 4 3 2 
./push_swap 2 1 3 4         |./checker_linux       2 1 3 4 
./push_swap 2 1 4 3         |./checker_linux       2 1 4 3 
./push_swap 2 3 1 4         |./checker_linux       2 3 1 4 
./push_swap 2 3 4 1         |./checker_linux       2 3 4 1 
./push_swap 2 4 1 3         |./checker_linux       2 4 1 3 
./push_swap 2 4 3 1         |./checker_linux       2 4 3 1 
./push_swap 3 1 2 4         |./checker_linux       3 1 2 4 
./push_swap 3 1 4 2         |./checker_linux       3 1 4 2 
./push_swap 3 2 1 4         |./checker_linux       3 2 1 4 
./push_swap 3 2 4 1         |./checker_linux       3 2 4 1 
./push_swap 3 4 1 2         |./checker_linux       3 4 1 2 
./push_swap 3 4 2 1         |./checker_linux       3 4 2 1 
./push_swap 4 1 2 3         |./checker_linux       4 1 2 3 
./push_swap 4 1 3 2         |./checker_linux       4 1 3 2 
./push_swap 4 2 1 3         |./checker_linux       4 2 1 3 
./push_swap 4 2 3 1         |./checker_linux       4 2 3 1 
./push_swap 4 3 1 2         |./checker_linux       4 3 1 2 
./push_swap 4 3 2 1         |./checker_linux       4 3 2 1 
./push_swap 1 2 3 4 5           |./checker_linux     1 2 3 4 5 
./push_swap 1 2 3 5 4           |./checker_linux     1 2 3 5 4 
./push_swap 1 2 4 3 5           |./checker_linux     1 2 4 3 5 
./push_swap 1 2 4 5 3           |./checker_linux     1 2 4 5 3 
./push_swap 1 2 5 3 4           |./checker_linux     1 2 5 3 4 
./push_swap 1 2 5 4 3           |./checker_linux     1 2 5 4 3 
./push_swap 1 3 2 4 5           |./checker_linux     1 3 2 4 5 
./push_swap 1 3 2 5 4           |./checker_linux     1 3 2 5 4 
./push_swap 1 3 4 2 5           |./checker_linux     1 3 4 2 5 
./push_swap 1 3 4 5 2           |./checker_linux     1 3 4 5 2 
./push_swap 1 3 5 2 4           |./checker_linux     1 3 5 2 4 
./push_swap 1 3 5 4 2           |./checker_linux     1 3 5 4 2 
./push_swap 1 4 2 3 5           |./checker_linux     1 4 2 3 5 
./push_swap 1 4 2 5 3           |./checker_linux     1 4 2 5 3 
./push_swap 1 4 3 2 5           |./checker_linux     1 4 3 2 5 
./push_swap 1 4 3 5 2           |./checker_linux     1 4 3 5 2 
./push_swap 1 4 5 2 3           |./checker_linux     1 4 5 2 3 
./push_swap 1 4 5 3 2           |./checker_linux     1 4 5 3 2 
./push_swap 1 5 2 3 4           |./checker_linux     1 5 2 3 4 
./push_swap 1 5 2 4 3           |./checker_linux     1 5 2 4 3 
./push_swap 1 5 3 2 4           |./checker_linux     1 5 3 2 4 
./push_swap 1 5 3 4 2           |./checker_linux     1 5 3 4 2 
./push_swap 1 5 4 2 3           |./checker_linux     1 5 4 2 3 
./push_swap 1 5 4 3 2           |./checker_linux     1 5 4 3 2 
./push_swap 2 1 3 4 5           |./checker_linux     2 1 3 4 5 
./push_swap 2 1 3 5 4           |./checker_linux     2 1 3 5 4 
./push_swap 2 1 4 3 5           |./checker_linux     2 1 4 3 5 
./push_swap 2 1 4 5 3           |./checker_linux     2 1 4 5 3 
./push_swap 2 1 5 3 4           |./checker_linux     2 1 5 3 4 
./push_swap 2 1 5 4 3           |./checker_linux     2 1 5 4 3 
./push_swap 2 3 1 4 5           |./checker_linux     2 3 1 4 5 
./push_swap 2 3 1 5 4           |./checker_linux     2 3 1 5 4 
./push_swap 2 3 4 1 5           |./checker_linux     2 3 4 1 5 
./push_swap 2 3 4 5 1           |./checker_linux     2 3 4 5 1 
./push_swap 2 3 5 1 4           |./checker_linux     2 3 5 1 4 
./push_swap 2 3 5 4 1           |./checker_linux     2 3 5 4 1 
./push_swap 2 4 1 3 5           |./checker_linux     2 4 1 3 5 
./push_swap 2 4 1 5 3           |./checker_linux     2 4 1 5 3 
./push_swap 2 4 3 1 5           |./checker_linux     2 4 3 1 5 
./push_swap 2 4 3 5 1           |./checker_linux     2 4 3 5 1 
./push_swap 2 4 5 1 3           |./checker_linux     2 4 5 1 3 
./push_swap 2 4 5 3 1           |./checker_linux     2 4 5 3 1 
./push_swap 2 5 1 3 4           |./checker_linux     2 5 1 3 4 
./push_swap 2 5 1 4 3           |./checker_linux     2 5 1 4 3 
./push_swap 2 5 3 1 4           |./checker_linux     2 5 3 1 4 
./push_swap 2 5 3 4 1           |./checker_linux     2 5 3 4 1 
./push_swap 2 5 4 1 3           |./checker_linux     2 5 4 1 3 
./push_swap 2 5 4 3 1           |./checker_linux     2 5 4 3 1 
./push_swap 3 1 2 4 5           |./checker_linux     3 1 2 4 5 
./push_swap 3 1 2 5 4           |./checker_linux     3 1 2 5 4 
./push_swap 3 1 4 2 5           |./checker_linux     3 1 4 2 5 
./push_swap 3 1 4 5 2           |./checker_linux     3 1 4 5 2 
./push_swap 3 1 5 2 4           |./checker_linux     3 1 5 2 4 
./push_swap 3 1 5 4 2           |./checker_linux     3 1 5 4 2 
./push_swap 3 2 1 4 5           |./checker_linux     3 2 1 4 5 
./push_swap 3 2 1 5 4           |./checker_linux     3 2 1 5 4 
./push_swap 3 2 4 1 5           |./checker_linux     3 2 4 1 5 
./push_swap 3 2 4 5 1           |./checker_linux     3 2 4 5 1 
./push_swap 3 2 5 1 4           |./checker_linux     3 2 5 1 4 
./push_swap 3 2 5 4 1           |./checker_linux     3 2 5 4 1 
./push_swap 3 4 1 2 5           |./checker_linux     3 4 1 2 5 
./push_swap 3 4 1 5 2           |./checker_linux     3 4 1 5 2 
./push_swap 3 4 2 1 5           |./checker_linux     3 4 2 1 5 
./push_swap 3 4 2 5 1           |./checker_linux     3 4 2 5 1 
./push_swap 3 4 5 1 2           |./checker_linux     3 4 5 1 2 
./push_swap 3 4 5 2 1           |./checker_linux     3 4 5 2 1 
./push_swap 3 5 1 2 4           |./checker_linux     3 5 1 2 4 
./push_swap 3 5 1 4 2           |./checker_linux     3 5 1 4 2 
./push_swap 3 5 2 1 4           |./checker_linux     3 5 2 1 4 
./push_swap 3 5 2 4 1           |./checker_linux     3 5 2 4 1 
./push_swap 3 5 4 1 2           |./checker_linux     3 5 4 1 2 
./push_swap 3 5 4 2 1           |./checker_linux     3 5 4 2 1 
./push_swap 4 1 2 3 5           |./checker_linux     4 1 2 3 5 
./push_swap 4 1 2 5 3           |./checker_linux     4 1 2 5 3 
./push_swap 4 1 3 2 5           |./checker_linux     4 1 3 2 5 
./push_swap 4 1 3 5 2           |./checker_linux     4 1 3 5 2 
./push_swap 4 1 5 2 3           |./checker_linux     4 1 5 2 3 
./push_swap 4 1 5 3 2           |./checker_linux     4 1 5 3 2 
./push_swap 4 2 1 3 5           |./checker_linux     4 2 1 3 5 
./push_swap 4 2 1 5 3           |./checker_linux     4 2 1 5 3 
./push_swap 4 2 3 1 5           |./checker_linux     4 2 3 1 5 
./push_swap 4 2 3 5 1           |./checker_linux     4 2 3 5 1 
./push_swap 4 2 5 1 3           |./checker_linux     4 2 5 1 3 
./push_swap 4 2 5 3 1           |./checker_linux     4 2 5 3 1 
./push_swap 4 3 1 2 5           |./checker_linux     4 3 1 2 5 
./push_swap 4 3 1 5 2           |./checker_linux     4 3 1 5 2 
./push_swap 4 3 2 1 5           |./checker_linux     4 3 2 1 5 
./push_swap 4 3 2 5 1           |./checker_linux     4 3 2 5 1 
./push_swap 4 3 5 1 2           |./checker_linux     4 3 5 1 2 
./push_swap 4 3 5 2 1           |./checker_linux     4 3 5 2 1 
./push_swap 4 5 1 2 3           |./checker_linux     4 5 1 2 3 
./push_swap 4 5 1 3 2           |./checker_linux     4 5 1 3 2 
./push_swap 4 5 2 1 3           |./checker_linux     4 5 2 1 3 
./push_swap 4 5 2 3 1           |./checker_linux     4 5 2 3 1 
./push_swap 4 5 3 1 2           |./checker_linux     4 5 3 1 2 
./push_swap 4 5 3 2 1           |./checker_linux     4 5 3 2 1 
./push_swap 5 1 2 3 4           |./checker_linux     5 1 2 3 4 
./push_swap 5 1 2 4 3           |./checker_linux     5 1 2 4 3 
./push_swap 5 1 3 2 4           |./checker_linux     5 1 3 2 4 
./push_swap 5 1 3 4 2           |./checker_linux     5 1 3 4 2 
./push_swap 5 1 4 2 3           |./checker_linux     5 1 4 2 3 
./push_swap 5 1 4 3 2           |./checker_linux     5 1 4 3 2 
./push_swap 5 2 1 3 4           |./checker_linux     5 2 1 3 4 
./push_swap 5 2 1 4 3           |./checker_linux     5 2 1 4 3 
./push_swap 5 2 3 1 4           |./checker_linux     5 2 3 1 4 
./push_swap 5 2 3 4 1           |./checker_linux     5 2 3 4 1 
./push_swap 5 2 4 1 3           |./checker_linux     5 2 4 1 3 
./push_swap 5 2 4 3 1           |./checker_linux     5 2 4 3 1 
./push_swap 5 3 1 2 4           |./checker_linux     5 3 1 2 4 
./push_swap 5 3 1 4 2           |./checker_linux     5 3 1 4 2 
./push_swap 5 3 2 1 4           |./checker_linux     5 3 2 1 4 
./push_swap 5 3 2 4 1           |./checker_linux     5 3 2 4 1 
./push_swap 5 3 4 1 2           |./checker_linux     5 3 4 1 2 
./push_swap 5 3 4 2 1           |./checker_linux     5 3 4 2 1 
./push_swap 5 4 1 2 3           |./checker_linux     5 4 1 2 3 
./push_swap 5 4 1 3 2           |./checker_linux     5 4 1 3 2 
./push_swap 5 4 2 1 3           |./checker_linux     5 4 2 1 3 
./push_swap 5 4 2 3 1           |./checker_linux     5 4 2 3 1 
./push_swap 5 4 3 1 2           |./checker_linux     5 4 3 1 2 
./push_swap 5 4 3 2 1           |./checker_linux     5 4 3 2 1


bash -c 'ARG="1 2 3 4 7 6 5"; ./push_swap $ARG | ./checker_linux $ARG'
bash -c 'ARG="1 4 2 7 3 8 5"; ./push_swap $ARG | ./checker_linux $ARG'
bash -c 'ARG="10 40 20 70 30 80 50 60"; ./push_swap $ARG |./checker_linux $ARG'
#
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -726"; ./push_swap $ARG |./checker_linux $ARG'
bash -c 'ARG="10 13 5 9 12 7 1 3 6 14 2 8 11 4"; ./push_swap $ARG |./checker_linux $ARG'
#
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -922 785 -726 -330 1175 -61 337"; ./push_swap $ARG |./checker_linux $ARG'
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -922 785 -726 -330 1175 -61 337 417 375"; ./push_swap $ARG |./checker_linux $ARG'
bash -c 'ARG="13 19 6 12 15 9 1 4 7 21 2 10 14 3 20 5 8 22 11 16 18 17"; ./push_swap $ARG | ./checker_linux $ARG'


##Currently failing
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -922 785 -726 -330 1175 -61 337 417 375 120 -188 -743 954 728 299 343 -562 -854 -280 1120 1083 393 -741 648 537 333 -790 -946"; ./push_swap $ARG |./checker_linux $ARG'
 

echo "--"
echo "regression_test.sh: All test executed"
echo "They passed iff there is no error output"
echo "like 'KO' between the two little dashed lines"

