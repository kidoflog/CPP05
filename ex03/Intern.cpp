/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:22:19 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:45:02 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& src) {
  (void)src;
}

Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) {
  AForm* form = NULL;
  if (formName == "presidential pardon") {
    form = new PresidentialPardonForm(target);
  }
  if (formName == "robotomy request") {
    form = new RobotomyRequestForm(target);
  }
  if (formName == "shrubbery creation") {
    form = new ShrubberyCreationForm(target);
  }
  if (form) {
    std::cout << "Intern creates " << form->getName() << "." << std::endl;
  } else {
    std::cout << "Intern can't create unknown form." << std::endl;
  }

  return (form);
}