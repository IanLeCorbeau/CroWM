#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define YYPREFIX "yy"
#line 23 "parse.y"

#include <sys/types.h>
#include "queue.h"

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calmwm.h"

#define YYSTYPE_IS_DECLARED

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file, *topfile;
struct file	*pushfile(const char *, FILE *);
int		 popfile(void);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...)
    __attribute__((__format__ (printf, 1, 2)))
    __attribute__((__nonnull__ (1)));
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 lgetc(int);
int		 lungetc(int);
int		 findeol(void);

static struct conf	*conf;

typedef struct {
	union {
		int64_t			 number;
		char			*string;
	} v;
	int lineno;
} YYSTYPE;

#line 62 "y.tab.c"
#define BINDKEY 257
#define UNBINDKEY 258
#define BINDMOUSE 259
#define UNBINDMOUSE 260
#define FONTNAME 261
#define STICKY 262
#define GAP 263
#define MONOCLE 264
#define AUTOGROUP 265
#define COMMAND 266
#define IGNORE 267
#define WM 268
#define YES 269
#define NO 270
#define BORDERWIDTH 271
#define MOVEAMOUNT 272
#define HTILE 273
#define VTILE 274
#define COLOR 275
#define SNAPDIST 276
#define ACTIVEBORDER 277
#define INACTIVEBORDER 278
#define URGENCYBORDER 279
#define GROUPBORDER 280
#define UNGROUPBORDER 281
#define MENUBG 282
#define MENUFG 283
#define FONTCOLOR 284
#define FONTSELCOLOR 285
#define ERROR 286
#define STRING 287
#define NUMBER 288
#define YYERRCODE 256
const short yylhs[] =
	{                                        -1,
    0,    0,    0,    0,    0,    2,    2,    3,    3,    1,
    1,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    5,
    6,    6,    6,    6,    6,    6,    6,    6,    6,
};
const short yylen[] =
	{                                         2,
    0,    2,    3,    3,    3,    2,    1,    1,    1,    1,
    1,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    3,    3,    5,    2,    5,    3,    2,    3,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,
};
const short yydefred[] =
	{                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    0,    0,    5,    9,    8,    0,   27,    0,   29,
   12,   10,   11,   13,    0,   14,    0,    0,   24,    0,
   15,   18,   16,   17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,   19,    3,    4,    7,    0,    0,
    0,    0,    0,    0,   31,   32,   33,   34,   35,   36,
   37,   38,   39,    6,    0,    0,   25,   23,
};
const short yydgoto[] =
	{                                       1,
   34,   59,   27,   22,   23,   54,
};
const short yysindex[] =
	{                                      0,
  -10,   -1, -282, -282, -282, -282, -276, -262, -266, -262,
 -265, -263, -261, -260, -259, -258, -257, -256, -264, -255,
    0,   15,   18,    0,    0,    0, -253,    0, -253,    0,
    0,    0,    0,    0, -252,    0, -250, -253,    0, -253,
    0,    0,    0,    0, -249, -248, -247, -246, -245, -244,
 -243, -242, -241,    0,    0,    0,    0,    0, -240, -240,
 -239,   -9, -240, -240,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -238, -236,    0,    0,};
const short yyrindex[] =
	{                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,   42,
    0,   43,   44,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,};
