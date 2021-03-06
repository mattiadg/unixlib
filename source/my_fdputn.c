/*
 * my_fdputn.c
 *
 * Licensed under GNU GPL v3
 * Contributors:
 * - Garuda1 <garuda1@protonmail.com>
 *
 */

#include <unixlib.h>
#include <sys/types.h>

/*
 * This function prints nb
 * as ASCII to fd
 *
 */

void my_fdputn(const int fd, const int n)
{
  int nb;
  int mod;

  nb = n;
  mod = 0;
  if (nb < 10 && nb > -1)
    my_fdputc(fd, nb + 48);
  if (nb < 0)
  {
    my_fdputc(fd, '-');
    nb *= -1;
    if (nb < 10 && nb > -1)
      my_fdputn(fd, nb);
  }
  if (nb > 9)
  {
    mod = nb % 10;
    my_fdputn(fd, nb / 10);
    my_fdputc(fd, mod + 48);
  }
}
