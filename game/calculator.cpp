#include "../std_lib_facilities_4.h"
#include <sstream>
#include "calculator.h"
#include "../fltk/Simple_window.h"
#include "../fltk/Graph.h"


void Token_stream::setString(string s){
	ss.str(s);
	full = false;
}

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}


Token Token_stream::get()
{	
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    ss >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            ss.putback(ch);         // put digit back into the input stream
            double val;
            ss >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}


 Token_stream ts;       // provides get() and putback() 


   // declaration so that primary() can call expression()

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
		ts.putback(t);
		if(t.kind=='+'||t.kind=='-'){	// if unary + or - is present, place a zero behind it.
			return 0;
		}
		else{
			error("expected primary");
		}
    }
}


// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream      ts.get

    while(true) {
        switch (t.kind) {
		case '(':
			//left*=primary();				//error if parentheses are not preceded by operator, or placed first.
			//t = ts.get();
			error("( not expected");
			break;
        case '*':
            left *= primary();
            t = ts.get();
			break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}


// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double calculator(string a)
{
	
	double val=0;
	string b = a + "=";	// add equal to end of formula input
	ts.setString(b);
	try{
    val = expression();	// run calculator remade to work with strings.
	}catch (exception& e) {
		return 0;	// if error, score is 0.
	}
	return val;
}