const short yygindex[] =
	{                                      0,
   46,  -28,   -2,    0,    0,    0,
};
#define YYTABLESIZE 266
const short yytable[] =
	{                                      21,
   60,   28,   29,   30,   25,   26,   32,   33,   24,   63,
   31,   64,   45,   46,   47,   48,   49,   50,   51,   52,
   53,   35,   37,   38,   56,   39,   40,   57,   41,   42,
   43,   44,   55,   58,   76,   61,   62,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   26,   75,   77,
   78,   28,   22,   20,   21,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,    0,    0,
   15,   16,   17,   18,   19,   20,
};
const short yycheck[] =
	{                                      10,
   29,    4,    5,    6,  287,  288,  269,  270,   10,   38,
  287,   40,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  288,  288,  287,   10,  287,  287,   10,  288,  288,
  288,  288,  288,  287,   44,  288,  287,  287,  287,  287,
  287,  287,  287,  287,  287,  287,  287,   10,  288,  288,
  287,   10,   10,   10,   10,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,   -1,   -1,
  271,  272,  273,  274,  275,  276,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#if YYDEBUG
const char * const yyname[] =
	{
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BINDKEY","UNBINDKEY",
"BINDMOUSE","UNBINDMOUSE","FONTNAME","STICKY","GAP","MONOCLE","AUTOGROUP",
"COMMAND","IGNORE","WM","YES","NO","BORDERWIDTH","MOVEAMOUNT","HTILE","VTILE",
"COLOR","SNAPDIST","ACTIVEBORDER","INACTIVEBORDER","URGENCYBORDER",
"GROUPBORDER","UNGROUPBORDER","MENUBG","MENUFG","FONTCOLOR","FONTSELCOLOR",
"ERROR","STRING","NUMBER",
};
const char * const yyrule[] =
	{"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar main '\\n'",
"grammar : grammar color '\\n'",
"grammar : grammar error '\\n'",
"string : string STRING",
"string : STRING",
"numberstring : NUMBER",
"numberstring : STRING",
"yesno : YES",
"yesno : NO",
"main : FONTNAME STRING",
"main : STICKY yesno",
"main : MONOCLE yesno",
"main : BORDERWIDTH NUMBER",
"main : HTILE NUMBER",
"main : VTILE NUMBER",
"main : MOVEAMOUNT NUMBER",
"main : SNAPDIST NUMBER",
"main : COMMAND STRING string",
"main : WM STRING string",
"main : AUTOGROUP NUMBER STRING",
"main : AUTOGROUP NUMBER STRING ',' STRING",
"main : IGNORE STRING",
"main : GAP NUMBER NUMBER NUMBER NUMBER",
"main : BINDKEY numberstring string",
"main : UNBINDKEY numberstring",
"main : BINDMOUSE numberstring string",
"main : UNBINDMOUSE numberstring",
"color : COLOR colors",
"colors : ACTIVEBORDER STRING",
"colors : INACTIVEBORDER STRING",
"colors : URGENCYBORDER STRING",
"colors : GROUPBORDER STRING",
"colors : UNGROUPBORDER STRING",
"colors : MENUBG STRING",
"colors : MENUFG STRING",
"colors : FONTCOLOR STRING",
"colors : FONTSELCOLOR STRING",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
unsigned int yystacksize;
int yyparse(void);
#line 307 "parse.y"

struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;

	file->errors++;
	va_start(ap, fmt);
	fprintf(stderr, "%s:%d: ", file->name, yylval.lineno);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "activeborder",	ACTIVEBORDER},
		{ "autogroup",		AUTOGROUP},
		{ "bind-key",		BINDKEY},
		{ "bind-mouse",		BINDMOUSE},
		{ "borderwidth",	BORDERWIDTH},
		{ "color",		COLOR},
		{ "command",		COMMAND},
		{ "font",		FONTCOLOR},
		{ "fontname",		FONTNAME},
		{ "gap",		GAP},
		{ "groupborder",	GROUPBORDER},
		{ "htile",		HTILE},
		{ "ignore",		IGNORE},
		{ "inactiveborder",	INACTIVEBORDER},
		{ "menubg",		MENUBG},
		{ "menufg",		MENUFG},
		{ "monocle",		MONOCLE},
		{ "moveamount",		MOVEAMOUNT},
		{ "no",			NO},
		{ "selfont", 		FONTSELCOLOR},
		{ "snapdist",		SNAPDIST},
		{ "sticky",		STICKY},
		{ "unbind-key",		UNBINDKEY},
		{ "unbind-mouse",	UNBINDMOUSE},
		{ "ungroupborder",	UNGROUPBORDER},
		{ "urgencyborder",	URGENCYBORDER},
		{ "vtile",		VTILE},
		{ "wm",			WM},
		{ "yes",		YES}
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define MAXPUSHBACK	128

char	*parsebuf;
int	 parseindex;
char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = (unsigned char)parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return ((unsigned char)pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (file == topfile || popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index + 1 >= MAXPUSHBACK)
		return (EOF);
	pushback_buffer[pushback_index++] = c;
	return (c);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;

	/* skip to either EOF or the first real EOL */
	while (1) {
		if (pushback_index)
			c = (unsigned char)pushback_buffer[--pushback_index];
		else
			c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	char	 buf[8096];
	char	*p;
	int	 quotec, next, c;
	int	 token;

	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || next == ' ' ||
				    next == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			} else if (c == '\0') {
				yyerror("syntax error");
				return (findeol());
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = (char)c;
		}
		yylval.v.string = xstrdup(buf);
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc((unsigned char)*--p);
			c = (unsigned char)*--p;
			if (c == '-')
				return (c);
		}
	}

