# Input from Bernhard on 29.10.2025

* Open im Child: Wenn open fehlschlägt sollen andere commands trotzdem noch executed werden
  (so hatte ich es sogar in meinem ersten Ansatz, ... bei meinem zweiten Ansatz nicht mehr jedoch)
* Nur mit einer offnen Pipe arbeiten (ähnlich wie bei meinem ersten Ansatz, aber da binich nicht mehr durchgestiegen als ich Fehler behandlung einbauen wollte auf der Rückreise von der Beerdigung)

* Tests die er durchgeführt hat und fixe von Cami sollten auf dem Campus noch in einem nicht gepushten branch vorliegen... (18.11.2025: Probably: `Ci2-pipex-submission-prep-debugging`)

* 18.11.2025 History mit vora allem einigen von Bernhard benutzten Befehlen (erste Befehle noch von mir?):

 git add inc/pipex.h  src/a_col_exiting/h_err_exit.c src/exec_pipeline.c src/main.c src/set_err.c 
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " cat  outfile_for_diff.txt; diff outfile.txt outfile_for_diff.txt\n
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'echo Miau' cawt OUTfile\n
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' cawt OUTfile\n
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' OUTfile OUTfile\n
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' ./OUTfile OUTfile\n
 pwd
 valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' /home/reciak/github/42-projects/Ci2-pipex/OUTfile OUTfile\n

 cd 42-projects_FRESH___PIPEX
 cd Ci2-pipex
 make
 funcheck -ac ./pipex Makefile ls mia 'grep -rin' '' "" outfile
 valgrjind ./test
 funcheck -ac ./pipex Makefile ls mia  '' "" outfile
 norminette

 git checkout -b Ci2-pipex-submission-prep-debugging
 git commit /a
 git commit -a 
 git checkout Ci2-pipex-submission-prep
 ls
 make re_not_libft
 code .
 make re
 make fclean
 make DEBUG_VALGRIND=1 re_not_libft
 make DEBUG_VALGRIND=1 re
 funcheck -ac ./pipex Makefile '' '' OUTfile



 valgrind ./pipex infile cat cat outfile
 export PS1="$ "

 touch infile
 (ulimit -u 20; ./pipex infile cat "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" outfile)
echo $?

 (ulimit -u 20; valgrind ./pipex infile cat "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" outfile)


./pipex
./pipex infile cat cat outfile
cat outfile
cat infile
make
cat infile
./pipex infile cat cat outfile
cat outfile

chmod 000 outfile
./pipex infile cat cat outfile
valgrind ./pipex infile cat cat outfile
valgrind ./pipex infile cat "sleep 5" outfile
valgrind ./pipex infile "sleep 5" cat outfile
< infile "sleep 5"  | cat > outfile
< infile sleep 5  | cat > outfile

chmod 644 outfile
unset PATH
/usr/bin/valgrind ./pipex infile cat cat outfile
/usr/bin/valgrind ./pipex infile cat cat outfilemake
make
/usr/bin/make
export PATH=/usr/bin
make

unset PATH
/usr/bin/valgrind ./pipex infile cat cat outfilemake
bash
/usr/bin/valgrind env -i ./pipex infile cat cat outfilemake
/usr/bin/valgrind /usr/bin/env -i ./pipex infile cat cat outfilemake

export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfilemake
make
/usr/bin/make
export PATH="/usr/bin"
make

export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfilemake

/usr/bin/touch cat
/usr/bin/valgrind ./pipex infile cat cat outfilemake
/usr/bin/chmod +x cat
/usr/bin/valgrind ./pipex infile cat cat outfilemake
/usr/bin/ls
cd ..
ls

export PATH="/usr/bin"
ls
Ci2-pipex/pipex
Ci2-pipex/././pipex
cd Ci2-pipex
ls

export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfilemake
make
export PATH="/usr/bin"
make


export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfilemake
export PATH="/usr/bin"
cat cat

export PATH="/usr/bin"
export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfilemake
/usr/bin/valgrind ./pipex infile cat cat outfile

bash
export PATH="::::"
/usr/bin/valgrind ./pipex infile cat cat outfile
time ./pipex infile "sleep 5" "sleep 10" outfile

export PATH="/usr/bin"
time ./pipex infile "sleep 5" "sleep 10" outfile
time ./pipex infile "sleep 5" "sleep 10" cat outfile
time ./pipex infile "sleep 5" "sleep 10" cat cat outfile
(ulimit -n 15; /usr/bin/valgrind --trace-children=yes --track-fds=yes ./pipex infile cat cat cat cat cat cat cat cat cat cat outfile)
