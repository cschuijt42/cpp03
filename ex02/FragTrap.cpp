#include "FragTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

FragTrap::FragTrap() : ClapTrap() {
	this->name = this->getName();
	std::cout << "FragTrap default constructor called: " << this->name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	std::cout << "FragTrap named constructor called: " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap copy constructor called: " << this->name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	this->name          = src.name;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points    = src.hit_points;
	std::cout << "FragTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << this->name << std::endl;
}

// Class member functions

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->getName() <<
				 " wants to high five, guys (m/f/x)!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->energy_points <= 0) {
		std::cout << "FragTrap " << this->name <<
				" is out of energy and cannot attack." << std::endl;
		return;
	}
	else if (this->hit_points <= 0) {
		std::cout << "FragTrap " << this->name <<
				" is dead and cannot attack." << std::endl;
		return;
	}

	this->energy_points--;

	std::cout << "FragTrap "          << this->name <<
				 " attacks "          << target <<
				 ", causing "         << this->attack_damage <<
				 " points of damage!" << std::endl;
}
