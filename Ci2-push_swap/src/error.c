/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:30:34 by reciak            #+#    #+#             */
/*   Updated: 2025/07/30 10:16:04 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file  error.c
 * @brief Convenient error handling and printing.
 */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

/**
 * @brief Complements a push_swap error code, by the corresponding
 *        error messages that are defined here.
 * @note
 * @param[in] error_code, cf. @code enum e_push_swap_errors @endcode in
 *                        push_swap.h
 * @return A @c t_err object containing \p errorcode and the corresponding
 *         error message.
 */
t_err	error(enum e_push_swap_errors error_code)
{
	static const t_err	err[] = {
	{ERR_NONE, "push_swap:"
		GREEN"Success" " - no error detected in input."
		RESET
		"\n\nYet mourning..."
		"\n"
		"\n  Oh why subject is declining"
		"\n  my purpose by defining;"
		"\n  Of these lines no print"
		"\n  when of args there is no hint!"
		"\n"},
	{ERR_ARG_NUM, "push_swap:"
		YELLOW"providing 0 numbers is valid but questionable."
		GREEN"- I'd like to suggest to provide at least one reasonable integer,"
		RED" but the subject prevents that I get ever printed!"
		RESET},
	{ERR_ARGV, "push_swap:"
		RED" Invalid arguments"
		GREEN" - Only integers (of type int) are allowed, appearing only once."
		RESET},
	{ERR_DUPLICATE, "push_swap:" RED"Duplicate detected"RESET},
	{ERR_MALLOC, "push_swap:" RED" Memory allocation failed"RESET},
	{ERR_LOGIC, RED"push_swap: logic is flawed or wrongly implemented"RESET}
	};

	return (err[error_code]);
}

/**
 * @brief Reactions to both empty input and errors.
 * @note Empty input is not considered as an error by the subject
 *       which makes sense, provided an empty stack `a` is regarded as sorted.
 *       The latter is consistent to common logical practice in mathematics:
 *       The statement $\forall x\in\emptyset: P(x)$ is regarded as true
 *       for any property `P`.
 * @note In addition to the subject requirement
 *       `it must display "Error" followed by an newline on the standard error.`
 *       more specific error messages are printed, which deems feasible since
 *       the subject does not specify if additional printings are ok or not.
 * @param[in] err: Error code and message.
 */
void	handle_error(t_err err)
{
	if (err.code == ERR_ARG_NUM)
		return ;
	if (err.code != ERR_NONE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putnbr_fd(err.code, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd((char *) err.msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
