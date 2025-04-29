#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", ShrubberyCreationForm::REQUIRED_GRADE_SIGN,
            ShrubberyCreationForm::REQUIRED_GRADE_EXEC),
      target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : AForm(form), target_(form.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
  if (this != &form) {
    AForm::operator=(form);
    const_cast<std::string &>(this->target_) = form.target_;
  }
  return *this;
}

void ShrubberyCreationForm::action(void) const {
  std::ofstream s;
  s.open(target_ + std::string("_shrubbery"));
  if (s.fail()) {
    throw FileException();
  }
  std::string ascii_tree = "     *      \n"
                           "    /.\\    \n"
                           "   /o..\\   \n"
                           "   /..o\\   \n"
                           "  /.o..o\\  \n"
                           "  /...o.\\  \n"
                           " /..o....\\ \n"
                           " ^^^[_]^^^ \n";

  s << ascii_tree << std::endl;
  if (s.is_open()) {
    s.close();
    if (s.fail())
      throw FileException();
  }
}

const char *ShrubberyCreationForm::FileException::what(void) const throw() {
  return "Error in file operation!";
}
