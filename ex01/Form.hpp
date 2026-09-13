/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:35:12 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 17:48:57 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 public:
  Form();
  Form(const std::string& initName, const int initGradeToSign,
       const int initGradeToExecute);
  Form(const Form& src);
  Form& operator=(const Form& src);
  ~Form();
  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat& bureaucrat);
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class FormAlreadySignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  void gradeCheck(int grade);
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
