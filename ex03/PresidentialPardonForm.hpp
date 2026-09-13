/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:33:55 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 19:50:29 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string& initTarget);
  PresidentialPardonForm(const PresidentialPardonForm& src);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
  ~PresidentialPardonForm();
  void executeAction() const;

 private:
  const std::string target;
};

#endif