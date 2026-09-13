/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:22:11 by kkido             #+#    #+#             */
/*   Updated: 2026/09/13 21:26:06 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& src);
  Intern& operator=(const Intern& src);
  ~Intern();
  AForm* makeForm(const std::string& formName, const std::string& target);

 private:
};

#endif
