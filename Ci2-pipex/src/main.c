/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:54:24 by reciak            #+#    #+#             */
/*   Updated: 2025/10/29 18:16:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Stores the definition of main()
 */

#include "pipex.h"

static bool	argc__ok(int argc, t_err *err);
static bool	alloc__cmds_pre_init(t_data *data, t_err *err);
static void	final__tidy_up(size_t num_cmds, t_cmd *cmd, t_err *err);
static int	wait__without_creating_zombies(pid_t pid_last_cmd);

/**
 * @brief The entry point and dirigent for the pipex programm ...
 * @note A note 
 * @note For building the documentation from comment blocks like this one run
 *         make doc; open doc/html/index.html
 * @param[in] argc The number of arguments handed over by the calling shell
 * @param[in] argv argv[0], argv[1], ... argv[argc - 1] are pointers to strings
 *                  containing the programms name and the command-line arguments
 *                  passed to the program.
 * @param[in] envp Well similar but for the environment variables.
 * @return a return code indicating success or an error.
 */
int	main(int argc, char **argv, char**envp)
{
	t_err	err;
	t_data	data;
	int		termination_status_last_cmd;

	set_err(&err, E_NONE, 0, "main");
	err.cmd_index = -1;
	data.num_cmds = (size_t) argc - 3;
	if (!argc__ok(argc, &err)
		|| !alloc__cmds_pre_init(&data, &err)
		|| !parse_argv(argc, argv, &data, &err))
		print_exit_msg_and_exit(&err);
	if (!parse_path(envp, data.num_cmds, data.cmd, &err)
		|| !open_pipes(data.num_cmds, data.cmd, &err)
		|| !open_files(data.num_cmds, data.cmd, &err))
		h_err_exit(data.num_cmds, data.cmd, &err);
	if (!exec_pipeline(&data, envp, &err))
		h_err_exit(data.num_cmds, data.cmd, &err);
	termination_status_last_cmd
		= wait__without_creating_zombies(data.cmd[data.num_cmds - 1].pid);
	final__tidy_up(data.num_cmds, data.cmd, &err);
	return (termination_status_last_cmd);
}

static bool	argc__ok(int argc, t_err *err)
{
	if (argc >= 1 + 4)
		return (true);
	set_err(err, E_ARGC, errno, "main");
	return (false);
}

static bool	alloc__cmds_pre_init(t_data *data, t_err *err)
{
	size_t	num_cmds;
	t_cmd	*cmd;
	size_t	i;

	data->cmd = malloc(data->num_cmds * sizeof (*data->cmd));
	if (data->cmd == NULL)
		return (set_err(err, E_ALLOC, errno, "alloc__cmds_pre_init"), false);
	num_cmds = data->num_cmds;
	cmd = data->cmd;
	i = 0;
	while (i < num_cmds)
	{
		cmd[i].ac = 0;
		cmd[i].av = NULL;
		cmd[i].path = NULL;
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		cmd[i].fd_in = DO_NOT_USE;
		cmd[i].fd_out = DO_NOT_USE;
		cmd[i].pid = DO_NOT_USE;
		i++;
	}
	return (true);
}

static void	final__tidy_up(size_t num_cmds, t_cmd *cmd, t_err *err)
{
	t_err	copy;
	size_t	i;

	copy = *err;
	i = 0;
	while (i < num_cmds)
	{
		tidy_up_and_reset_cmd_items(&cmd[i], err);
		i++;
	}
	free (cmd);
	if (err->type != copy.type)
		out_str_fd(BLUE"What?! Even on tidying up another error happend?!\n"
			"Not investigating that ...\n"RESET, STDERR_FILENO);
}

/**
 * @note Neither the flags WUNTRACED nor WCCONTINUED are given as option to 
         to waitpid.
         Thus the *wait status* set by waitpid covers exactly the
         *termination status* of the child process for the last command, cf.
         Kerrisk (The Linux Programming Interface, Sec. 26.1.3
         "The Wait Status Value", p. 545).
 * @note @code waitpid(-1, &termination_status, 0); @endcode is equivalent to
 *       @code wait(&termination_status); @endcode
 */
