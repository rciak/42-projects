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
#
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -922 785 -726 -330 1175 -61 337 417 375 120 -188 -743 954 728 299 343 -562 -854 -280 1120 1083 393 -741 648 537 333 -790 -946"; ./push_swap $ARG |./checker_linux $ARG'
bash -c 'ARG="58 691 -519 6 320 -179 -997 -868 -353 1136 -984 -68 303 -922 785 -726 -330 1175 -61 337 417 375 120 -188 -743 954"; ./push_swap $ARG |./checker_linux $ARG'
bash -c 'ARG="15 22 7 14 18 11 1 4 8 25 2 12 17 3 23 6 9 26 13 19 21 20 16 10 5 24"; ./push_swap $ARG |./checker_linux $ARG'

bash -c 'ARG="5 812 -503 -666 636 -47 553 -229 -31 -287 1109 -187 -800 1092 -441 -327 -678 -594 745 -536 721 986 305 49 -827 278 1206 -791 -717 496 392 -391 200 1180 927 1119 703 -732 379 -808 -231 53 450 -266 906 461 -664 822 -728 644 798 -605 -519 -378 -884 911 983 -437 545 522 383 -565 1110 -413 842 -754 -660 -473 734 -730 1006 587 678 981 -124 1033 750 95 -552 351 136 84 526 -185 298 282 -292 128 506 -117 4 -635 425 -61 1167 -433 -997 134 -87 -994"; \
  ./push_swap $ARG | ./checker_linux $ARG'

bash -c 'ARG="-40 1172 -782 530 650 156 429 262 415 -543 270 -606 -505 -613 61 826 1145 -392 935 -641 -434 487 351 526 -410 -131 745 269 449 515 -72 -567 241 -716 435 -701 948 888 684 -245 -464 1031 -49 523 -77 -27 -25 -449 -36 -769 -980 -961 -538 -302 -648 -173 -643 -85 -456 -104 1086 -902 937 894 622 129 912 -334 1102 987 823 27 393 409 388 -29 -540 445 128 -405 -566 1055 709 -554 -52 1017 890 619 -3 -796 -766 -86 -861 1194 1071 -337 -930 -454 84 972 -854 -850 -416 1116 520 1058 -864 196 510 -299 -655 124 -54 -328 169 -251 1002 -177 -433 610 362 -158 -462 -478 35 328 117 1183 -503 831 332 -991 991 -169 -753 -616 1222 329 940 -785 -810 314 1215 134 807 884 -579 -802 -635 698 73 810 -452 -784 481 -845 -435 1152 -59 305 -887 1054 -326 871 815 -520 51 180 -604 988 -948 1080 -860 503 522 1229 1173 -953 718 -585 638 556 302 572 28 -666 -459 -517 -843 443 -370 -773 671 133 506 904 -338 714 -148 -815 560 527 862 322 50 1227 416 1036 623 986 315 866 1120 -823 55 1053 -30 -421 -875 -397 430 785 -603 562 1076 805 -278 710 -628 873 576 -279 955 -905 960 -65 624 822 175 924 -31 -925 -780 -484 -408 947 -414 485 -178 -295 -33 -500 418 -23 -171 1163 592 542 -422 248 -230 135 969 1198 404 -254 394 1181 410 -446 -256 313 1203 -563 -69 938 21 -926 381 540 599 1089 674 -984 -535 819 734 -107 -257 311 616 372 -22 -127 58 -752 -805 1160 191 -335 -820 1073 1098 -43 -293 795 956 280 -376 -737 1009 -223 715 -515 970 -891 155 869 1104 -34 1041 161 -199 187 1101 256 1026 -24 52 725 -218 -906 -259 -671 1105 -945 652 340 -735 -71 -602 -80 -909 373 958 1132 -419 -413 9 -993 531 -897 71 224 258 -75 -588 580 1018 -497 1038 1140 538 455 -228 762 197 -463 -351 -928 1095 -418 148 1011 -190 809 -971 -848 -986 1171 102 116 -224 375 1174 260 -352 760 -266 -932 448 825 914 -741 1162 942 583 -758 606 339 -837 212 -840 614 -166 -989 751 564 -136 561 221 1050 590 -321 712 883 387 847 226 838 -465 279 -147 -323 828 -4 584 408 1138 863 200 -672 -779 502 -2 -546 952 111 -286 728 -813 164 563 1119 -448 518 1001 547 39 -35 -262 1161 705 -867 1166 1045 -611 -393 797 -927 -770 -649 954 708 984 731 -852 776 149 366 -872 627 -488 -999 853 -652 982 291 827 -451 1074 615 94 -371 -940 996 1084 -496 -565 867 160 -219 966 1023 724 -195 -383 -599 -596 1088"; \
  ./push_swap $ARG | ./checker_linux $ARG'


echo "--"
echo "regression_test.sh: All test executed"
echo "They passed iff there is no error output"
echo "like 'KO' between the two little dashed lines"

