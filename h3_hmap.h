/* Modified 2016 by Joel Bosveld (wboqm) */

/* Declarations for System V style searching functions.
   Copyright (C) 1995-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef H3_HMAP_H
#define	H3_HMAP_H 1


/* For use with hsearch(3).  */
#ifndef __COMPAR_FN_T
# define __COMPAR_FN_T
typedef int (*__compar_fn_t) (const void *, const void *);
#endif

/* Action which shall be performed in the call the hsearch.  */
typedef enum
  {
    SELECT,
    INSERT,
    UPDATE,
    UPSERT
  }
h3_hmap_action;

typedef struct entry
  {
    void *key;
    void *data;
  }
h3_hmap_entry;

/* Opaque type for internal use.  */
struct _h3_hmap_entry;

/* Data type for reentrant functions.  */
typedef struct
  {
    struct _h3_hmap_entry *table;
    unsigned int size;
    unsigned int filled;
    unsigned int keylen;
  } h3_hmap_data;

h3_hmap_data
h3_hmap_data_i()
{
  h3_hmap_data r={.table=0,.size=0,.filled=0,.keylen=0};
  return r;
}

/* Reentrant versions which can handle multiple hashing tables at the
   same time.  */
extern h3_hmap_entry *h3_hsearch (h3_hmap_entry __item, h3_hmap_action __action, h3_hmap_data *__htab);
extern int h3_hcreate (size_t __nel, unsigned int keylen, h3_hmap_data *__htab);
extern void h3_hdestroy (h3_hmap_data *__htab);


#endif /* h3_hmap.h */
