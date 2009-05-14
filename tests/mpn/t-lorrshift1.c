/* Test mpn_lshift1 mpn_rshift1 mpn_lshift2 mpn_rshift2

  Copyright 2008 Jason Moxham

  This file is part of the MPIR Library.

  The MPIR Library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation; either version 2.1 of the License, or (at
  your option) any later version.

  The MPIR Library is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
  License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with the MPIR Library; see the file COPYING.LIB.  If not, write
  to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.

*/

#include <stdio.h>
#include <stdlib.h>
#include "mpir.h"
#include "gmp-impl.h"
#include "tests.h"

int
main (void)
{
  unsigned long n;
  gmp_randstate_ptr rands;
  int j, i1, k1, k2;
  mp_limb_t xp[10000], zp[10000], cp[10000];

  tests_start ();
  rands = RANDS;


  for (i1 = 0; i1 < 2; i1++)
    {
      for (n = 1; n < 1000; n++)
	{
	  for (j = 1; j < 10; j++)
	    {
	      if (i1 == 0)
		{
		  mpn_random (xp, n);
		}
	      else
		{
		  mpn_random2 (xp, n);
		}
	      k1 = mpn_lshift1 (zp, xp, n);
	      k2 = mpn_lshift (cp, xp, n, 1);
	      if (k1 != k2)
		{
		  printf ("mpn_lshift1 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (zp, cp, n) != 0)
		{
		  printf ("mpn_lshift1 wrong\n");
		  abort ();
		}
	      k1 = mpn_rshift1 (zp, xp, n);
	      k2 = mpn_rshift (cp, xp, n, 1);
	      if (k1 != k2)
		{
		  printf ("mpn_rshift1 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (zp, cp, n) != 0)
		{
		  printf ("mpn_rshift1 wrong\n");
		  abort ();
		}
              k1 = mpn_lshift2 (zp, xp, n);
	      k2 = mpn_lshift (cp, xp, n, 2);
	      if (k1 != k2)
		{
		  printf ("mpn_lshift2 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (zp, cp, n) != 0)
		{
		  printf ("mpn_lshift2 wrong\n");
		  abort ();
		}
	      k1 = mpn_rshift2 (zp, xp, n);
	      k2 = mpn_rshift (cp, xp, n, 2);
	      if (k1 != k2)
		{
		  printf ("mpn_rshift2 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (zp, cp, n) != 0)
		{
		  printf ("mpn_rshift2 wrong\n");
		  abort ();
		}
	    }
	}
    }

  for (i1 = 0; i1 < 2; i1++)
    {
      for (n = 1; n < 1000; n++)
	{
	  for (j = 1; j < 10; j++)
	    {
	      if (i1 == 0)
		{
		  mpn_random (xp, n);
		}
	      else
		{
		  mpn_random2 (xp, n);
		}
	      k2 = mpn_lshift (cp, xp, n, 1);
	      k1 = mpn_lshift1 (xp, xp, n);
	      if (k1 != k2)
		{
		  printf ("mpn_lshift1 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (xp, cp, n) != 0)
		{
		  printf ("mpn_lshift1 wrong\n");
		  abort ();
		}
	    }
	}
    }

  for (i1 = 0; i1 < 2; i1++)
    {
      for (n = 1; n < 1000; n++)
	{
	  for (j = 1; j < 10; j++)
	    {
	      if (i1 == 0)
		{
		  mpn_random (xp, n);
		}
	      else
		{
		  mpn_random2 (xp, n);
		}
	      k2 = mpn_rshift (cp, xp, n, 1);
	      k1 = mpn_rshift1 (xp, xp, n);
	      if (k1 != k2)
		{
		  printf ("mpn_rshift1 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (xp, cp, n) != 0)
		{
		  printf ("mpn_rshift1 wrong\n");
		  abort ();
		}
	    }
	}
    }
  for (i1 = 0; i1 < 2; i1++)
    {
      for (n = 1; n < 1000; n++)
	{
	  for (j = 1; j < 10; j++)
	    {
	      if (i1 == 0)
		{
		  mpn_random (xp, n);
		}
	      else
		{
		  mpn_random2 (xp, n);
		}
	      k2 = mpn_lshift (cp, xp, n, 2);
	      k1 = mpn_lshift2 (xp, xp, n);
	      if (k1 != k2)
		{
		  printf ("mpn_lshift2 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (xp, cp, n) != 0)
		{
		  printf ("mpn_lshift2 wrong\n");
		  abort ();
		}
	    }
	}
    }

  for (i1 = 0; i1 < 2; i1++)
    {
      for (n = 1; n < 1000; n++)
	{
	  for (j = 1; j < 10; j++)
	    {
	      if (i1 == 0)
		{
		  mpn_random (xp, n);
		}
	      else
		{
		  mpn_random2 (xp, n);
		}
	      k2 = mpn_rshift (cp, xp, n, 2);
	      k1 = mpn_rshift2 (xp, xp, n);
	      if (k1 != k2)
		{
		  printf ("mpn_rshift2 wrong\n");
		  abort ();
		}
	      if (mpn_cmp (xp, cp, n) != 0)
		{
		  printf ("mpn_rshift2 wrong\n");
		  abort ();
		}
	    }
	}
    }
    
  tests_end ();
  exit (0);
}
