/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:35:09 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 20:35:51 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default form"),
      isSigned(false),
      gradeToSign(75),
      gradeToExecute(50) {
}

AForm::AForm(const std::string& initName, const int initGradeToSign,
             const int initGradeToExecute)
    : name(initName),
      isSigned(false),
      gradeToSign(initGradeToSign),
      gradeToExecute(initGradeToExecute) {
  gradeCheck(initGradeToSign);
  gradeCheck(initGradeToExecute);
}

AForm::AForm(const AForm& src)
    : name(src.name),
      isSigned(src.isSigned),
      gradeToSign(src.gradeToSign),
      gradeToExecute(src.gradeToExecute) {
}

AForm& AForm::operator=(const AForm& src) {
  if (this != &src) {
    this->isSigned = src.isSigned;
  }
  return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
  return this->name;
}

bool AForm::getIsSigned() const {
  return this->isSigned;
}

int AForm::getGradeToSign() const {
  return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
  return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
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

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!!";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!!";
}

const char* AForm::FormAlreadySignedException::what() const throw() {
  return "Form is already signed!!";
}

const char* AForm::FormIsNotSignedException::what() const throw() {
  return "Form is not signed!!";
}

void AForm::gradeCheck(int grade) {
  if (grade > 150) {
    throw(GradeTooLowException());
  }
  if (grade < 1) {
    throw(GradeTooHighException());
  }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form " << form.getName()
     << (form.getIsSigned() ? " is signed. " : " is not signed. ") << "Grade "
     << form.getGradeToSign() << " required for sign and "
     << form.getGradeToExecute() << " required for execute.";
  return os;
}

void AForm::execute(const Bureaucrat& executor) const {
  if (this->isSigned == false) {
    throw(FormIsNotSignedException());
  }
  if (executor.getGrade() > this->gradeToExecute) {
    throw(GradeTooLowException());
  }
  executeAction();
}