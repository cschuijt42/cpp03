#include "FragTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

FragTrap::FragTrap() {
	this->setFragTrapStats();
	std::cout << "FragTrap default constructor called: " << this->getName() << std::endl;
}

FragTrap::FragTrap(const std::string& name) {
	this->setName(name);
	this->setFragTrapStats();
	std::cout << "FragTrap named constructor called: " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap copy constructor called: " << this->getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	this->setName(src.getName());
	this->setAttackDamage(src.getAttackDamage());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setHitPoints(src.getHitPoints());
	std::cout << "FragTrap copy assignment operator called: " << this->getName() << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << this->getName() << std::endl;
}

// Class member functions

void FragTrap::attack(const std::string& target) {
	if (this->getEnergyPoints() <= 0) {
		std::cout << "FragTrap " << this->getName() <<
				" is out of energy and cannot attack." << std::endl;
		return;
	}
	else if (this->getHitPoints() <= 0) {
		std::cout << "FragTrap " << this->getName() <<
				" is dead and cannot attack." << std::endl;
		return;
	}

	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << "FragTrap "          << this->getName() <<
				 " attacks "          << target <<
				 ", causing "         << this->getAttackDamage() <<
				 " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->getName() <<
				 " wants to high five, guys (m/f/x)!" << std::endl;
}

void FragTrap::setFragTrapStats( void ) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
