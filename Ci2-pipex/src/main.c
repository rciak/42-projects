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












































  9619  cd
 9620  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat '/usr/bin/cat' outfile2.txt
 9621  git add inc/pipex.h src/exec_pipeline.c src/exec_pipeline/execute.c
 9622  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt cat '/usr/bin/cat' outfile2.txt
 9623  touch sample.sh
 9624  open sample.sh
 9625  chmod u+x sample.sh
 9626  ./sample.sh
 9627  make DEBUG_LAUB_SAN=1 CC_LESS_STRICT=1 re; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/echo  '/usr/bin/cat' outfile2.txt
 9628  make DEBUG_LAUB_SAN=1 CC_LESS_STRICT=1 re; ./pipex testin.txt /usr/echo  '/usr/bin/cat' outfile2.txt
 9629  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/echo  '/usr/bin/cat' outfile2.txt
 9630  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/cat  '/usr/bin/cat' outfile2.txt
 9631  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt ./sample.sh  '/usr/bin/cat' outfile2.txt
 9632  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  '/usr/bin/cat' outfile2.txt
 9633  mkdir src/error_management/handle_error
 9634  touchgit  src/error_management/handle_error/err_execve.c
 9635  cat makefile_dir/def_sources.mk
 9636  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  'cat' outfile2.txt
 9637  wiki; cd 42-projects.wiki; code.; sleep 1;  cur; code .; sleep 1; show_cur_subject; sleep 1; wiki; cd 42-notes-improving_42.wiki; code . ; sleep 3; ; wiki; cd 42-notes-private.wiki ; code .; sleep 3;  cur;
 9638  cd github-wikis
 9639  cd 42-projects.wiki
 9640  cd 42-notes-improving_42.wiki
 9641  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  'cat' outfile2.txt
 9642  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' outfile2.txt
 9643  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' ./sample.sh outfile2.txt
 9644  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --show-leak-kinds=all  --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' ./sample.sh outfile2.txt
 9645  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' 'echo miau' outfile2.txt
 9646  make DEBUG_VALGRIND=1  re_not_libft; valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' 'echod miau' outfile2.txt
 9647  make DEBUG_VALGRIND=1  re_not_libft; valgrind -s--leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' 'echod miau' outfile2.txt
 9648  make DEBUG_VALGRIND=1  re_not_libft; valgrind -s --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/echo  'cat' 'echod miau' outfile2.txt
 9649  make DEBUG_VALGRIND=1  re_not_libft; valgrind -s --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  'cat' 'echo miau' outfile2.txt
 9650  make DEBUG_VALGRIND=1  re_not_libft; valgrind -s --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  'cat' 'echo miau dfaf' outfile2.txt
 9651  cp ../usr/bin/cat ./my_cat
 9652  cp  /usr/bin/cat ./my_cat
 9653  git add inc/pipex.h makefile_dir/def_sources.mk src/error.c src/error_management/handle_error.c src/error_management/handle_error/err_execve.c src/exec_pipeline.c  src/exec_pipeline/execute.c src/exit_msg.c src/init/parse.c src/main.c
 9654  zsh
 9655  cp ~/.zsh_history .
 9656  tail .zsh_history
 9657  tail -100 .zsh_history
 9658  git add .zsh_history
 9659  mkdir verytmclo
 9660  cd verytmclo
 9661  git clone git@github.com:rciak/42-projects 42-projects_FRESH77777
 9662  cd 42-projects_FRESH77777
 9663  ln -s ../Ci0-libft libft
 9664  cat src/main.c
 9665  git pull
 9666  git rm --keep-local
 9667  cd src_OLD
 9668  cp OLD_pipex.h OLD_pipex.h_SIC
 9669  touch OLD_pipex.h
 9670  open OLD_pipex.h
 9671  git rm OLD_pipex.h
 9672  git rm --cached OLD_pipex.h
 9673  make DEBUG_VALGRIND=1  re_not_libft; valgrind -s --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex testin.txt /usr/bin/cat  './my_cat' 'echo miau dfaf' outfile2.txt
 9674  make CC_LESS_STRICT=1 re_but_no_libft_rebuilt
 9675  touchgit a_col_tools/tidy_up_all_cmds.c
 9676  make CC_LESS_STRICT=1 re
 9677  grep -rin "free(" src
 9678  grep -rin "free (" src
 9679  git restore src/main.c
 9680  git stash
 9681  grep -rin "free" src 
 9682  meld src src_OLD
 9683  valgrind ./pipex testin.txt  /usr/bin/cat cat  '/usr/bin/cat'  outfile2.txt
 9684  valgrind ./pipex testin.txt  /usr/bin/cat cat cat '/usr/bin/cat'  outfile2.txt
 9685  valgrind ./pipex testin.txt  /usr/bin/cat cat cat cat '/usr/bin/cat'  outfile2.txt
 9686  valgrind ./pipex testin.txt  /usr/bin/cat '/usr/bin/cat'  outfile2.txt
 9687  valgrind ./pipex testin.txt  '/usr/bin/cat'  outfile2.txt
 9688  funcheck -ac ./pipex Makefile ls wc outfile
 9689  git add src/a_col_exiting/h_err_exit.c src/a_col_tools/tidy_up_all_cmds.c  src/main.c src/parse_argv.c src/parse_path.c
 9690  git mv src/a_col_tools/tidy_up_all_cmds.c src/a_col_tools/tidy_up_and_reset_cmd_itmes.c
 9691  valgrind ./pipex testin.txt cat '/usr/bin/cat'  outfile2.txt
 9692  valgrind ./pipex testin.txt cat '/usr/bin/cat -l --logn'  outfile2.txt
 9693  valgrind ./pipex testin.txt cat '/usr/bin/cat -l --logn' echo  outfile2.txt
 9694  git add  inc/pipex.h  makefile_dir/def_sources.mk  src/a_col_exiting/h_err_exit.c  src/a_col_tools/tidy_up_and_reset_cmd_itmes.c src/main.c src/parse_argv.c
 9695  funcheck -ac ./pipex Makefile ls 'grep -rin' wc outfile
 9696  funcheck -ac ./pipex Makefile ls mia 'grep -rin' wc outfile
 9697  valgrind ./pipex testin.txt cat '/usr/bin/cat -l --logn' 'a c d w f s' echo  outfile2.txt
 9698  valgrind ./pipex testin.txt ' echo  outfile2.txt
 9699  valgrind ./pipex testin.txt '' echo  outfile2.txt
 9700  valgrind ./pipex testin.txt  echo  outfile2.txt
 9701  valgrind ./pipex testin.txt  echo  cat outfile2.txt
 9702  valgrind ./pipex testin.txt  echo cat cat outfile2.txt
 9703  git add src/main.c src/parse_argv.c
 9704  man atoi
 9705  git add src/main.c src/parse_argv.c 
 9706  git difftool --staged
 9707  valgrind ./pipex testin.txt  echo 'cat l -a' cat outfile2.txt
 9708  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=no   ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc" outfile.txt
 9709  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc" outfile.txt
 9710  git add src/parse_argv.c src/parse_path.c
 9711  exi
 9712  git add src/parse_argv.c
 9713  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc" outfile.txt\n
 9714  git add src/main.c
 9715  make hyperlinks_clangd
 9716  touchgit open_pipes.c
 9717  man ulimit
 9718  make CC_LESS_STRICT=1 re_not_libft
 9719  /home/reciak/.vscode/extensions/vadimcn.vscode-lldb-1.11.7/bin/codelldb-launch --connect=127.0.0.1:42335 --clear-screen 
 9720  lldb ./pipex testin.txt  /usr/bin/cat  '/usr/bin/cat'  outfile2.txt
 9721  make DEBUG_VALGRIND=1 CC_LESS_STRICT=1 re_not_libft
 9722  make DEBUG_LAUB_SAN=1 re
 9723  git add inc/pipex.h makefile_dir/def_sources.mk src/a_col_exiting/h_err_exit.c src/main.c  src/open_pipes.c src/set_err.c
 9724  make CC_LESS_STRICT=1 DEBUG_LAUB_SAN=1 re
 9725  make CC_LESS_STRICT=1 DEBUG_M_SAN=1 re
 9726  touchgit open_files.c
 9727  Makefile > cat | wc > outfile
 9728  show_cur_subject
 9729  Makefile < cat | wc > outfile
 9730  < Makefile cat | wc > outfile
 9731  mdkir very_tmp
 9732  mkdir ver_tmpy
 9733  cd ver_tmpy
 9734  touch mi
 9735  ls -al
 9736  chmod 000 mi
 9737  chmod 000 mi; ls
 9738  chmod 000 mi; ls -l
 9739  chmod 421 mi; ls -l
 9740  rm -fr ver_tmpy
 9741  make CC_LESS_STRICT=1 DEBUG_VALGRIND=1 re
 9742  ulimit 
 9743  ulimit
 9744  ulimit -help
 9745  ulimit --help
 9746  git add inc/pipex.h makefile_dir/def_sources.mk src/main.c src/open_files.c src/set_err.c
 9747  git difftool 
 9748  cat src/outfile
 9749  rm src/outfile
 9750  rm src/cat
 9751  make tests
 9752  touchgit src/exec_pipeline.c
 9753  cattempl doxygen_comment-Ci2-pipex.txt
 9754  grep -rn "E_LOGIC"
 9755  git add src/open_files.c 
 9756  git add src/set_err.c
 9757  git difft
 9758  git add src/a_col_exiting/h_err_exit.c
 9759  git difftool src/a_col_exiting/h_err_exit.c
 9760  norminette src/a_col_exiting/logic_error_exit.c
 9761  make r
 9762  ./pipex testin.txt  /usr/bin/cat  '/usr/bin/cat'  outfile2.txt
 9763  bash --posix
 9764  exdit
 9765  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" /usr/bin/cat /usr/bin/cat /usr/bin/cat "/usr/bin/wc -l " outfile.txt\n
 9766  make print_info
 9767  make re_but_no_libft_rebuilt
 9768  mae
 9769  ./pipex testin.txt  cat /usr/bin/cat  '/usr/bin/cat'  outfile2.txt
 9770  ./pipex Makefile cat /usr/bin/cat  '/usr/bin/cat'  outfile2.txt
 9771  cat outfile2.txt
 9772  git log --oneline | grep "debug"
 9773  git show 9ad4e7c
 9774  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " cat outfile.txt\n
 9775  grep -rin "close" src
 9776  grep -rn "close" src
 9777  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " cat cat outfile.txt\n
 9778  top
 9779  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/cat" "/usr/bin/wc -l " outfile.txt\n
 9780  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/cat" "/usr/bin/echo "   outfile.txt\n
 9781  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " outfile.txt\n
 9782  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " 'echo  Hi'  outfile.txt\n
 9783  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " '/usr/bin/echo  Hi'  outfile.txt\n
 9784  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " '/usr/bin/cat'  outfile.txt\n
 9785  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'" "/usr/bin/wc -l " '/usr/bin/echo'  outfile.txt\n
 9786  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'"  '/usr/bin/echo'  outfile.txt\n
 9787  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You'"  '/usr/bin/echo Hi'  outfile.txt\n
 9788  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo 'Hi You safdfasdjhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh'"  '/usr/bin/echo Hi'  outfile.txt\n
 9789  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/cat"  '/usr/bin/echo Hi'  outfile.txt\n
 9790  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/cat"  '/usr/bin/echo'  outfile.txt\n
 9791  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/grep 'Miau' "  '/usr/bin/echo'  outfile.txt\n
 9792  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/cat"  '/usr/bin/sleep 2'  outfile.txt\n
 9793  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/grep 'Miau' "  '/usr/bin/sleep 2'  outfile.txt\n
 9794  git add  inc/pipex.h  src/exec_pipeline.c src/main.c  src/set_err.c
 9795  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/grep 'Miau' "  '/usr/bin/sleepdd 2'  outfile.txt\n
 9796  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/grep " /usr/bin/sleep2'  outfile.txt\n
 9797  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/grep " /usr/bin/sleep2  outfile.txt\n
 9798  unset -i ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/sleep2  outfile.txt\n
 9799  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/sleep2  outfile.txt\n
 9800  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi "/usr/bin/cat  outfile.txt\n
 9801  tmp_play
 9802  cd 22_pipex_stuff
 9803  mkdir pi_03_execution_in_path
 9804  cd pi_03_execution_in_path
 9805  cp /usr/bin/echo ./echo_copy
 9806  mkdir other_path
 9807  cp /usr/bin/ls other_path/prog
 9808  mkdir path
 9809  mv echo_copy other_path/prog
 9810  ls **
 9811  ./other_path/prog mi
 9812  cp /usr/bin/ls path/prog
 9813  ./path/prog
 9814  ./other_path/prog
 9815  ./other_path/prog m
 9816  ./other_path/prog -l
 9817  chmod u-x path/prog
 9818  ./path/prog -l
 9819  ""
 9820  errno
 9821  for i in {1..600} then; do errno $i; done
 9822  errno 134
 9823  errno 133
 9824  man execv
 9825  whereis bashexitcode.h
 9826  cd /usr/include
 9827  find . -name bash
 9828  find . -name *bash*
 9829  find . -name *spa*
 9830  find . -name "*spa*"
 9831  find . -name "*bash*"
 9832  find . -name "*bash*"  | grep "\.h"
 9833  find . -name "*bash*"  | grep "\.h" | grep -v "hpp"
 9834  man execve
 9835  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/cat  outfile.txt\n
 9836  ls -la
 9837  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " cat  outfile_for_diff.txt; diff outfile outfile_for_diff.txt\n
 9838  echo $PATH
 9839  norminette src/a_col_exiting/h_err_exit.c
 9840  wiki; cd 42-projects.wiki; code .; sleep 1;  cur; code .; sleep 1; show_cur_subject; sleep 1; wiki; cd 42-notes-improving_42.wiki; code . ; sleep 3; ; wiki; cd 42-notes-private.wiki ; code .; sleep 3;  cur;
 9841  code --disable-extensions .
 9842  wiki; cd 42-projects.wiki; code .; sleep 1;   show_cur_subject; sleep 1; wiki; cd 42-notes-improving_42.wiki; code . ; sleep 3; ; wiki; cd 42-notes-private.wiki ; code .; sleep 3;  cur;
 9843  man strerr
 9844  man strerror
 9845  mn perror
 9846  man perror
 9847  cat outfile.txt
 9848  cat outfile_for_diff.txt
 9849  man access
 9850  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " /usr/bin/cat  outfile.txt; diff outfile.txt outfile_for_diff.txt\n
 9851  cat outfile
 9852  ./pipex Makefile cat cat OUTfile
 9853  ls /home/reciak/.brew/bin/cat
 9854  ./pipex Makefile 'echo Hello' fcat cat OUTfile
 9855  ./pipex Makefile 'echo Hello' caft OUTfile
 9856  ./pipex Makefile 'echo Hello' cat OUTfile
 9857  cat OUtfile
 9858  ./pipex Makefile 'echo Bye' caft OUTfile
 9859  ./pipex Makefile 'echo Bye' cat OUTfile
 9860  ./pipex Makefile 'echo Miau' cat OUTfile
 9861  git add inc/pipex.h  src/a_col_exiting/h_err_exit.c src/exec_pipeline.c src/main.c src/set_err.c 
 9862  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes   ./pipex Makefile "/usr/bin/echo Hi " cat  outfile_for_diff.txt; diff outfile.txt outfile_for_diff.txt\n
 9863  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'echo Miau' cawt OUTfile\n
 9864  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' cawt OUTfile\n
 9865  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' OUTfile OUTfile\n
 9866  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' ./OUTfile OUTfile\n
 9867  pwd
 9868  valgrind --leak-check=full --trace-children=yes --track-origins=yes --track-fds=yes  ./pipex Makefile 'ecasfho Miau' /home/reciak/github/42-projects/Ci2-pipex/OUTfile OUTfile\n
 9869  ./pipex Makefile 'echo Miau' cawt OUTfile
 9870  ./pipex Makefile '/usr/bin/echo Miau' cat OUTfile
 9871  gedit
 9872  ./pipex Makefile 'echo Hi' cat cat OUTfile
 9873  cat OUTfile
 9874  make CC_LESS_STRICT=1 DEBUG_VALGRIND=1 re_not_libft
 9875  ./pipex Makefile 'echo Hello' cat cat OUTfile
 9876  ./pipex Makefile 'esdfacho Hello' cat cat OUTfile
 9877  grep -rin "printf" src
 9878  rm OUT2 OUTfile outfile outfile.txt outfile2.txt outfile_for_diff.txt 
 9879  git add src/a_col_exiting/h_err_exit.c src/a_col_exiting/print_err.c src/a_col_exiting/print_exit_msg_and_exit.c src/a_col_tools/free_and_reset.c src/a_col_tools/tidy_up_and_reset_cmd_itmes.c src/exec_pipeline.c src/main.c src/open_files.c src/open_pipes.c src/parse_path.c src/set_err.c
 9880  ./pipex Makefile 'echo Hello' ./OUTfile cat OUTfile
 9881  git log --oneline
 9882  git branch
 9883  git checkout -b Ci2-pipex-submission-prep
 9884  norminette src
 9885  norminette inc
 9886  git rm .vscode/launch.json
 9887  git rm OLD_makefile
 9888  make update_INCS__SRCS__SRCS_BONUS
 9889  git rm makefile makefile_dir/rules/checks/check_variables.mk makefile_dir/rules/doc.mk  makefile_dir/rules/hyperlinks_clangd.mk  makefile_dir/rules/tests.mk  makefile_dir/rules/update_INCS__SRCS__SRCS_BONUS_and_view.mk 
 9890  git rm SRC_OLD
 9891  git rm src_OLD/
 9892  git rm -r src_OLD/
 9893  git rm tests
 9894  git rm -r tests
 9895  git push --set-upstream origin Ci2-pipex-submission-prep
 9896  git clone git@github.com:rciak/42-projects 42-projects_FRESH___PIPEX
 9897  cd Ci0-libft
 9898  open .
 9899  git rm makefile_dir/def_headers.mk makefile_dir/def_sources.mk 
 9900  git log
 9901  git stat
 9902  git diff --staged Makefile
 9903  rm -fr 42-projects_FRESH___PIPEX
 9904  git clone git@github.com:rciak/42-projects 42-projects_FRESH___PIPEX; cd 42-projects_FRESH___PIPEX/Ci2-pipex
 9905  mkdir libft
 9906  alias meld='flatpak run --file-forwarding org.gnome.meld'
 9907  git add libft/
 9908  meld  ../Ci0-libft libft
 9909  git add libft/Makefile
 9910  git status 
 9911  git commit
 9912  wiki
 9913  cd 42-notes-private.wiki
 9914  git status | grep -v "\.c"
 9915  show_norm
 9916  cd inc
 9917  cat pipex.h
 9918  head -30 pipex.h
 9919  head -20 pipex.h
 9920  head -15 pipex.h
 9921  head -12 pipex.h
 9922  cd src
 9923  cd a_col_exiting
 9924  for f in *.c; do head -12 "$f"; done
 9925  cd a_col_tools
 9926  clear; for f in *.c; do head -12 "$f"; done
 9927  git diff
 9928  git restore inc/pipex.h
 9929  make libftfclean
 9930  git rm src/a_col_exiting/print_err.c
 9931  git add inc/pipex.h
 9932  make 
 9933  ḿake
 9934  git add Makefile
 9935  git difftool --staged 
 9936  git commit 
 9937  grep -rin "memcpy" src
 9938  grep -rin "memcpy" libft
 9939  cd ..
 9940  nm -us pipex
 9941  grep -rin "memcpy" .
 9942  git ls-files
 9943  git rm .gitignore\n
 9944  git rm -fr tests\n
 9945  git rm -fr makefile\n
 9946  git rm -fr makefile_dir\n
 9947  cat Makefile
 9948  make all
 9949  make bonus
 9950  make pipex
 9951  make clean
 9952  funcheck -acobs  ./pipex Makefile hi  miau  cat  OUTFILE\n
 9953  funcheck -ac ./pipex Makefile hi  miau  cat  OUTFILE\n
 9954  ./pipex Makefile 'echo Hello' ./OUTfile cat '' OUTfile
 9955  ./pipex Makefile 'echo Hello' ./OUTfile cat '' cat OUTfile
 9956  bash
 9957  git libftfclean
 9958  rm OUTFILE libft/.timestamp_file_bonus_avoiding_unnecessary_relinking pipex
 9959  make DEBUG_VALGRIND=true re
 9960  ./pipex Makefile '' '' OUTfile
 9961  funcheck -ac ./pipex Makefile ls mia 'grep -rin' '' "" maiu wc outfile
 9962  exit
 9963  rm OUTfile
 9964  rm libft/.timestamp_file_bonus_avoiding_unnecessary_relinking  pipex
 9965  cur
 9966  cd github
 9967  l
 9968  cd 42-projects_FRESH___PIPEX
 9969  cd Ci2-pipex
 9970  make
 9971  funcheck -ac ./pipex Makefile ls mia 'grep -rin' '' "" outfile
 9972  valgrjind ./test
 9973  funcheck -ac ./pipex Makefile ls mia  '' "" outfile
 9974  norminette
 9975  git checkout -b Ci2-pipex-submission-prep-debugging
 9976  git commit /a
 9977  git commit -a 
 9978  git checkout Ci2-pipex-submission-prep
 9979  ls
 9980  make re_not_libft
 9981  code .
 9982  make re
 9983  make fclean
 9984  make DEBUG_VALGRIND=1 re_not_libft
 9985  make DEBUG_VALGRIND=1 re
 9986  man waitpid
 9987  funcheck -ac ./pipex Makefile '' '' OUTfile
 9988  git status
 9989  git difftool
 9990  git commit -a
 9991  git push
 9992  valgrind ./pipex infile cat cat outfile
 9993  export PS1="$ "
 9994  clear
 9995  ls -l
 9996  touch infile
 9997  (ulimit -u 20; ./pipex infile cat "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" outfile)
 9998  echo $?
 9999  (ulimit -u 20; valgrind ./pipex infile cat "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" "sleep 20" outfile)
