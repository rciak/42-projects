/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_test_ft_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:26:26 by reciak            #+#    #+#             */
/*   Updated: 2025/06/17 22:09:13 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//  Original version created by perplexity via the promt:
//
//  Can you please write me a main (containing argc and argv) 
//  that compares my ft_printf with the original printf: 
//  Put the output of the original and the ft version on the screen such 
//  that the user can compare them optically. 
//  Also check if the return values are the same?
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"


int main(int argc, char **argv)
{
    // Example format and arguments for demonstration
    // You can modify this to use argc/argv or test various formats
    const char *format = "Hello, %s! Number: %d, Hex: %x\n";
    const char *str = (argc > 1) ? argv[1] : "World";
    int num = (argc > 2) ? atoi(argv[2]) : 42;
    int hex = (argc > 3) ? atoi(argv[3]) : 255;

    int ret_printf, ret_ftprintf;

    printf("=== Standard printf ===\n");
    ret_printf = printf(format, str, num, hex);
    printf("Return value: %d\n", ret_printf);

    printf("\n=== Your ft_printf ===\n");
    ret_ftprintf = ft_printf(format, str, num, hex);
    printf("Return value: %d\n", ret_ftprintf);

    printf("\n=== Comparison ===\n");
    if (ret_printf == ret_ftprintf)
        printf("Return values are the same.\n");
    else
        printf("Return values are DIFFERENT!\n");

    return 0;
}


// //// FOR HANDING OVER FROMAT_STRING
// int main(int argc, char **argv)
// {
//     // Example format and arguments for demonstration
//     // You can modify this to use argc/argv or test various formats

// 	char *format = (argc > 1) ? argv[1]: "Hi, %s! Number: %d, Hex: %x\n";
// 	const char *str = (argc > 2) ? argv[2] : "World";
// 	int num = (argc > 3) ? atoi(argv[2]) : 42;
//     int hex = (argc > 4) ? atoi(argv[3]) : 255;

//     int ret_printf, ret_ftprintf;

//     printf("=== Standard printf ===\n");
//     ret_printf = printf(format, str, num, hex);
//     printf("Return value: %d\n", ret_printf);

//     printf("\n=== Your ft_printf ===\n");
//     ret_ftprintf = ft_printf(format, str, num, hex);
//     printf("Return value: %d\n", ret_ftprintf);

//     printf("\n=== Comparison ===\n");
//     if (ret_printf == ret_ftprintf)
//         printf("Return values are the same.\n");
//     else
//         printf("Return values are DIFFERENT!\n");

//     return 0;
// }


////
////  TEST if no format string is given but NULL
////
// int main(int argc, char **argv)
// {
//      int ret_printf, ret_ftprintf;

//      printf("=== Standard printf ===\n");
//     ret_printf = printf(NULL);
//     printf("Return value: %d\n", ret_printf);

//     printf("\n=== Your ft_printf ===\n");
//     ret_ftprintf = ft_printf(NULL);
//     printf("Return value: %d\n", ret_ftprintf);

//     printf("\n=== Comparison ===\n");
//     if (ret_printf == ret_ftprintf)
//         printf("Return values are the same.\n");
//     else
//         printf("Return values are DIFFERENT!\n");

//     return 0;
// }

