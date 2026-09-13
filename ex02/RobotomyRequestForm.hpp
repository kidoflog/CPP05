/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:34:01 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 19:51:32 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string& initTarget);
  RobotomyRequestForm(const RobotomyRequestForm& src);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
  ~RobotomyRequestForm();
  void executeAction() const;

 private:
  const std::string target;
};
#endif