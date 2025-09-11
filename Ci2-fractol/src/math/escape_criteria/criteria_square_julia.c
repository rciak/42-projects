/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   criteria_square_julia.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:19:07 by reciak            #+#    #+#             */
/*   Updated: 2025/08/31 22:52:40 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file criteria_square_julia.c
 * @brief Stores the definition of criteria_square_julia()
 */

#include "fractol.h"

/**
 * @brief Implements the square escape criteria 
 *        |z|_\infty := max{|z.re|, |z.im|} > max{2, |w|_\infty}
 *        for the Mandelbrot / Multibrot sets.
 * @note For the mbrot criteria the complex number `w` is not needed,
 *       but since the criteria are used as a kind of plugin in,
 *       cf. fractol.h, where the function pointer refers to a function
 *       of both `z` and `w`.
 * @note The following goes back to a mathematical reasoning when doing
 *       fractol the first time. A proof was done by R. Ciak on paper for
 *       the function z |--> z^2 + w. It feels like the escape criteria
 *       |z| > 2 and |z| > max {|w|, 2}, respectively, should work also for
 *       multibrot fractals and their corresponding julia sets, respectively.
 * @note "REMARK 1: For the calculation of the Mandelbrot set the inequality
 *       |z| > 2  can also be used as escape criterion. But NOT neccesarily for
 *       the calculation of the Julia set if |w| > 2, as the following
 *       examples illustrates.
 *       For the choice w = -12 the function f: C->C given by
 *       f(z) := z^2 - 12
 *       we have f(-3) = 9 - 12 = -3 (*).
 *       Therefor the starting point z = -3 generates the constant sequence
 *       -3, -3 , -3, ...  which is clearly not escaping to infinity;
 *       because of |-3| = 3 > 2 it is thereby shown that the inequality |z| > 2
 *       can not be used as escape criterion for the calculation of the
 *       Julia set.
 *       The second remark shows two feasible escape criteria (A) and (B).
 *
 *       Detail to (*):
 *         Because of |f'(-3)| = 2|-3| = 6 > 1 the fixpoint -3 is repelling.
 *         Thus it belongs to the Julia Set,
 *         see ??[Scripts on complex chaotic systems?, Book of Milnor?].
 *
 *       REMARK 2: Given any complex numbers z, w with 
 *       ***********************************
 *       *   |z| > |w| and |z| > 2 ,   (A) *
 *       ***********************************
 *       the inverse triangle inequality gives
 *         |z^2 + w| / |z| >= (|z|^2 - |w|) / |z| = |z| - |w|/|z| =: q(|z|) > 1
 *       and hence
 *         |z^2 + w | >= q(|z|) |z| .
 *       Since q is monotonic increasing in |z| this implies
 *       that a sequence z_0, z_1, z_2, z_3, ... of iterates of f(.) = (.)^2 + w
 *       will escape to infinity whenever the condition (A) is fulfilled.
 *
 *       The subsequent function implements not condition A but another
 *       condition (B) which is though sufficient for (A) and hence also 
 *       an escape condition.
 *       Writing z = x + iy and w = a + ib with real numbers x, y, a, b we have
 *         |w| <= |a + ib| <= |a| + |ib| = |a| + |i||b| = |a| + |b| .
 *       Therefore the condition 
 *          |z| > |a| + |b| and |z| > 2
 *       would imply (A). This condition in turn would hold true if we have
 *       *************************************************************
 *       *   max(|x|,|y|) > |a| + |b|  and  max(|x|,|y|) > 2 .   (B) *
 *       *************************************************************"
 *
 *       It is criteria (B) that is implemented.
 *
 * @param[in] \p z, \p w The pair of complex numbers to be checked.
 * @return
 *          * true, if the escape criteria is meet
 *          * false, else
 */
bool	criteria_square_julia(t_cmplx z, t_cmplx w)
{
	if (fabs(z.re) > fabs(w.re) + fabs(w.im) && fabs(z.re) > 2.0)
		return (true);
	else if (fabs(z.im) > fabs(w.re) + fabs(w.im) && fabs(z.im) > 2.0)
		return (true);
	return (false);
}
