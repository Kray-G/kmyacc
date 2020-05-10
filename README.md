# kmyacc

## Special Thanks

Tribute to the late Mr. MORI Koichiro.
Many thanks for providing a great parser generator compatible with yacc.

Please see the original README file.

* [README](README)
* [README.moriyoshi](README.moriyoshi)

The following is the document converted to Markdown of the original [README](README) file with a little modifications.

* Modifications:
  * Modified for Markdown document style.
  * Added the instruction to build on Windows.

---

# kmyacc version 4.1.4 (2006/02/15)

kmyacc is an LALR(1) parser generator, hopefully compatible with AT&T yacc.

## Features

- Generates smaller table than Yacc/Berkeley yacc/Bison.
- Supports multi-language (currenly C and Java).


## Install

### Linux

1. You must have ANSI C compiler.
2. Read Makefile and change macro BIN and PARLIB appropriately.
3. Type

        make
        make install

### Windows

1. You must have Visual C compiler.
2. Type

        nmake -f Makefile.msc

## How To Use

### Command for C

    kmyacc foo.y

generates parser code "y.tab.c", same as original yacc.

### Command for Java

    kmyacc Foo.jy

creates parser code "Foo.java", its class name is "Foo".

## Synopsys

    kmyacc [ -dvltani ] [ -b X ] [ -p XX ] [ -m MODEL ] [ -L LANG ] grammar

## Options

|   Option   |                                                                                                                Meaning                                                                                                                 |
| ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `-d`       | Makes definition file named y.tab.h, which contains definitions of token values and the type of semantic stack. (C language only)                                                                                                      |
| `-v`       | Generates file y.output which contains human-readable parser tables and diagnostics.                                                                                                                                                   |
| `-l`       | Does not insert #line control directives in y.tab.c.                                                                                                                                                                                   |
| `-t`       | Generates debugging code.  Compiling with -DYYDEBUG option gives the same effect.                                                                                                                                                      |
| `-a`       | Makes semantic actions individual functions rather than blocks in one switch statement.  This option is useful if your compiler can not compile big functions/methods.                                                                 |
| `-b X`     | Uses X rather than y as the prefix of generated filenames. X.tab.c for C, X.java for Java.                                                                                                                                             |
| `-p XX`    | Uses XX rather than yy as the prefix of global identifiers in the parser.  You can avoid collision of external symbols when you use more than one parser in the same program by specifing this option. (C language only)               |
| `-m MODEL` | Uses file MODEL as prototype of parser code. When defaulted, file /usr/local/lib/kmyacc.LANG.parser is taken, where LANG is a host language name deduced from source file extension(.y/.jy), or one specified by -L switch explicitly. |
| `-L LANG`  | Specifies LANG as host programming language. c,java,javascript,perl are available.                                                                                                                                                     |
| `-n`       | Allows referencing semantic values by name.                                                                                                                                                                                            |
| `-i`       | Inhibits referencing semantic values by $$, $1, $2 form.                                                                                                                                                                               |

## Environment

|    Name     |                 Meaning                 |
| ----------- | --------------------------------------- |
| `KMYACCPAR` | Prototype file name. Same as -m option. |


## Differences between kmyacc and AT&T yacc

-  Options `-b`, `-p`, `-a`, `-m`, `-L` added
-  Bison's `%expect`, `%pure_parser` statement added
-  Treat `//` as comment
-  Following obsolete features deleted
	- literal tokens surrounded by `"`
	- `\left`, `\right` etc.
	- `%<`, `%>`, `%binary`, `%2`, `%0`, `%=`
-  `YYBACKUP` macro not supported


## Copyright

```
Copyright (C) 1987,1989,1992,1993,2005,2006  MORI Koichiro.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
```


## Contact

Bug reports, suggestions, patches are welcome.
Please send email to:

    MORI Koichiro <kmori@acm.org>  

