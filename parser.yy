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
    ExpTree *exptr;
    
};

%code {
    #include "driver.hh"
}

%token        END      0 "end of file"
%token        ASSIGN     ":="

%token <ival> NUMBER     "number"
%type  <exptr> exp


%printer {debug_stream() << $$;} <ival>

%left '+' '-';
%left '*' '/';
%right UMINUS;

%start to_eval;

%%


to_eval: exp END { drv.result = move($1);};
     
     


exp: exp '+' exp   { $$ = new ExpTree(ADD, {move($1), move($3)}); }
    | exp '-' exp   { $$ = new ExpTree(SUB, {move($1), move($3)}); }
    | exp '*' exp   { $$ = new ExpTree(MUL, {move($1), move($3)}); }
    | exp '/' exp   { $$ = new ExpTree(DIV, {move($1), move($3)}); }
    | '-' exp %prec UMINUS { $$ = new ExpTree(NEG, {move($2)}); }
    | '(' exp ')'   { $$ = $2; }
    | "number"      { $$ = new ExpTree(INT, $1);}

%%

void yy::parser::error (const yy::parser::location_type& l, const string& m)
{
    drv.error(l, m);
}