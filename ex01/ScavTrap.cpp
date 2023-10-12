#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	std::cout << "Default constructor called: " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	this->setName(name);
	std::cout << "Named constructor called: " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) {
	*this = src;
	std::cout << "Copy constructor called: " << this->getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	this->setName(src.getName());
	this->setAttackDamage(src.getAttackDamage());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setHitPoints(src.getHitPoints());
	std::cout << "Copy assignment operator called: " << this->getName() << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called: " << this->getName() << std::endl;
}

void ScavTrap::guardGate( void ) {
	std::cout << this->getName() << " is in gate guarding mode." << std::endl;
}
