// Generated by Bisonc++ V4.04.01 on Mon, 18 Nov 2013 22:35:41 -0800

#ifndef parserParser_h_included
#define parserParser_h_included

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "scanner.h"

// Include header to support the 'not' operator used in parse.cc
#ifdef _WIN32
# include <iso646.h>
#endif

// $insert namespace-open
namespace Marsyas
{

#undef Parser
class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;
    node d_actor;
    node d_directives;
    std::ostream d_dummy_out;

    public:
        Parser( std::istream & stream ):
          d_dummy_out(nullptr)
        {
          d_scanner.switchStreams(stream, d_dummy_out);
        }

        int parse();

        const node &actor()
        {
          return d_actor;
        }

        const node &directives()
        {
          return d_directives;
        }

    private:
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};

// $insert namespace-close
}

#endif