10000  exit
10001  cd github
10002  ls
10003  cd 42-projects_FRESH___PIPEX
10004  ls
10005  git status
10006  git push
10007  pwd
10008  make
10009  ls
10010  cd Ci2-pipex
10011  make
10012  make -n
10013  make re
10014  ./pipex
10015  ./pipex infile cat cat outfile
10016  cat outfile
10017  cat infile
10018  make
10019  cat infile
10020  ./pipex infile cat cat outfile
10021  cat outfile
10022  chmod 000 outfile
10023  ./pipex infile cat cat outfile
10024  valgrind ./pipex infile cat cat outfile
10025  valgrind ./pipex infile cat "sleep 5" outfile
10026  valgrind ./pipex infile "sleep 5" cat outfile
10027  < infile "sleep 5"  | cat > outfile
10028  < infile sleep 5  | cat > outfile
10029  chmod 644 outfile
10030  unset PATH
10031  /usr/bin/valgrind ./pipex infile cat cat outfile
10032  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10033  make
10034  /usr/bin/make
10035  export PATH=/usr/bin
10036  make
10037  unset PATH
10038  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10039  bash
10040  /usr/bin/valgrind env -i ./pipex infile cat cat outfilemake
10041  /usr/bin/valgrind /usr/bin/env -i ./pipex infile cat cat outfilemake
10042  export PATH="::::"
10043  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10044  make
10045  /usr/bin/make
10046  export PATH="/usr/bin"
10047  make
10048  export PATH="::::"
10049  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10050  touch cat
10051  /usr/bin/touch cat
10052  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10053  /usr/bin/chmod +x cat
10054  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10055  /usr/bin/ls
10056  cd ..
10057  ls
10058  export PATH="/usr/bin"
10059  ls
10060  Ci2-pipex/pipex
10061  Ci2-pipex/././pipex
10062  cd Ci2-pipex
10063  ls
10064  export PATH="::::"
10065  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10066  make
10067  export PATH="/usr/bin"
10068  make
10069  export PATH="::::"
10070  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10071  export PATH="/usr/bin"
10072  cat cat
10073  export PATH="/usr/bin"
10074  export PATH="::::"
10075  /usr/bin/valgrind ./pipex infile cat cat outfilemake
10076  /usr/bin/valgrind ./pipex infile cat cat outfile
10077  bash
10078  /usr/bin/bash
10079  export PATH="/usr/bin"
10080  bash
10081  export PATH="::::"
10082  /usr/bin/valgrind ./pipex infile cat cat outfile
10083  time ./pipex infile "sleep 5" "sleep 10" outfile
10084  export PATH="/usr/bin"
10085  time ./pipex infile "sleep 5" "sleep 10" outfile
10086  time ./pipex infile "sleep 5" "sleep 10" cat outfile
10087  time ./pipex infile "sleep 5" "sleep 10" cat cat outfile
10088  show_cur_subject
10089  (ulimit -n 15; /usr/bin/valgrind --track-fds=yes ./pipex infile cat cat cat cat cat cat outfile)
10090  (ulimit -n 15; /usr/bin/valgrind --track-fds=yes ./pipex infile cat cat cat cat cat cat cat cat cat cat outfile)
10091  (ulimit -n 15; /usr/bin/valgrind --trace-children=yes --track-fds=yes ./pipex infile cat cat cat cat cat cat cat cat cat cat outfile)
10092  cur
10093  ls
10094  cd src_OLD
10095  code .
10096  git checkout main
10097  ls
10098  git log --oneline
10099  git checkout Ci2-pipex
10100  ls
10101  code .
10102  bash
10103* cur
10104* git checkout Ci2-pipex-submission-prep
10105* git pull
10106* cd ..
10107* cd 42-projects_FRESH___PIPEX
10108* cd Ci2-pipex
10109* git status
10110* git commit -a
10111* git push
10112* ls
10113* exit
10114* git commit -a
10115* git push
