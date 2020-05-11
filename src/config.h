/*
 * Configuration for kmyacc
 *
 * Copyright (C) 1993, 2005  MORI Koichiro
 */

#ifndef HAS_STDLIB
# define HAS_STDLIB 1
#endif /* HAS_STDLIB */

#ifndef PARSERBASE
#if defined(_WIN32) || defined(_WIN64)
# define PARSERBASE "kmyacc"
#else
# define PARSERBASE "/usr/local/lib/kmyacc"
#endif /* _WIN32 | _WIN64 */
#endif /* PARSERBASE */

#define MAXTERM 512		/* Maximum number of terminals */
#define MAXNONT 512		/* Maximum number of nonterminals */
#define MAXPROD 2000		/* Maximum number of productions */
