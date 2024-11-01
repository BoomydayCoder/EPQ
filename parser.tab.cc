
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 41 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 50 "parser.tab.cc"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
#line 32 "parser.yy"

    #include "driver.hh"



/* Line 318 of lalr1.cc  */
#line 61 "parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 130 "parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 5: /* "NUMBER" */

/* Line 449 of lalr1.cc  */
#line 51 "parser.yy"
	{debug_stream() << (yyvaluep->ival);};

/* Line 449 of lalr1.cc  */
#line 207 "parser.tab.cc"
	break;
       default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 18 "parser.yy"
{
    yylloc.begin.filename = yylloc.end.filename = &drv.file;
}

/* Line 553 of lalr1.cc  */
#line 322 "parser.tab.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, drv);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 69 "parser.yy"
    {drv.result = (yysemantic_stack_[(2) - (1)].exptr);}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 72 "parser.yy"
    {(yyval.exptr) = new Ast(SEQ);}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 73 "parser.yy"
    {(yyval.exptr) = (yysemantic_stack_[(2) - (1)].exptr); (yysemantic_stack_[(2) - (1)].exptr)->add(move((yysemantic_stack_[(2) - (2)].exptr)));}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 75 "parser.yy"
    {(yyval.exptr) = new Ast(BLK, {move((yysemantic_stack_[(3) - (2)].exptr))});}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 77 "parser.yy"
    {(yyval.exptr) = new Ast(SEQ);}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 78 "parser.yy"
    {(yyval.exptr) = new Ast(EXP, {move((yysemantic_stack_[(2) - (1)].exptr))});}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 79 "parser.yy"
    {(yyval.exptr) = new Ast(PRINT, {move((yysemantic_stack_[(3) - (2)].exptr))});}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 80 "parser.yy"
    {(yyval.exptr) = (yysemantic_stack_[(1) - (1)].exptr);}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 81 "parser.yy"
    {(yyval.exptr) = new Ast(IF, {move((yysemantic_stack_[(7) - (2)].exptr)), move((yysemantic_stack_[(7) - (5)].exptr)), move((yysemantic_stack_[(7) - (7)].exptr))});}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 82 "parser.yy"
    {(yyval.exptr) = new Ast(IF, {move((yysemantic_stack_[(5) - (2)].exptr)), move((yysemantic_stack_[(5) - (5)].exptr)), new Ast(SEQ)});}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 83 "parser.yy"
    {(yyval.exptr) = new Ast(WHL, {move((yysemantic_stack_[(5) - (2)].exptr)), move((yysemantic_stack_[(5) - (5)].exptr))});}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 84 "parser.yy"
    {(yyval.exptr) = new Ast(FOR, {move((yysemantic_stack_[(9) - (2)].exptr)), move((yysemantic_stack_[(9) - (4)].exptr)), move((yysemantic_stack_[(9) - (6)].exptr)), move((yysemantic_stack_[(9) - (9)].exptr))});}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 88 "parser.yy"
    {(yyval.exptr) = new Ast(SET, {new Ast(ID, (yysemantic_stack_[(3) - (1)].sval)), move((yysemantic_stack_[(3) - (3)].exptr))}); delete (yysemantic_stack_[(3) - (1)].sval);}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 89 "parser.yy"
    { (yyval.exptr) = new Ast(ADD, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 90 "parser.yy"
    { (yyval.exptr) = new Ast(SUB, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 91 "parser.yy"
    { (yyval.exptr) = new Ast(MUL, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 92 "parser.yy"
    { (yyval.exptr) = new Ast(DIV, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 93 "parser.yy"
    { (yyval.exptr) = new Ast(EQ, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 94 "parser.yy"
    { (yyval.exptr) = new Ast(GT, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 95 "parser.yy"
    { (yyval.exptr) = new Ast(LT, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 96 "parser.yy"
    { (yyval.exptr) = new Ast(GE, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 97 "parser.yy"
    { (yyval.exptr) = new Ast(LE, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 98 "parser.yy"
    { (yyval.exptr) = new Ast(NE, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 99 "parser.yy"
    { (yyval.exptr) = new Ast(OR, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 100 "parser.yy"
    { (yyval.exptr) = new Ast(AND, {move((yysemantic_stack_[(3) - (1)].exptr)), move((yysemantic_stack_[(3) - (3)].exptr))}); }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 101 "parser.yy"
    { (yyval.exptr) = new Ast(NOT, {move((yysemantic_stack_[(2) - (2)].exptr))}); }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 102 "parser.yy"
    { (yyval.exptr) = new Ast(NEG, {move((yysemantic_stack_[(2) - (2)].exptr))}); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 103 "parser.yy"
    { (yyval.exptr) = (yysemantic_stack_[(3) - (2)].exptr); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 104 "parser.yy"
    { (yyval.exptr) = new Ast(INT, (yysemantic_stack_[(1) - (1)].ival));}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 105 "parser.yy"
    { (yyval.exptr) = new Ast(ID, (yysemantic_stack_[(1) - (1)].sval)); delete (yysemantic_stack_[(1) - (1)].sval);}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 106 "parser.yy"
    {(yyval.exptr) = new Ast(INP);}
    break;



/* Line 678 of lalr1.cc  */
#line 658 "parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -16;
  const short int
  parser::yypact_[] =
  {
       -16,     4,    35,   -16,   -16,    52,   -16,    13,   -16,    52,
      52,   -16,   -16,    74,    52,   -16,   -16,   147,   161,    52,
     197,   -16,    63,   -12,   128,    92,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,   -16,   -16,
     175,   -16,    52,    -6,   -16,   187,   197,    -9,    -9,    -9,
      -9,    -9,    -9,   -15,   -15,   -16,   -16,   111,    74,    74,
      74,   -16,     7,   -10,    74,    12,   -16,    74,   -16
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         3,     0,     0,     1,     2,     0,    30,    31,    32,     0,
       0,     3,     6,     0,     0,     9,     4,     0,     0,     0,
      27,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
      14,     5,     0,     0,    29,    25,    26,    19,    24,    23,
      22,    21,    20,    15,    16,    17,    18,     0,     0,     0,
       0,    12,    11,     0,     0,     0,    10,     0,    13
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -16,   -16,    10,   -16,   -13,    -4
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,     1,     2,    15,    16,    17
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        23,    18,    58,    59,     3,    20,    21,    36,    37,    24,
      25,    34,    35,    36,    37,    40,    19,    64,    42,    65,
      67,    22,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     4,     0,     0,    57,     5,
       6,     7,     8,     0,     0,    61,    62,    63,     9,     0,
       0,    66,     0,     0,    68,     0,    10,     6,     7,     8,
      11,     0,    12,    13,     0,     9,    14,     5,     6,     7,
       8,     0,     0,    10,     0,     0,     9,     0,     5,     6,
       7,     8,     0,    14,    10,     0,     0,     9,    11,    41,
      12,    13,     0,     0,    14,    10,     0,     0,     0,    11,
       0,    12,    13,    26,    27,    14,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     0,     0,     0,
       0,     0,    26,    27,    44,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,    26,
      27,    60,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,    38,     0,    43,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,    26,    27,    38,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    26,    27,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
        13,     5,     8,     9,     0,     9,    10,    22,    23,    13,
      14,    20,    21,    22,    23,    19,     3,    10,    30,    29,
       8,    11,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,     0,    -1,    -1,    42,     4,
       5,     6,     7,    -1,    -1,    58,    59,    60,    13,    -1,
      -1,    64,    -1,    -1,    67,    -1,    21,     5,     6,     7,
      25,    -1,    27,    28,    -1,    13,    31,     4,     5,     6,
       7,    -1,    -1,    21,    -1,    -1,    13,    -1,     4,     5,
       6,     7,    -1,    31,    21,    -1,    -1,    13,    25,    26,
      27,    28,    -1,    -1,    31,    21,    -1,    -1,    -1,    25,
      -1,    27,    28,    11,    12,    31,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    32,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    11,
      12,    30,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    29,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    11,    12,    27,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    11,    12,    27,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    34,    35,     0,     0,     4,     5,     6,     7,    13,
      21,    25,    27,    28,    31,    36,    37,    38,    38,     3,
      38,    38,    35,    37,    38,    38,    11,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    27,    27,
      38,    26,    30,    29,    32,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,     8,     9,
      30,    37,    37,    37,    10,    29,    37,     8,    37
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,    64,    63,
      58,   124,    38,    33,    61,   263,   264,   265,   266,   267,
      43,    45,    42,    47,   268,   123,   125,    59,    91,    93,
      44,    40,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    33,    34,    35,    35,    36,    37,    37,    37,    37,
      37,    37,    37,    37,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     0,     2,     3,     1,     2,     3,     1,
       7,     5,     5,     9,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "END", "error", "$undefined", "ASSIGN", "PRINT", "NUMBER", "ID",
  "INPUT", "'@'", "'?'", "':'", "'|'", "'&'", "'!'", "'='", "NE", "LE",
  "GE", "LT", "GT", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'{'", "'}'",
  "';'", "'['", "']'", "','", "'('", "')'", "$accept", "program",
  "sequence", "block", "stmt", "exp", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        34,     0,    -1,    35,     0,    -1,    -1,    35,    37,    -1,
      25,    35,    26,    -1,    27,    -1,    38,    27,    -1,     4,
      38,    27,    -1,    36,    -1,    28,    38,    29,     9,    37,
      10,    37,    -1,    28,    38,    29,     9,    37,    -1,    28,
      38,    29,     8,    37,    -1,    28,    37,    30,    38,    30,
      37,    29,     8,    37,    -1,     6,     3,    38,    -1,    38,
      20,    38,    -1,    38,    21,    38,    -1,    38,    22,    38,
      -1,    38,    23,    38,    -1,    38,    14,    38,    -1,    38,
      19,    38,    -1,    38,    18,    38,    -1,    38,    17,    38,
      -1,    38,    16,    38,    -1,    38,    15,    38,    -1,    38,
      11,    38,    -1,    38,    12,    38,    -1,    13,    38,    -1,
      21,    38,    -1,    31,    38,    32,    -1,     5,    -1,     6,
      -1,     7,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,     7,    10,    14,    16,    19,    23,
      25,    33,    39,    45,    55,    59,    63,    67,    71,    75,
      79,    83,    87,    91,    95,    99,   103,   107,   110,   113,
     117,   119,   121
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    69,    69,    72,    73,    75,    77,    78,    79,    80,
      81,    82,    83,    84,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    13,     2,     2,     2,     2,    12,     2,
      31,    32,    22,    20,    30,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    10,    27,
       2,    14,     2,     9,     8,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,    11,    26,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,    15,    16,    17,    18,    19,    24
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 220;
  const int parser::yynnts_ = 6;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 3;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 33;

  const unsigned int parser::yyuser_token_number_max_ = 268;
  const parser::token_number_type parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1158 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 108 "parser.yy"


void yy::parser::error (const yy::parser::location_type& l, const string& m)
{
    drv.error(l, m);
}
