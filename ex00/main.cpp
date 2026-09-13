/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 17:29:02 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  std::cout << "=== default constructor test ===" << std::endl;
  Bureaucrat Alice("Alice", 90);
  std::cout << Alice << std::endl;
  try {
    Bureaucrat Bob("Bob", 0);
  } catch (const Bureaucrat::GradeTooHighException&) {
    std::cout << "catch GradeTooHighException." << std::endl;
  }
  try {
    Bureaucrat Bob("Bob", 0);
  } catch (const std::exception& e) {
    std::cout << "catch std::exception& e." << std::endl;
  }
  try {
    Bureaucrat Bob("Bob", 151);
  } catch (const Bureaucrat::GradeTooLowException&) {
    std::cout << "catch GradeTooLowException." << std::endl;
  }
  try {
    Bureaucrat Bob("Bob", 151);
  } catch (const std::exception& e) {
    std::cout << "catch std::exception& e." << std::endl;
  }
  Bureaucrat Top("Top", 1);
  Bureaucrat Bottom("Bottom", 150);
  std::cout << "=== standard increment decrement test ===" << std::endl;
  std::cout << Alice << std::endl;
  std::cout << "=== incrementGrade() ===" << std::endl;
  Alice.incrementGrade();
  std::cout << Alice << std::endl;
  std::cout << "=== decrementGrade() ===" << std::endl;
  Alice.decrementGrade();
  std::cout << Alice << std::endl;
  std::cout << "=== too high grade test ===" << std::endl;
  std::cout << Top << std::endl;
  std::cout << "=== incrementGrade() ===" << std::endl;
  try {
    Top.incrementGrade();
  } catch (const Bureaucrat::GradeTooHighException&) {
    std::cout << "catch GradeTooHighException." << std::endl;
  }
  std::cout << Top << std::endl;
  std::cout << "=== too low grade test ===" << std::endl;
  std::cout << Bottom << std::endl;
  std::cout << "=== decrementGrade() ===" << std::endl;
  try {
    Bottom.decrementGrade();
  } catch (const Bureaucrat::GradeTooLowException&) {
    std::cout << "catch GradeTooLowException." << std::endl;
  }
  std::cout << Bottom << std::endl;
  return 0;
}
