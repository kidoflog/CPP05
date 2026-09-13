/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:34:04 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:02:00 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("anonymous") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& initTarget)
    : AForm("ShrubberyCreationForm", 145, 137), target(initTarget) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), target(src.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

const char* ShrubberyCreationForm::FileCanNotOpenException::what() const
    throw() {
  return "Error: Failed to open file.";
}

void ShrubberyCreationForm::executeAction() const {
  std::ofstream ofs((target + "_shrubbery").c_str());
  if (!ofs) {
    throw(FileCanNotOpenException());
  }
  ofs << "                         *\n"
         "                        /|\\\n"
         "                       /*|*\\\n"
         "                      /***|***\\\n"
         "                     /****|****\\\n"
         "                    /*****|*****\\\n"
         "                   /******|******\\\n"
         "                  /*******|*******\\\n"
         "                 /********|********\\\n"
         "                /*********|*********\\\n"
         "               /**********|**********\\\n"
         "              /***********|***********\\\n"
         "             /************|************\\\n"
         "            /*************|*************\\\n"
         "           /**************|**************\\\n"
         "          /***************|***************\\\n"
         "                 |||||||||||\n"
         "                 |||||||||||\n"
         "                 |||||||||||"
      << std::endl;
}
