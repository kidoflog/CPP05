/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:33:52 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 20:40:36 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("anonymous") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& initTarget)
    : AForm("PresidentialPardonForm", 25, 5), target(initTarget) {
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : AForm(src), target(src.target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::executeAction() const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}