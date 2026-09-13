/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:33:57 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 20:54:01 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("anonymous") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& initTarget)
    : AForm("RobotomyRequestForm", 72, 45), target(initTarget) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), target(src.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::executeAction() const {
  std::cout << "* drilling noises *\nVrrrrrrrr...\nBrrrrrrrrrr..." << std::endl;
  if (std::rand() % 2 == 1) {
    std::cout << this->target
              << " has been robotomized successfully 50% of the time."
              << std::endl;
  } else {
    std::cout << "The robotomy failed." << std::endl;
  }
}