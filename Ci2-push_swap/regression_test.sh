#! /bin/bash

echo "************"
echo "Preparing..."
echo "************"

# WITH AI Support:
cd ~/github/42-projects || exit 1
mkdir -p TEST
rsync -av --exclude='42-eva-lua' Ci2-push_swap TEST/Ci2-push_swap || exit 1
find TEST/Ci2-push_swap/src -type f -name "*.c" \
    -not -path "Ci2-push_swap/src/operations_basic/*" | while read -r file; do
        sed -i'' '/^ft_put/d' "$file"
done
cd TEST/Ci2-push_swap || exit 1

# END of PERPLEXITY supported SCRIPT
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

##Currently failing

echo "--"
echo "regression_test.sh: All test executed"
echo "They passed iff there is no error output"
echo "like 'KO' between the two little dashed lines"

