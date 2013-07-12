// header for the class scanner

#include <string>
#include <vector>

enum SymTypeEnum
  {
    PAR_OPEN = 0,
    PAR_CLOSE,
    NUM,
    OP_MINUS,
    OP_PLUS,
    OP_MULT,
    OP_DIV
  };

class Symbol
{
 public:
  Symbol(SymTypeEnum type, float val=0.0);
  const std::string GetTypeString();
  SymTypeEnum type;
  // meaningful only if the "type" is NUM
  float val; 
};

class Scanner
{
 public:
  Scanner();
  ~Scanner();

  // return false if the setup failed
  bool SetInputString(const std::string &inputStr);

  // clear the state & content of scanner
  void Clear();

  // reset to initial state (content is not deleted)
  void Reset();

  const Symbol& GetCurrSymbol();

  // return false if there is no symbol anymore
  bool MoveToNextSymbol();

 private:
  unsigned int currPos;
  std::vector<Symbol> inputSyms;

};
