/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:04:17 by reciak            #+#    #+#             */
/*   Updated: 2025/10/11 21:19:48 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

// "Geklaut" von Thomas Kolar
void redir() {
	cr_redirect_stdout();
	// not necessary here, but not the worst idea in general
	setbuf(stdout, NULL);
	cr_redirect_stderr();
}

Test(hello, output, .init = redir) {
	char *greeting = "Hello World!\n\n";
	hello();
	cr_assert_stdout_eq_str(greeting);
}

Test(bye, output, .init = redir) {
	char *greeting = "Farewell!\n\n";
	bye();
	cr_assert_stdout_eq_str(greeting);
}