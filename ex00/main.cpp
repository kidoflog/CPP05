/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/12 18:24:22 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat Alice = Bureaucrat(90, "Alice");
  Bureaucrat Top = Bureaucrat(1, "Top");
  Bureaucrat Bottom = Bureaucrat(150, "Bottom");
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
  } catch (const Bureaucrat::GradeTooHighException) {
    std::cout << "increment failed." << std::endl;
  }
  std::cout << Top << std::endl;
  std::cout << "--- too low grade test ---" << std::endl;
  std::cout << Bottom << std::endl;
  std::cout << "--- decrementGrade() ---" << std::endl;
  try {
    Bottom.decrementGrade();
  } catch (const Bureaucrat::GradeTooLowException) {
    std::cout << "decrement failed." << std::endl;
  }
  std::cout << Bottom << std::endl;
  return 0;
}
