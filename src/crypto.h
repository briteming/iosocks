/*
 * encrypt.h - encryption and decryption
 *
 * Copyright (C) 2014 - 2015, Xiaoxiao <i@xiaoxiao.im>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>


typedef struct
{
	int i;
	int j;
	uint8_t s[256];
} rc4_evp_t;

typedef struct
{
	rc4_evp_t enc, dec;
} crypto_evp_t;

extern void crypto_init(crypto_evp_t *evp, const void *key, const void *iv);
extern void crypto_encrypt(void *buf, size_t len, crypto_evp_t *evp);
extern void crypto_decrypt(void *buf, size_t len, crypto_evp_t *evp);


#endif // CRYPTO_H