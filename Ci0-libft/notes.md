# Notes to this version of libft

## Remarks on the organisation of the source code

**Timestamp (newest first)**

* 11.09.2025

The source code is distributed in several subfolders of `src/`.
This is done such that the two needs

* **Ease of navigating:**
  * The `ft_` functions required by the libft-project can be easily found
  * All other functions can be found by topic
* **Fast estimation of reliability:**
      At one glance it should be clear which functions are very well tested (e.g. by testers from Tripouille) or not so well tested.

1. The submitted code for the libft project is mostly contained in the subfolders

    ```bash
    01_libft_libc
    02_libft_others
    03_libft_singly_linked_list
    ```

    while a few (non static) helper functions and tools that
    otherwise might get forgotten, i.e. practically "lost" in
    these folders have ended up in one the `@` tagged
    subfolders where they thematically rather belong to

    ```bash
    09@_string_tools
    10@_math
    99@_miscellaneous
    ```

    Those functions are recognizable by the `ft_x_` - prefix
    of the name of the file or folder they are contained in.

2. A remark regarding the `ft_xx_` prefix (if memory is valid):
    The corresponding (output) functions were used in the
    ft_printf project.