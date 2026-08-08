/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:01:27 by kkido             #+#    #+#             */
/*   Updated: 2026/08/08 17:34:45 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>

Bureaucrat::Bureaucrat() : grade(75), name("anonymous") {
}

Bureaucrat::Bureaucrat(const int init_grade, const std::string& init_name)
    : grade(init_grade), name(init_name) {
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : grade(src.grade), name(src.name) {
}