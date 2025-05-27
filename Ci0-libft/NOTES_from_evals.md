# Notes from Evals

## Notes from Eval by Thomas (tkolar), given on Monday 26.05.2025

* Allocating 0 bytes: `NULL` or "unique pointer" allowed by man page;
  new subject though request it to be a "unique pointer". 
  Hans Joachim mentioned:
  https://www.reddit.com/r/C_Programming/comments/wpghky/i_have_been_trying_to_understand_what_malloc0/?tl=de

  [C Standard 99, draft Septermber 7, 2007 ]
  (https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)

  On p. 313 it reads:
  ```text
  If the size of the space requested is zero, the behavior is implementation-
  defined: either a null pointer is returned, or the behavior is as if the size
  were some nonzero value, except that the returned pointer shall not be used 
  to access an object.
  ```

  --> In alloc: Use for 0 bytes allocation not malloc (0) but e.g. malloc(1)

* Strukturverlauf gleich halten:
  * Z.B. Immer nur eine non static function pro file
  (27.5.2025: Gedanke: Vielleicht nur für die nicht ft_x_... funktionen?)