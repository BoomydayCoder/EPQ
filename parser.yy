%skeleton "lalr1.cc" // -*- C++ -*-
%require "2.4.1"
%defines
%define parser_class_name "parser"

%code requires {
    #include <string>
    #include <memory>
    using namespace std;
    #include "exptree.hh"
    class driver;
}

%parse-param {driver& drv}
%lex-param {driver& drv}

%locations
%initial-action {
    @$.begin.filename = @$.end.filename = &drv.file;
};

%debug
%error-verbose

%union {
    int ival;
    string *sval;
    ExpTree *exptr;
    
};

%code {
    #include "driver.hh"
}

%token        END      0 "end of file"
%token        ASSIGN     ":="
%token        PRINT      "print"

%token <ival> NUMBER     "number"
%token <sval> ID        "identifier"
%type  <exptr> exp
%type  <exptr> stmt 
%type  <exptr> sequence




%printer {debug_stream() << $$;} <ival>

%right ASSIGN;
%left '+' '-';
%left '*' '/';
%right UMINUS;

%start program;

%%

program: sequence END {drv.result = $1;}


sequence: {$$ = new ExpTree(SEQ);} 
| sequence stmt {$$ = $1; $1->add(move($2));}

stmt: exp ';' {$$ = new ExpTree(EXP, {move($1)});}
    | PRINT exp ';' {$$ = new ExpTree(PRINT, {move($2)});}

exp: ID ASSIGN exp {$$ = new ExpTree(SET, {new ExpTree(ID, $1), move($3)}); delete $1;}
    | exp '+' exp   { $$ = new ExpTree(ADD, {move($1), move($3)}); }
    | exp '-' exp   { $$ = new ExpTree(SUB, {move($1), move($3)}); }
    | exp '*' exp   { $$ = new ExpTree(MUL, {move($1), move($3)}); }
    | exp '/' exp   { $$ = new ExpTree(DIV, {move($1), move($3)}); }
    | '-' exp %prec UMINUS { $$ = new ExpTree(NEG, {move($2)}); }
    | '(' exp ')'   { $$ = $2; }
    | "number"      { $$ = new ExpTree(INT, $1);}
    | "identifier" { $$ = new ExpTree(ID, $1); delete $1;}

%%

void yy::parser::error (const yy::parser::location_type& l, const string& m)
{
    drv.error(l, m);
}