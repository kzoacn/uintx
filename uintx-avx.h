#ifndef UINTX_AVX_H
#define UINTX_AVX_H

#include <stdint.h>
#include <stdbool.h>

typedef __uint128_t  uint128_t;

typedef uint128_t uint256_t[2];

static const __uint128_t UINT128_ZERO = 0;
static const __uint128_t UINT128_MAX = ~UINT128_ZERO;

bool less_u256(const uint256_t *x, const uint256_t *y)
{
  return (*x)[1]<(*y)[1] || ((*x)[1]==(*y)[1]&&(*x)[0]<(*y)[0]);
}

void set0_u256(uint256_t *z)
{
  (*z)[0] = (*z)[1] = 0;
}
void set1_u256(uint256_t *z)
{
  (*z)[0] = 1;
  (*z)[1] = 0;
}

void add_u256(uint256_t *z, const uint256_t *x, const uint256_t *y)
{
  uint128_t c = UINT128_MAX-(*y)[0]<(*x)[0] ? 1 : 0;
  (*z)[0]=(*x)[0]+(*y)[0];
  (*z)[1]=(*x)[1]+(*y)[1]+c;
}

void sub_u256(uint256_t *z, const uint256_t *x, const uint256_t *y)
{
  uint128_t c = (*x)[0]<(*y)[0] ? 1 : 0;
  (*z)[0]=(*x)[0]-(*y)[0];
  (*z)[1]=(*x)[1]-(*y)[1]-c;
}

#endif
