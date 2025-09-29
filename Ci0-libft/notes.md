# Notes to this version of libft

Timestamp (newest first)

* 29.09.2025
* 25.09.2025
* 11.09.2025


## On the organisation of the source code

The source code is distributed in several subfolders of `src/`.
This is done such that the two needs

* **Ease of navigating:**
  * The `ft_` functions required by the libft-project can be easily found
  * All other functions can be found by topic
* **Fast estimation of reliability:**
      At one glance it should be clear which functions are very well tested
      (e.g. by testers from Tripouille) or not so well tested.

are both taken into account.

1. The *submitted code* for the **libft project** is mostly contained
   in the subfolders

    ```bash
    01_libft_libc
    02_libft_others
    03_libft_singly_linked_list
    ```

    while a few (non static) helper functions and tools that
    otherwise might get forgotten, i.e. practically "lost" in
    these folders have ended up in one the `x` tagged
    subfolders and the `ft_x` subfolders therein.

2. Functions in folders with `ft_xx_` prefix, see 07_conversions
   were developed alongside the **ft_printf project** (if memory is correct).

## Descriptions of what is in which subfolders

* In the folder

    ```bash
    00_libft_piscine
    ```

    is currently only the piscine function `ft_strcmp` - a relative of
    `01_libft_libft/ft_strncmp.c: ft_strncmp` (that was strangely not requested
    in the libft subject sheet.)

* In the folders

    ```bash
    01_libft_libc
    02_libft_others
    03_libft_singly_linked_list
    ```

    reside the functions that were requested in the libft Project.
    Some of these functions might call non static helper functions being
    now contained in other various `ft_x` subfolders contained elsewhere.
    E.g. `ft_calloc` calls `calloc_uninit` now being contained in
    `./09_memtools/ft_x`.

* The folders

    ```bash
    04_ft_printf
    05_get_next_line
    ```

    contain code from the respective projects of Common Core Circle 1.
    Note though that many astatic (non static) helper functions for ft_printf
    are located in `src/08xx_output/ft_xx_wrappers_for_ft_printf`, calling
    themselves functions placed in `src/08xx_output/ft_xx_behind_wrappers` and
    `src/08xx_output/ft_xx_astatic_helpers`

* As of 29.09.2025 the folder

    ```bash
    06_doubly_linked_list
    ```

    contains the following 8 tools for dealing with double linked lists,
    be it in linear or circular form.

    ```bash
    dl_lst_add_after
    dl_lst_add_before
    dl_lst_circularize
    dl_lst_clear
    dl_lst_linearize
    dl_lst_new_nd
    dl_lst_size
    dl_lst_type
    ```

    They were developed during the **push_swap** project.

* As of 29.09.2025 the folder

  ```bash
  07_conversions
  ```

  contains the conversion functions

  ```bash
  atof_strict
  atoi_strict
  atoll_strict
  atoi_proper
  ```

  * `atoi_proper` is a kind of ft_atoi with error feedback,
  * `atoi_strict` is more rigorous than `atoi_proper`; in contrast 
    to atoi_proper() and ft_atoi() weird input like
    `123abc` will not be converted into the number `123`, but atoi_strict()
    will return "0" instead and set an error code - to `E_ATOI_BAD_STRING`.
  * `atoll_strict` and `atof_strict` do similar things for long long intgers
    and doubles (atof_strict is far away from being perfect,
    but as long as one does not
    cause "RANGE_PANIC" by staying away from e.g. things like
    +infinity, -infinity, NaN, and DBL_MIN it should be usuable for
    *reasonable* input, cf. also the documentation of that function.)

* The Folder

  ```bash
  08xx_output
  ```

  * has various `ft_xx`... subfolders that contain code that like was completely
    developed alongside the `ft_printf project`.

  * `ft_putllnbr_fd` is used in the Ci2 fractol Project (used in there for
    printing doubles and complex numbers to the terminal).

* As of 29.09.2025 the folder

  ```bash
  09x_memtools
  ```

  contains the functions `calloc_uninit` and `si_is_overflow`
  (both in the ft_x subfolder). They were coded a part of the libft project
  (though the timestamp of `calloc_uninit.c` suggests differently).

* The folder

  ```bash
  10x_string_tools
  ```

  contain string tools that were used already during the libft project,
  see ("ft_x" subfolder) and some other useful looking tools,
  some of them are a kind of off-spring when dealing with ft_split.

* The folder

  ```bash
  11x_math
  ```

  contain a few math helpers. Again those in "ft_x" were used in the libft
  project. `si_max` is not put in that "ft_x" subfolder, since it is not called
  by a libft core function (in contrast to `si_min`).