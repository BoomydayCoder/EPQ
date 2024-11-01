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
    Ast *exptr;
    
};

%code {
    #include "driver.hh"
}

%token        END      0 
%token        ASSIGN    
%token        PRINT     

%token <ival> NUMBER     
%token <sval> ID         
%token        INPUT      
%type  <exptr> exp
%type  <exptr> stmt 
%type  <exptr> sequence
%type <exptr> block




%printer {debug_stream() << $$;} <ival>


%right ASSIGN;
%token '@';
%right '?' ':';
%left '|';
%left '&';
%right '!';
%left '=' GT LT GE LE NE;
%left '+' '-';
%left '*' '/';
%right UMINUS;

%start program;

%%

program: sequence END {drv.result = $1;}


sequence: {$$ = new Ast(SEQ);} 
| sequence stmt {$$ = $1; $1->add(move($2));}

block: '{' sequence '}' {$$ = new Ast(BLK, {move($2)});}

stmt: ';' {$$ = new Ast(SEQ);}
    | exp ';' {$$ = new Ast(EXP, {move($1)});}
    | PRINT exp ';' {$$ = new Ast(PRINT, {move($2)});}
    | block {$$ = $1;}
    | exp '?' stmt ':' stmt {$$ = new Ast(IF, {move($1), move($3), move($5)});}
    | exp '?' stmt {$$ = new Ast(IF, {move($1), move($3), new Ast(SEQ)});}
    | exp '@' stmt {$$ = new Ast(WHL, {move($1), move($3)});}
    
    

exp: ID ASSIGN exp {$$ = new Ast(SET, {new Ast(ID, $1), move($3)}); delete $1;}
    | exp '+' exp   { $$ = new Ast(ADD, {move($1), move($3)}); }
    | exp '-' exp   { $$ = new Ast(SUB, {move($1), move($3)}); }
    | exp '*' exp   { $$ = new Ast(MUL, {move($1), move($3)}); }
    | exp '/' exp   { $$ = new Ast(DIV, {move($1), move($3)}); }
    | exp '=' exp   { $$ = new Ast(EQ, {move($1), move($3)}); }
    | exp GT exp    { $$ = new Ast(GT, {move($1), move($3)}); }
    | exp LT exp    { $$ = new Ast(LT, {move($1), move($3)}); }
    | exp GE exp    { $$ = new Ast(GE, {move($1), move($3)}); }
    | exp LE exp    { $$ = new Ast(LE, {move($1), move($3)}); }
    | exp NE exp    { $$ = new Ast(NE, {move($1), move($3)}); }
    | exp '|' exp   { $$ = new Ast(OR, {move($1), move($3)}); }
    | exp '&' exp   { $$ = new Ast(AND, {move($1), move($3)}); }
    | '!' exp       { $$ = new Ast(NOT, {move($2)}); }
    | '-' exp %prec UMINUS { $$ = new Ast(NEG, {move($2)}); }
    | '(' exp ')'   { $$ = $2; }
    | NUMBER      { $$ = new Ast(INT, $1);}
    | ID { $$ = new Ast(ID, $1); delete $1;}
    | INPUT {$$ = new Ast(INP);}

%%

void yy::parser::error (const yy::parser::location_type& l, const string& m)
{
    drv.error(l, m);
}