static int	wait__without_creating_zombies(pid_t pid_last_cmd)
{
	pid_t	pid;
	int		wstatus;
	int		status_last_cmd;

	pid = 1;
	while (pid > 0)
	{
		pid = waitpid(-1, &wstatus, 0);  // wait(&wstatus)
		if (pid == pid_last_cmd && WIFEXITED(wstatus))
			status_last_cmd = WEXITSTATUS(wstatus);
		else if (pid == pid_last_cmd && WIFSIGNALED(wstatus))
			status_last_cmd = 128 + WTERMSIG(wstatus);
	}
	return (status_last_cmd);
}


    3  ls /ussr 
    4  ls /ussr 
    5  ls /ussr | ls .
    6  ls /ussr | ls .
    7  ls /ussr | ls .
    8  ls /ussr | ls .
    9  man waitpid
   10  exit
   11  miau
   12  echi $?
   13  echo $?
   14  miau
   15  echo $?
   16  ls
   17  ./outfile 
   18  ./outfile | ls
   19  echo $?
   20  cat /usr/include/sysexits.h 
   21  whereis bash.h
   22  ls /usr/include/
   23  ls /usr/include/ | grep bash
   24  whereis shell.h
   25  for f in {1..2] do; echo $f; done
   26  echo $?
   27  exit 3.14
   28  bash
   29  echo $?
   30  exit abf
   31  bash | exit 3.14
   32  bash -e 'exit 3.14'
   33  bash -c 'exit 3.14'
   34  echo $?
   35  exit
   36  bash | exit 3.14
   37  echo $?
   38  bash | exit 3.14
   39  exit
   40  bash | exit 3.14
   41  man fork
   42  exit
   43  grep -rin Makefile 
   44  unset PATH
   45  exit
   46  echo "ja ja" | env -i grep "a" | grep j
   47  echo "ja ja" | env -i grep "a" | grep j
   48  echo $?
   49  echo "ja ja" | env -i grep "a" | grep j
   50  echo $?
   51  echo "ja ja" | env -i grep "a" | grep n
   52  echo $?
   53  env -i echo "ja ja" | env -i grep "a" | grep n
   54  echo $?
   55  whereis grep
   56  env -i ls
   57  env i- less 
   58  env -i less 
   59  env -i less Makefile 
   60  less Makefile 
   61  env -i less Makefile 
   62  bash
   63  ls
   64  unset PATH
   65  less Makefile 
   66  set -i less Makefile 
   67  man env
   68  less
   69  exit
   70  echo "ja ja" | env -i grep "a" | grep n
   71  echo "ja ja" | env -i grep "a" | grep n; echo $?
   72  echo "ja ja" | PATH= grep "a" | grep n; echo $?
   73  echo "ja ja" | PATH= grep "a" | less; echo $?
   74  echo "ja ja" | PATH= grep "a" | wc; echo $?
   75  echo "ja ja" | PATH= grep "a" | grep "n"; echo $?
   76  exit
   77  find . --name miau
   78  find . -name miau
   79  find . -name main.c
   80  find / -name main.c
   81  echo $?
   82  code .
   83  exit
   84  true
   85  echo $?
   86  false
   87  echo $?
   88  exit
   89  Makefile
   90  ./Makefile
   91  ./show.sh 
   92  ./show.sh 
   93  ./pipex Makefile /usr/bin/cat "/usr/bin/cat" outfile
   94  ls
   95  exit
   96  echo "wuff2" > testin.txt
   97  ls -al
   98  chmod u-w outfile2.txt 
   99  ls -al
  100  < testin.txt |  /usr/bin/cat | '/usr/bin/cat' > outfile2.txt
  101  exit
  102  touch ""
  103  valgrind ./pipex testin.txt  echo 'cat l -a' cat outfile2.txt
  104  exit
  105  exit
  106  ulimit -u 1;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  107  ulimit -n 4;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  108  ulimit -n 10;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  109  ulimit -n 20;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  110  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  111  exit
  112  ulimit -n 4;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  113  ulimit -n 5;
  114  ulimit -n 4;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  115  ulimit -n 20;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  116  ulimit -n 20;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  117  ulimit -n 7;  ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  118  ulimit -help
  119  ulimit --help
  120  bash
  121  exit
  122  ulimit -n 20;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  123  ulimit -n 10;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  124  ulimit -n 7;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  125  ulimit -n 6;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  126  ulimit -n 5;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  127  ulimit -n 4;  ./pipex Makefile "/usr/bin/echo 'Hi You'" cat outfile.txt
  128  exit
  129  ulimit -n 10;  ./pipex Makefile cat cat cat cat outfile.txt
  130  ulimit -n 8;  ./pipex Makefile cat cat cat cat outfile.txt
  131  ulimit -n 7;  ./pipex Makefile cat cat cat cat outfile.txt
  132  ulimit -n 6;  ./pipex Makefile cat cat cat cat outfile.txt
  133  ulimit -n 6;  ./pipex Makefile miau  miau cat cat cat cat outfile.txt
  134  ulimit -n 6;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  135  exit
  136  ulimit -n 6;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  137  cd ..
  138  exit
  139  ulimit -n 6;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  140  ulimit -n 6;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  141  ulimit -n 8;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  142  ulimit -n 10;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  143  ulimit -n 20;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  144  ulimit -n 100;  ./pipex Makefile miau miau mia  miau cat cat cat cat outfile.txt
  145  exit
  146  ulimit -n 20;  ./pipex Makefile cat cat outfile.txt
  147  ulimit -n 20; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  148  ulimit -n 20; ./pipex Makefile cat cat outfile.txt
  149  ulimit -n 20; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  150  ulimit -n 30; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  151  ulimit -n 30; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  152  ulimit -n 8; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  153  ulimit -n 8 ;  ./pipex Makefile cat cat outfile.txt
  154  ulimit -n 6 ;  ./pipex Makefile cat cat outfile.txt
  155  ulimit -n 5 ;  ./pipex Makefile cat cat outfile.txt
  156  ulimit -n 4 ;  ./pipex Makefile cat cat outfile.txt
  157  ulimit -n 8 ; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  158  exit
  159  ulimit -n 8 ; valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  160  ulimit -n 8
  161  valgrind --track-fds=yes ./pipex Makefile cat cat outfile.txt
  162  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  163  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  164  exit
  165  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  166  ulimit -n 100; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  167  ulimit -n 20; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  168  ulimit -n 17; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  169  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  170  exit
  171  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  172  ulimit -n 20; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  173  exit
  174  ulimit -n 20; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  175  ulimit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  176  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  177  exit
  178  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  179  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  180  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  181  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  182  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  183  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  184  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  185  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  186  ulimit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  187  ulimit -n 22; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  188  exit
  189  ulimit -n 22; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  190  exit
  191  ulimit -n 22; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  192  exit
  193  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  194  make re
  195  make CC_LESS_STRICT=1 re
  196  make re
  197  exit
  198  make CC_LESS_STRICT=1 DEBUG_VALGRIND=1 re
  199  cur
  200  exit
  201  make CC_LESS_STRICT=1 DEBUG_VALGRIND=1 re
  202  ls
  203  ls
  204  make CC_LESS_STRICT=1 DEBUG_VALGRIND=1 re
  205  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  206  exit
  207  < Miau cat | wc > outfile
  208  < Miau.md cat | wc > outfile
  209  cat outfile
  210  cat outfile
  211  cat Miau.md 
  212  clear
  213  < Miau.md cat | wc > outfile
  214  exit
  215  ulimit --help
  216  exit
  217  ulimit --help
  218  ulimit -n 30; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  219  ulimit -n 28; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  220  ulimit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  221  exit
  222  ulimit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  223  limit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  224  limit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  225  limit -n 23; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  226  limit -n 22; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  227  limit -n 21; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  228  limit -n 20; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  229  limit -n 19; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  230  limit -n 18; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  231  limit -n 14; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  232  limit -n 12; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  233  limit -n 10; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  234  limit -n 8; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  235  limit -n 6; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  236  exit
  237  ulimit -n 24; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi You" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt
  238  exit
  239  unset -i ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/sleep2  outfile.txt
  240  set -i ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/sleep2  outfile.txt
  241  git diff
  242  exit
  243  "" | ""
  244  exit
  245  "" | ""
  246  "'' ab " | ""
  247  "'' ab " | echo
  248  lss -al
  249  '' ab  | echo
  250  bash
  251  .
  252  man access
  253  echo $PATH
  254  exit
  255  PATH=$PATH:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/path:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/other_path
  256  prog
  257  prog -l
  258  ls
  259  history
  260  chmod u+x path/prog
  261  prog -l
  262  ./path/prog -l
  263  prog -l
  264  ./other_path/prog -l
  265  ./path/prog -l
  266  echo $PATH
  267  prog -l
  268  chmod u-x ./other_path/prog 
  269  prog -l
  270  mv ./other_path/prog ./other_path/prog2
  271  prog -l
  272  ls **
  273  ls -l **
  274  mv other_path/prog2 other_path/prog
  275  chmod u+x other_path/prog
  276  ls -l **
  277  prog -l
  278  echo $PATH
  279  ls **
  280  ls -l **
  281  ./path/prog -l
  282  ./other_path/path/prog -l
  283  ./other_path/prog -l
  284  prog
  285  prog -l
  286  ./other_path/prog -l
  287  prog -l
  288  chmod a-x other_path/prog 
  289  prog -l
  290  ls -al
  291  pwd
  292  PATH=$PATH:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/other_path:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/path:nonsense
  293  prog
  294  mv path/prog path/prog2
  295  prog
  296  mv path/prog2 path/prog
  297  prog
  298  ./path/prog 
  299  ./other_path/prog 
  300  prog
  301  chmod a+x ./other_path/prog 
  302  prog
  303  chmod a-x path/prog 
  304  prog
  305  echo $PATH
  306  PATH=/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/other_path:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/path
  307  echo $PATH
  308  mv path/ ls_path
  309  /usr/bin/mv path/ ls_path
  310  ls
  311  /bin/ls
  312  echo $PATH
  313  echo $PATH | /bin/tr ':' '\n' 
  314  /bin/ls
  315  echo $PATH | /bin/tr ':' '\n' 
  316  PATH=/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/other_path:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/ls_path
  317  /bin/ls
  318  prog
  319  ./ls_path/prog
  320  chmod a+x ./ls_path/prog
  321  /bin/chmod a+x ./ls_path/prog
  322  ./ls_path/prog
  323  prog
  324  /bin/chmod a-x ./other_path/prog
  325  prog
  326  ./ls_path/prog -l
  327  ./ls_path/prog  -l **
  328  ./prog
  329  pwd
  330  /home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/prog
  331  /home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/ls_path/prog
  332  ""
  333  prog
  334  prog2
  335  exit
  336  ""
  337  ''
  338  exit
  339  prog
  340  pgroasg
  341  echo $?
  342  exit
  343  ls
  344  ./outfile
  345  echo $?
  346  make re
  347  make re
  348  make re
  349  make re
  350  make re
  351  make re
  352  make D
  353  exit
  354  exit
  355  ./pipex Makefile 'echo Miau' cawt OUTfile
  356  < Makefile | 'echo Miau' | cawt > OUTfile
  357  < Makefile  'echo Miau' | cawt > OUTfile
  358  < Makefile  echo Miau | cawt > OUTfile
  359  < Makefile  echo Miau | cgaggawt > OUTfile
  360  < Makefile  echo Miau | cgaggawt > OUTfile
  361  < Makefile  asdffasecho Miau | cgaggawt > OUTfile
  362  echo $?
  363  ./pipex Makefile 'echo Miau' cawt OUTfile
  364  echo $?
  365  ext
  366  exit
  367  ./pipex Makefile 'echo Miau' cawt OUTfile
  368  make re
  369  make re_not_libft
  370  make re_not_libft
  371  ./pipex Makefile 'echo Miau' cawt OUTfile
  372  make re_not_libft
  373  ./pipex Makefile 'echo Miau' cawt OUTfile
  374  make re_not_libft
  375  ./pipex Makefile 'echo Miau' cawt OUTfile
  376  ./pipex Makefile 'echo Miau' cawt OUTfile
  377  make re
  378  make re
  379  ./pipex Makefile 'echo Miau' cawt OUTfile
  380  ./pipex Makefile 'echo Miau' cawt OUTfile
  381  make re
  382  make re
  383  make re
  384  make re
  385  ./pipex Makefile 'echo Miau' cawt OUTfile
  386  ./pipex Makefile 'echo Miau' cawt OUTfile
  387  ./pipex Makefile 'echo Miau' cawt OUTfile
  388  make re
  389  ./pipex Makefile 'echo Miau' cawt OUTfile
  390  ./pipex Makefile 'echo Miau' cawt OUTfile
  391  ls
  392  exit
  393  PATH=/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/other_path:/home/reciak/github/42-tmp_play/22_pipex_stuff/pi_03_execution_in_path/ls_path
  394  ./pipex Makefile prog cat OUT2
  395  PATH=
  396  ./pipex Makefile prog cat OUT2
  397  ./pipex Makefile my_cat cat OUT2
  398  ./pipex Makefile ./my_cat cat OUT2
  399  ./pipex Makefile ./testin.txt cat OUT2
  400  ./pipex Makefile ./testin.txt cat OUT2
  401  exit
  402  make re_not_libft
  403  ./pipex Makefile ./testin.txt cat OUT2
  404  echo $?
  405  ./pipex Makefile ./testin.txt catssfdaag OUT2
  406  echo $?
  407  ./pipex Makefile ./testin.txt catssfdaag OUT2
  408  echo $?
  409  echo $?
  410  git status
  411  exit
  412  make re_no_libft
  413  make re_not_libft
  414  ./pipex Makefile ./testin.txt catssfdaag OUT2
  415  echo $?
  416  exit
  417  make re
  418  ./pipex Makefile ./testin.txt catssfdaag OUT2
  419  make re_not_libft
  420  ./pipex Makefile ./testin.txt catssfdaag OUT2
  421  make re_not_libft
  422  make re_not_libft
  423  ./pipex Makefile ./testin.txt catssfdaag OUT2
  424  make
  425  make re_not_libft
  426  make re_not_libft
  427  ./pipex 
  428  ./pipex Makefile ./testin.txt catssfdaag OUT2
  429  echo $?
  430  < Makefile ./testin.txt | catssfdaag > OUT2
  431  git status
  432  git difftool
  433  git status
  434  git commit -a
  435  git push
  436  exit
  437  ./pipex Makefile 'echo Hello' cat cat OUTfile
  438  ./pipex Makefile 'echo Hello' cat cat OUTfile
  439  ./pipex Makefile 'echo Hello' cat cat OUTfile
  440  make re
  441  exit
  442  ./pipex Makefile 'echo Hello' ./OUTfile cat OUTfile
  443  ./pipex Makefile 'echo Hello' cat ./OUTfile  OUTfile
  444  echo $?
  445  < Makefile 'echo Hello' | cat | ./OUTfile > OUTfile
  446  echo $?
  447  < Makefile echo Hello | cat | ./OUTfile > OUTfile
  448  echo $?
  449  < Makefile echo Hello | cat | ./OasdfUTfile > OUTfile
  450  echo $?
  451  ./pipex Makefile 'echo Hello' cat ./OasdfUTfile  OUTfile
  452  echo $?
  453  exit
  454  ./pipex Makefile 'echo Hello' cat ./OasdfUTfile  OUTfile
  455  grep -rin "printf"
  456  exit
  457  exit
  458  ./pipex Makefile 'echo Hello' ./OUTfile cat '' OUTfile
  459  ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  460  valgrin ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  461  valgrind ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  462  echo $?
  463  valgrind --trace-children=yes ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  464  valgrind --trace-children=yes ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  465  ./pipex Makefile "" 'echo Hello' ./OUTfile cat '' OUTfile
  466  < Makefile "" | 'echo Hello' | ./OUTfile | cat | '' > OUTfile
  467  exit
  468  ./pipex  "" '' OUTfile
  469  ./pipex  '' '' OUTfile
  470  ./pipex  'a' 'b' OUTfile
  471  ./pipex Makefile '' '' OUTfile
  472  ./pipex Makefile '' '' OUTfile
  473  exit
  474  ./pipex Makefile 'echo Hello' cat ./OasdfUTfile ""  OUTfile
  475  ./pipex Makefile 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  476  ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  477  make re_not_libft
  478  ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  479  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  480  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  481  exit
  482  env
  483  env -i ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  484  echo $?
  485  exit
  486  env -i ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  487  exit
  488  env -i ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  489  exit
  490  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  491  echo $?
  492  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile   OUTfile
  493  echo $?
  494  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  495  PATH=
  496  valgrind ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  497  ./pipex Makefile '' 'echo Hello' cat ./OasdfUTfile ''  OUTfile
  498  exit
  499  ./cat
  500  ./cat
  501  cat /dev/urandom | < OLD_pipex.h cat | cat
  502  history
