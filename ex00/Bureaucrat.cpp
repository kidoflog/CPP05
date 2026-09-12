/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/09/12 18:05:51 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>

Bureaucrat::Bureaucrat() : grade(75), name("anonymous") {
}

Bureaucrat::Bureaucrat(const int init_grade, const std::string& init_name)
    : grade(init_grade), name(init_name) {
  gradeCheck(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : grade(src.grade), name(src.name) {
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
  os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade()
     << ".";
  return os;
}