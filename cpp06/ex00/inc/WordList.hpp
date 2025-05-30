#ifndef CPP06__EX00_WordList_H_
#define CPP06__EX00_WordList_H_

#include "Word.hpp"
#include <cstddef>

class WordList {
public:
  WordList(void);
  ~WordList(void);

  static WordList *createWordList(std::string);
  std::size_t size(void) const;
  Word *getWords(void);
  void append(Word *word);

private:
  WordList(const WordList &other);
  WordList &operator=(const WordList &other);

  std::size_t size_;
  Word *words_;
};

#endif
