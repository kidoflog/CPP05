/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 17:02:05 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  std::cout << "=== default Form test ===" << std::endl;
  Form defaultForm;
  std::cout << defaultForm << std::endl;

  std::cout << "=== valid Form test ===" << std::endl;
  Form validForm("valid form", 50, 25);
  std::cout << validForm << std::endl;

  std::cout << "=== invalid sign grade test ===" << std::endl;
  try {
    Form invalidForm("invalid sign grade", 0, 25);
  } catch (const Form::GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=== sign grade too low test ===" << std::endl;
  try {
    Form invalidForm("sign grade too low", 151, 25);
  } catch (const Form::GradeTooLowException& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=== invalid execute grade test ===" << std::endl;
  try {
    Form invalidForm("invalid execute grade", 50, 151);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=== execute grade too high test ===" << std::endl;
  try {
    Form invalidForm("execute grade too high", 50, 0);
  } catch (const Form::GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=== successful sign test ===" << std::endl;
  Bureaucrat highRank("high rank", 40);
  highRank.signForm(validForm);
  std::cout << validForm << std::endl;

  std::cout << "=== already signed Form test ===" << std::endl;
  highRank.signForm(validForm);

  std::cout << "=== failed sign test ===" << std::endl;
  Form unsignedForm("unsigned form", 50, 25);
  Bureaucrat lowRank("low rank", 60);
  lowRank.signForm(unsignedForm);
  std::cout << unsignedForm << std::endl;

  std::cout << "=== copy constructor test ===" << std::endl;
  Form copiedForm(validForm);
  std::cout << copiedForm << std::endl;

  std::cout << "=== copy assignment test ===" << std::endl;
  Form assignedForm("assigned form", 100, 100);
  assignedForm = validForm;
  std::cout << assignedForm << std::endl;

  return 0;
}
