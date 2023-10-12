#include "ScavTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

ScavTrap::ScavTrap() {
	type = "ScavTrap";
	this->setScavTrapStats();
	std::cout << "ScavTrap default constructor called: " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	this->setName(name);
	this->setScavTrapStats();
	std::cout << "ScavTrap named constructor called: " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap copy constructor called: " << this->getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	this->setName(src.getName());
	this->setAttackDamage(src.getAttackDamage());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setHitPoints(src.getHitPoints());
	std::cout << "ScavTrap copy assignment operator called: " << this->getName() << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called: " << this->getName() << std::endl;
}

// Class member functions

void ScavTrap::guardGate( void ) {
	std::cout << type << " " << this->getName() <<
				 " is in Gate Keeper mode." << std::endl;
}

void ScavTrap::setScavTrapStats( void ) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}
