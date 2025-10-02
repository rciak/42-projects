/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ci1-ft_printf-crtests.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:41 by reciak            #+#    #+#             */
/*   Updated: 2025/06/08 16:11:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI1_FT_PRINTF_CRTESTS_H
# define CI1_FT_PRINTF_CRTESTS_H
# include <stddef.h>
# include <signal.h>
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <criterion/parameterized.h>

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"

# define BUF_SIZE_EXPECTED 4096	

typedef struct s0_param
{
	const char*		str;
}	t0_param;

typedef struct s11c_param
{
	const char*		str;
	char			arg1;
}	t11c_param;

typedef struct s12s_param
{
	const char*		str;
	char*			arg1;
}	t12s_param;

typedef struct s13p_param
{
	const char*		str;
	void*			arg1;
}	t13p_param;

typedef struct s14di_param
{
	const char*		str;
	int				arg1;
}	t14di_param;

typedef struct s15uxX_param
{
	const char*		str;
	unsigned int	arg1;
}	t15uxX_param;

typedef struct s16_param
{
	const char*		str;
	double			arg1;
}	t16_param;


#endif
