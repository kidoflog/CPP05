/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/09/12 20:05:39 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>

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
