#ifndef CPP06_EX00_Word_H_
#define CPP06_EX00_Word_H_

#include <string>

enum eWordType {
  MINUS,
  PLUS,
  NUMBER,
  STR,
};

class Word {
public:
  Word(const std::string &);
  ~Word(void);

  eWordType getType(void) const;
  const std::string &getWord(void) const;
  Word *next(void) const;

private:
  Word(void);
  Word(const Word &);
  Word &operator=(const Word &);

  eWordType type_;
  std::string word_;
  Word *next_;
};

#endif
