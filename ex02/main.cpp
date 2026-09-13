/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:17:38 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void testShrubberyCreationForm() {
  std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;

  ShrubberyCreationForm form("test_home");
  Bureaucrat signerTooLow("signer-too-low", 146);
  Bureaucrat signer("signer", 145);
  Bureaucrat executorTooLow("executor-too-low", 138);
  Bureaucrat executor("executor", 137);

  executor.executeForm(form);
  signerTooLow.signForm(form);
  signer.signForm(form);
  executorTooLow.executeForm(form);
  executor.executeForm(form);
}

static void testRobotomyRequestForm() {
  std::cout << "\n=== RobotomyRequestForm ===" << std::endl;

  RobotomyRequestForm form("Bender");
  AForm& polymorphicForm = form;
  Bureaucrat signer("signer", 72);
  Bureaucrat executorTooLow("executor-too-low", 46);
  Bureaucrat executor("executor", 45);

  signer.signForm(polymorphicForm);
  executorTooLow.executeForm(polymorphicForm);
  for (int i = 0; i < 4; ++i) {
    executor.executeForm(polymorphicForm);
  }
}

static void testPresidentialPardonForm() {
  std::cout << "\n=== PresidentialPardonForm ===" << std::endl;

  PresidentialPardonForm form("Arthur Dent");
  Bureaucrat topBureaucrat("top-bureaucrat", 1);
  Bureaucrat signerTooLow("signer-too-low", 26);
  Bureaucrat signer("signer", 25);
  Bureaucrat executorTooLow("executor-too-low", 6);
  Bureaucrat executor("executor", 5);

  topBureaucrat.executeForm(form);
  signerTooLow.signForm(form);
  signer.signForm(form);
  executorTooLow.executeForm(form);
  executor.executeForm(form);
}

int main() {
  testShrubberyCreationForm();
  testRobotomyRequestForm();
  testPresidentialPardonForm();

  return 0;
}
