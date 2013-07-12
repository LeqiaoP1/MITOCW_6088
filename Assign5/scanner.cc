// Implementation of the class scanner

#include "scanner.h"
#include <iostream>

Symbol::Symbol(SymTypeEnum type, float val)
  : type(type), val(val)
{}

const std::string Symbol::GetTypeString()
{
  std::string ret;
  switch (type)
    {
    case PAR_OPEN:
      ret = "PAR_OPEN";
      break;

    case PAR_CLOSE:
      ret = "PAR_CLOSE";
      break;

    case NUM:
      ret = "NUM";
      break;

    case OP_MINUS:
      ret = "OP_MINUS";
      break;

    case OP_PLUS:
      ret = "OP_PLUS";
      break;

    case OP_MULT :
      ret = "OP_MULT";
      break;

    case OP_DIV :
      ret = "OP_DIV";
    break;

    default:
      ret = "INVALID";
      break;
    }

  return ret;
}


Scanner::Scanner()
  :currPos(0)
{}

Scanner::~Scanner()
{
}

bool Scanner::SetInputString(const std::string &inputStr)
{
  unsigned int index = 0;
  std::size_t sz = 0;
  float fval = 0.0;


  Clear();

  // loop over each char for recongizing meaningful symbols (setup its type and value)
  for (index = 0; index < inputStr.length(); index++)
    {
      switch (inputStr[index])
	{
	case '(':
	  inputSyms.push_back(Symbol(PAR_OPEN));
	  break;
	  
	case ')':
	  inputSyms.push_back(Symbol(PAR_CLOSE));
	  break;

	case '-':
	  inputSyms.push_back(Symbol(OP_MINUS));
	  break;

	case '+':
	  inputSyms.push_back(Symbol(OP_PLUS));
	  break;

	case '*':
	  inputSyms.push_back(Symbol(OP_MULT));
	  break;

	case '/':
	  inputSyms.push_back(Symbol(OP_DIV));
	  break;

	case ' ':
	  // do nothing for space
	  break;

	  // identify the first digit in float numeric
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
	 
	  fval = std::stof(inputStr.substr(index), &sz);
	  inputSyms.push_back( Symbol(NUM, fval) );
	  index += (sz-1); // here "-1" to compensate the effect of "index++";
	  break;

	default:
	  std::cout << "unrecognized char at pos " << index << " of input string.\n";
	  return false;
	}
    }

  return true;
}

void Scanner::Clear()
{
  currPos = 0;
  inputSyms.clear();
}

void Scanner::Reset()
{
  currPos = 0;
}


const Symbol& Scanner::GetCurrSymbol()
{
  return inputSyms.at(currPos);
}

bool Scanner::MoveToNextSymbol()
{
  // if already at the end of vector
  if ((currPos+1) < inputSyms.size())
    {
      currPos += 1;
      return true;
    }
  else
    return false;
}

