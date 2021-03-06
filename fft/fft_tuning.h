/* fft_tuning.h -- autogenerated by tune-fft */

#ifndef FFT_TUNING_H
#define FFT_TUNING_H

#include "mpir.h"
#include "gmp-impl.h"

#ifndef FFT_TAB /* check if we already have tuning values */

#if GMP_LIMB_BITS == 64

#define FFT_TAB \
   { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 2, 1 }, { 1, 0 } }

#define MULMOD_TAB \
   { 4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 3, 2, 2, 2, 2, 1, 1 }

#define FFT_N_NUM 19

#define FFT_MULMOD_2EXPP1_CUTOFF 128

#else /* 32 bits */

#define FFT_TAB \
   { { 3, 3 }, { 3, 2 }, { 2, 1 }, { 2, 1 }, { 0, 0 } }

#define MULMOD_TAB \
   { 4, 3, 3, 3, 3, 2, 2, 2, 3, 2, 2, 2, 2, 1, 1 }

#define FFT_N_NUM 15

#define FFT_MULMOD_2EXPP1_CUTOFF 256

#endif

#endif

#endif