/* Similar to other parse.y copies, but also allows '/' in strings */
#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '#' && x != ','))

	if (isalnum(c) || c == ':' || c == '_' || c == '*' || c == '/') {
		do {
			*p++ = c;
			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			yylval.v.string = xstrdup(buf);
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

struct file *
pushfile(const char *name, FILE *stream)
{
	struct file	*nfile;

	nfile = xcalloc(1, sizeof(struct file));
	nfile->name = xstrdup(name);
	nfile->stream = stream;
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

int
parse_config(const char *filename, struct conf *xconf)
{
	FILE		*stream;
	int		 errors = 0;

	conf = xconf;

	stream = fopen(filename, "r");
	if (stream == NULL) {
		if (errno == ENOENT)
			return (0);
		warn("%s", filename);
		return (-1);
	}
	file = pushfile(filename, stream);
	topfile = file;

	yyparse();
	errors = file->errors;
	popfile();

	return (errors ? -1 : 0);
}
#line 632 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    unsigned int newsize;
    long sslen;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    sslen = yyssp - yyss;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    newss = (short *)realloc(yyss, newsize * sizeof *newss);
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + sslen;
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newvs)
        goto bail;
    newvs = (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs);
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + sslen;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 93 "parse.y"
{ file->errors++; }
break;
case 6:
#line 96 "parse.y"
{
			if (asprintf(&yyval.v.string, "%s %s", yyvsp[-1].v.string, yyvsp[0].v.string) == -1) {
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				yyerror("string: asprintf");
				YYERROR;
			}
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 8:
#line 109 "parse.y"
{
			char	*s;
			if (asprintf(&s, "%lld", yyvsp[0].v.number) == -1) {
				yyerror("string: asprintf");
				YYERROR;
			}
			yyval.v.string = s;
		}
break;
case 10:
#line 120 "parse.y"
{ yyval.v.number = 1; }
break;
case 11:
#line 121 "parse.y"
{ yyval.v.number = 0; }
break;
case 12:
#line 124 "parse.y"
{
			free(conf->font);
			conf->font = yyvsp[0].v.string;
		}
break;
case 13:
#line 128 "parse.y"
{
			conf->stickygroups = yyvsp[0].v.number;
		}
break;
case 14:
#line 131 "parse.y"
{
			conf->monocle = yyvsp[0].v.number;
		}
break;
case 15:
#line 134 "parse.y"
{
			if (yyvsp[0].v.number < 0 || yyvsp[0].v.number > INT_MAX) {
				yyerror("invalid borderwidth");
				YYERROR;
			}
			conf->bwidth = yyvsp[0].v.number;
		}
break;
case 16:
#line 141 "parse.y"
{
			if (yyvsp[0].v.number < 0 || yyvsp[0].v.number > 99) {
				yyerror("invalid htile percent");
				YYERROR;
			}
			conf->htile = yyvsp[0].v.number;
		}
break;
case 17:
#line 148 "parse.y"
{
			if (yyvsp[0].v.number < 0 || yyvsp[0].v.number > 99) {
				yyerror("invalid vtile percent");
				YYERROR;
			}
			conf->vtile = yyvsp[0].v.number;
		}
break;
case 18:
#line 155 "parse.y"
{
			if (yyvsp[0].v.number < 0 || yyvsp[0].v.number > INT_MAX) {
				yyerror("invalid movemount");
				YYERROR;
			}
			conf->mamount = yyvsp[0].v.number;
		}
break;
case 19:
#line 162 "parse.y"
{
			if (yyvsp[0].v.number < 0 || yyvsp[0].v.number > INT_MAX) {
				yyerror("invalid snapdist");
				YYERROR;
			}
			conf->snapdist = yyvsp[0].v.number;
		}
break;
case 20:
#line 169 "parse.y"
{
			if (strlen(yyvsp[0].v.string) >= PATH_MAX) {
				yyerror("%s command path too long", yyvsp[-1].v.string);
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			conf_cmd_add(conf, yyvsp[-1].v.string, yyvsp[0].v.string);
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 21:
#line 180 "parse.y"
{
			if (strlen(yyvsp[0].v.string) >= PATH_MAX) {
				yyerror("%s wm path too long", yyvsp[-1].v.string);
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			conf_wm_add(conf, yyvsp[-1].v.string, yyvsp[0].v.string);
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 22:
#line 191 "parse.y"
{
			if (yyvsp[-1].v.number < 0 || yyvsp[-1].v.number > 9) {
				yyerror("invalid autogroup");
				free(yyvsp[0].v.string);
				YYERROR;
			}
			conf_autogroup(conf, yyvsp[-1].v.number, NULL, yyvsp[0].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 23:
#line 200 "parse.y"
{
			if (yyvsp[-3].v.number < 0 || yyvsp[-3].v.number > 9) {
				yyerror("invalid autogroup");
				free(yyvsp[-2].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			conf_autogroup(conf, yyvsp[-3].v.number, yyvsp[-2].v.string, yyvsp[0].v.string);
			free(yyvsp[-2].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 24:
#line 211 "parse.y"
{
			conf_ignore(conf, yyvsp[0].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 25:
#line 215 "parse.y"
{
			if (yyvsp[-3].v.number < 0 || yyvsp[-3].v.number > INT_MAX ||
			    yyvsp[-2].v.number < 0 || yyvsp[-2].v.number > INT_MAX ||
			    yyvsp[-1].v.number < 0 || yyvsp[-1].v.number > INT_MAX ||
			    yyvsp[0].v.number < 0 || yyvsp[0].v.number > INT_MAX) {
				yyerror("invalid gap");
				YYERROR;
			}
			conf->gap.top = yyvsp[-3].v.number;
			conf->gap.bottom = yyvsp[-2].v.number;
			conf->gap.left = yyvsp[-1].v.number;
			conf->gap.right = yyvsp[0].v.number;
		}
break;
case 26:
#line 228 "parse.y"
{
			if (!conf_bind_key(conf, yyvsp[-1].v.string, yyvsp[0].v.string)) {
				yyerror("invalid bind-key: %s %s", yyvsp[-1].v.string, yyvsp[0].v.string);
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 27:
#line 238 "parse.y"
{
			if (!conf_bind_key(conf, yyvsp[0].v.string, NULL)) {
				yyerror("invalid unbind-key: %s", yyvsp[0].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			free(yyvsp[0].v.string);
		}
break;
case 28:
#line 246 "parse.y"
{
			if (!conf_bind_mouse(conf, yyvsp[-1].v.string, yyvsp[0].v.string)) {
				yyerror("invalid bind-mouse: %s %s", yyvsp[-1].v.string, yyvsp[0].v.string);
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 29:
#line 256 "parse.y"
{
			if (!conf_bind_mouse(conf, yyvsp[0].v.string, NULL)) {
				yyerror("invalid unbind-mouse: %s", yyvsp[0].v.string);
				free(yyvsp[0].v.string);
				YYERROR;
			}
			free(yyvsp[0].v.string);
		}
break;
case 31:
#line 269 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_ACTIVE]);
			conf->color[CWM_COLOR_BORDER_ACTIVE] = yyvsp[0].v.string;
		}
break;
case 32:
#line 273 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_INACTIVE]);
			conf->color[CWM_COLOR_BORDER_INACTIVE] = yyvsp[0].v.string;
		}
break;
case 33:
#line 277 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_URGENCY]);
			conf->color[CWM_COLOR_BORDER_URGENCY] = yyvsp[0].v.string;
		}
break;
case 34:
#line 281 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_GROUP]);
			conf->color[CWM_COLOR_BORDER_GROUP] = yyvsp[0].v.string;
		}
break;
case 35:
#line 285 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_UNGROUP]);
			conf->color[CWM_COLOR_BORDER_UNGROUP] = yyvsp[0].v.string;
		}
break;
case 36:
#line 289 "parse.y"
{
			free(conf->color[CWM_COLOR_MENU_BG]);
			conf->color[CWM_COLOR_MENU_BG] = yyvsp[0].v.string;
		}
break;
case 37:
#line 293 "parse.y"
{
			free(conf->color[CWM_COLOR_MENU_FG]);
			conf->color[CWM_COLOR_MENU_FG] = yyvsp[0].v.string;
		}
break;
case 38:
#line 297 "parse.y"
{
			free(conf->color[CWM_COLOR_MENU_FONT]);
			conf->color[CWM_COLOR_MENU_FONT] = yyvsp[0].v.string;
		}
break;
case 39:
#line 301 "parse.y"
{
			free(conf->color[CWM_COLOR_MENU_FONT_SEL]);
			conf->color[CWM_COLOR_MENU_FONT_SEL] = yyvsp[0].v.string;
		}
break;
#line 1117 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
