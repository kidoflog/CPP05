/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:34:06 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 20:59:50 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
  ~ShrubberyCreationForm();
  void executeAction() const;
  class FileCanNotOpenException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  const std::string target;
};
#endif