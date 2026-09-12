/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/12 19:26:06 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  std::cout << "--- default constructer test ---" << std::endl;
  Bureaucrat Alice(90, "Alice");
  std::cout << Alice << std::endl;
  try {
    Bureaucrat Bob(0, "Bob");
  } catch (const Bureaucrat::GradeTooHighException&) {
    std::cout << "catch GradeTooHighException." << std::endl;
  }
  try {
    Bureaucrat Bob(0, "Bob");
  } catch (const std::exception& e) {
    std::cout << "catch std::exception& e." << std::endl;
  }
  try {
    Bureaucrat Bob(151, "Bob");
  } catch (const Bureaucrat::GradeTooLowException&) {
    std::cout << "catch GradeLowHighException." << std::endl;
  }
  try {
    Bureaucrat Bob(151, "Bob");
  } catch (const std::exception& e) {
    std::cout << "catch std::exception& e." << std::endl;
  }
  Bureaucrat Top(1, "Top");
  Bureaucrat Bottom(150, "Bottom");
  std::cout << "--- standard increment decrement test ---" << std::endl;
  std::cout << Alice << std::endl;
  std::cout << "--- incrementGrade() ---" << std::endl;
  Alice.incrementGrade();
  std::cout << Alice << std::endl;
  std::cout << "--- decrementGrade() ---" << std::endl;
  Alice.decrementGrade();
  std::cout << Alice << std::endl;
  std::cout << "--- too high grade test ---" << std::endl;
  std::cout << Top << std::endl;
  std::cout << "--- incrementGrade() ---" << std::endl;
  try {
    Top.incrementGrade();
  } catch (const Bureaucrat::GradeTooHighException&) {
    std::cout << "catch GradeTooHighException." << std::endl;
  }
  std::cout << Top << std::endl;
  std::cout << "--- too low grade test ---" << std::endl;
  std::cout << Bottom << std::endl;
  std::cout << "--- decrementGrade() ---" << std::endl;
  try {
    Bottom.decrementGrade();
  } catch (const Bureaucrat::GradeTooLowException&) {
    std::cout << "catch GradeTooLowException." << std::endl;
  }
  std::cout << Bottom << std::endl;
  return 0;
}
