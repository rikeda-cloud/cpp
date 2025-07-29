#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

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
  std::string ascii_tree = "     *      \n"
                           "    /.\\    \n"
                           "   /o..\\   \n"
                           "   /..o\\   \n"
                           "  /.o..o\\  \n"
                           "  /...o.\\  \n"
                           " /..o....\\ \n"
                           " ^^^[_]^^^ \n";
  std::string file_name = std::string(target_) + std::string("_shrubbery");
  std::ofstream s(file_name.c_str());

  try {
    s << ascii_tree << std::endl;
    s.close();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
