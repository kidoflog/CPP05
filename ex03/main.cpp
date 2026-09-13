/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:46:54 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void testFormCreation(Intern& intern, const std::string& formName,
                             const std::string& target,
                             Bureaucrat& bureaucrat) {
  AForm* form = intern.makeForm(formName, target);
  if (form == NULL) {
    std::cout << "Form creation failed unexpectedly." << std::endl;
    return;
  }

  std::cout << "Form info: " << *form << std::endl;
  bureaucrat.signForm(*form);
  bureaucrat.executeForm(*form);
  delete form;
}

static void testUnknownForm(Intern& intern) {
  AForm* form = intern.makeForm("unknown form", "Nobody");
  if (form == NULL) {
    std::cout << "Unknown form correctly returned NULL." << std::endl;
  } else {
    std::cout << "Unknown form unexpectedly created a form." << std::endl;
    delete form;
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  Intern intern;
  Bureaucrat bureaucrat("boss", 1);

  std::cout << "\n=== Intern creates forms ===" << std::endl;
  testFormCreation(intern, "shrubbery creation", "intern_test_home",
                   bureaucrat);
  testFormCreation(intern, "robotomy request", "Bender", bureaucrat);
  testFormCreation(intern, "presidential pardon", "Arthur Dent", bureaucrat);

  std::cout << "\n=== Unknown form ===" << std::endl;
  testUnknownForm(intern);

  return 0;
}
