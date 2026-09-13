/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:35:09 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 17:55:42 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : name("Default form"),
      isSigned(false),
      gradeToSign(75),
      gradeToExecute(50) {
}

Form::Form(const std::string& initName, const int initGradeToSign,
           const int initGradeToExecute)
    : name(initName),
      isSigned(false),
      gradeToSign(initGradeToSign),
      gradeToExecute(initGradeToExecute) {
  gradeCheck(initGradeToSign);
  gradeCheck(initGradeToExecute);
}

Form::Form(const Form& src)
    : name(src.name),
      isSigned(src.isSigned),
      gradeToSign(src.gradeToSign),
      gradeToExecute(src.gradeToExecute) {
}

Form& Form::operator=(const Form& src) {
  if (this != &src) {
    this->isSigned = src.isSigned;
  }
  return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
  return this->name;
}

bool Form::getIsSigned() const {
  return this->isSigned;
}

int Form::getGradeToSign() const {
  return this->gradeToSign;
}

int Form::getGradeToExecute() const {
  return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (this->isSigned == true) {
    throw(FormAlreadySignedException());
  }
  if (bureaucrat.getGrade() <= this->gradeToSign) {
    this->isSigned = true;
    return;
  } else {
    throw(GradeTooLowException());
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high!!";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low!!";
}

const char* Form::FormAlreadySignedException::what() const throw() {
  return "Form is already signed!!";
}

void Form::gradeCheck(int grade) {
  if (grade > 150) {
    throw(GradeTooLowException());
  }
  if (grade < 1) {
    throw(GradeTooHighException());
  }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form " << form.getName()
     << (form.getIsSigned() ? " is signed. " : " is not signed. ") << "Grade "
     << form.getGradeToSign() << " required for sign and "
     << form.getGradeToExecute() << " required for execute.";
  return os;
}