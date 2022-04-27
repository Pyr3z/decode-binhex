/** @file   strhash.h
 *  @author [Levi Perez](https://leviperez.dev/3pw)
 *  @date   2022-04-26
 *  
 *  @brief  ~ UNFINISHED (/ abandoned?)
 * 
 *  @details
 *    https://en.wikipedia.org/wiki/BinHex#BinHex_4_(.hqx)
**/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define N_HQX 64 /* looks & quacks like Base64; is in fact not Base64 */
static const char HQX[]
  = "!\"#$%&'()*+,-012345689@ABCDEFGHIJKLMNPQRSTUVXYZ[`abcdefhijklmpqr";

static const char LN1[]
  = "(This file must be converted with BinHex 4.0)";


/* ~ PROGRAM ENTRY */

int main(int argc, const char* argv[])
{
  int i, ret;

  if (argc < 2)
    return EXIT_FAILURE;

  ret = 0;
  for (i = 1; i < argc; ++i)
  {
    ret += !!TryConvertBinHex4(argv[i]);
  }

  return ret ? EXIT_SUCCESS : EXIT_FAILURE;
}


static int TryConvertBinHex4(const char* filename)
{
  FILE* file          = NULL;
  char  buf[N_HQX+1]  = { 0 };
  int   colon         = 0;

  if (!(file = fopen(filename, "rb"))       ||
      fgets(buf, sizeof(buf), file) == NULL ||
      strncmp(buf, LN1, N_HQX) != 0)            /* check exact line contents */
  {
    return 0;
  }

  while (fgets(buf, sizeof(buf), file) != NULL)
  {
    if (!colon)
    {

    }
    else
    {

    }
  }

  fclose(file);
  return 1;
}
