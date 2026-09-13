/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:13:41 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat() : name("anonymous"), grade(75) {
}

Bureaucrat::Bureaucrat(const std::string& initName, const int initGrade)
    : name(initName), grade(initGrade) {
  gradeCheck(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.name), grade(src.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
    this->grade = src.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
  return this->name;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

void Bureaucrat::incrementGrade() {
  gradeCheck(grade - 1);
  grade--;
}

void Bureaucrat::decrementGrade() {
  gradeCheck(grade + 1);
  grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!!";
}

void Bureaucrat::gradeCheck(int grade) {
  if (grade > 150) {
    throw(GradeTooLowException());
  }
  if (grade < 1) {
    throw(GradeTooHighException());
  }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
  } catch (const AForm::FormAlreadySignedException& e) {
    std::cout << e.what() << std::endl;
    return;
  } catch (const AForm::GradeTooLowException& e) {
    std::cout << "Bureaucrat " << this->name
              << "'s grade is too low for sign to Form \"" << form.getName()
              << "\"." << std::endl;
    return;
  }
  std::cout << "Bureaucrat " << this->name << " signed Form \""
            << form.getName() << "\"." << std::endl;
}

void Bureaucrat::executeForm(const AForm& form) const {
  try {
    form.execute(*this);
  } catch (const AForm::FormIsNotSignedException& e) {
    std::cout << e.what() << std::endl;
    return;
  } catch (const AForm::GradeTooLowException& e) {
    std::cout << "Bureaucrat " << this->name
              << "'s grade is too low for execute Form \"" << form.getName()
              << "\"." << std::endl;
    return;
  } catch (const ShrubberyCreationForm::FileCanNotOpenException& e) {
    std::cerr << e.what() << std::endl;
    return;
  }
  std::cout << "Bureaucrat " << this->name << " executed Form \""
            << form.getName() << "\"." << std::endl;
}
