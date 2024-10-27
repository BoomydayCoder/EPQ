#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include <map>
# include "parser.tab.hh"
#include "exptree.hh"
using namespace std;

# define YY_DECL                                        \
       yy::parser::token_type                         \
       yylex (yy::parser::semantic_type* yylval,      \
              yy::parser::location_type* yylloc,      \
              driver& driver)
     // ... and declare it for the parser's sake.
     YY_DECL;

class driver
    {
     public:
       driver ();
       virtual ~driver ();
     
     
       ExpTree* result;

       void scan_begin ();
       void scan_end ();
       bool trace_scanning;

       int parse(const string& f);
       string file;
       bool trace_parsing;

       void error (const yy::location& l, const string& m);
       void error (const string& m);
    };
    #endif // ! DRIVER_HH