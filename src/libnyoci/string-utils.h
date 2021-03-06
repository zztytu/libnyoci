/*!	@file string-utils.h
**	@author Robert Quattlebaum <darco@deepdarc.com>
**	@brief Various string utilities
**
**	Originally published 2014-8-29.
**
**	This file was written by Robert Quattlebaum <darco@deepdarc.com>.
**
**	This work is provided as-is. Unless otherwise provided in writing,
**	Robert Quattlebaum makes no representations or warranties of any
**	kind concerning this work, express, implied, statutory or otherwise,
**	including without limitation warranties of title, merchantability,
**	fitness for a particular purpose, non infringement, or the absence
**	of latent or other defects, accuracy, or the present or absence of
**	errors, whether or not discoverable, all to the greatest extent
**	permissible under applicable law.
**
**	To the extent possible under law, Robert Quattlebaum has waived all
**	copyright and related or neighboring rights to this work. This work
**	is published from the United States.
**
**	I, Robert Quattlebaum, dedicate any and all copyright interest in
**	this work to the public domain. I make this dedication for the
**	benefit of the public at large and to the detriment of my heirs and
**	successors. I intend this dedication to be an overt act of
**	relinquishment in perpetuity of all present and future rights to
**	this code under copyright law. In jurisdictions where this is not
**	possible, I hereby release this code under the Creative Commons
**	Zero (CC0) license.
**
**	 * <http://creativecommons.org/publicdomain/zero/1.0/>
*/

#ifndef NYOCI_string_utils_h
#define NYOCI_string_utils_h

#include <stdint.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

NYOCI_INTERNAL_EXTERN char * uint32_to_hex_cstr(char *str, uint32_t v);
NYOCI_INTERNAL_EXTERN char * uint32_to_dec_cstr(char s[], uint32_t n);
NYOCI_INTERNAL_EXTERN char * int32_to_dec_cstr(char s[], int32_t n);

NYOCI_INTERNAL_EXTERN bool str2bool(const char* str);

#if __AVR__
#include <avr/pgmspace.h>
#define strnequal_const(a, const_b, len_a) (strncmp_P(a, PSTR(const_b),len_a) == 0)
#define strequal_const(a, b) (strcmp_P(a, PSTR(b)) == 0)
#define strhasprefix_const(a, b) (strncmp_P(a, PSTR(b), sizeof(b) - 1) == 0)
#else
#define strnequal_const(a, const_b, len_a) (strncmp(a, const_b,len_a) == 0)
#define strequal_const(a, b) (strcmp(a, b) == 0)
#define strhasprefix_const(a, b) (strncmp(a, b, sizeof(b) - 1) == 0)
#endif

#if defined(__cplusplus)
}
#endif

#endif
