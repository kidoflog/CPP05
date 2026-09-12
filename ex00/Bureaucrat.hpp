/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:32 by kkido             #+#    #+#             */
/*   Updated: 2026/09/12 18:01:24 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const int init_grade, const std::string& init_name);
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

 private:
  void gradeCheck(int grade);
  int grade;
  const std::string name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif
