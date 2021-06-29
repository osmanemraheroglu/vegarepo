#pragma once

#include <inttypes.h>
#include "crypto.h"

typedef struct roinput_t {
  uint64_t* fields;
  PackedBits bits;
  size_t fields_len;
  size_t fields_capacity;
  size_t bits_len;
  size_t bits_capacity;
} ROInput;

void roinput_add_field(ROInput *input, const Field a);
void roinput_add_scalar(ROInput *input, const Scalar a);
void roinput_add_bit(ROInput *input, bool b);
void roinput_add_bytes(ROInput *input, const uint8_t *bytes, size_t len);
void roinput_add_uint32(ROInput *input, const uint32_t x);
void roinput_add_uint64(ROInput *input, const uint64_t x);

size_t roinput_to_fields(uint64_t *out, const ROInput *input);
void roinput_to_bytes(uint8_t *out, const ROInput *input);
