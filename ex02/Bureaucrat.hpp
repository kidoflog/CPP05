/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:32 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 19:46:24 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string& initName, const int initgrade);
  Bureaucrat(const Bureaucrat& src);
  Bureaucrat& operator=(const Bureaucrat& src);
  ~Bureaucrat();
  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  void signForm(AForm& form);
  void executeForm(const AForm& form) const;

 private:
  void gradeCheck(int grade);
  const std::string name;
  int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
