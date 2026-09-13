/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:35:12 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 20:15:46 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 public:
  AForm();
  AForm(const std::string& initName, const int initGradeToSign,
        const int initGradeToExecute);
  AForm(const AForm& src);
  AForm& operator=(const AForm& src);
  virtual ~AForm();
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
  class FormIsNotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  void execute(const Bureaucrat& executor) const;

 protected:
  virtual void executeAction() const = 0;

 private:
  void gradeCheck(int grade);
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
