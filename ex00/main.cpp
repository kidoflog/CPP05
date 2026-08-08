/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/08/08 15:02:03 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "Polymorphism test:" << std::endl;
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "j (Dog) type: " << j->getType() << std::endl;
    std::cout << "i (Cat) type: " << i->getType() << std::endl;

    std::cout << "i (Cat): ";
    i->makeSound();
    std::cout << "j (Dog): ";
    j->makeSound();
    std::cout << "meta (Animal): ";
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
  }

  std::cout << "Wrong animal test" << std::endl;
  {
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << "wrongMeta (WrongAnimal): ";
    wrongMeta->makeSound();

    std::cout << "wrongCat:  ";
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;
  }

  return 0;
}
