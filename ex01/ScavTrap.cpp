#include "ScavTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

ScavTrap::ScavTrap() : ClapTrap() {
	this->name = this->getName();
	std::cout << "ScavTrap default constructor called: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	std::cout << "ScavTrap named constructor called: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap copy constructor called: " << this->name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	this->name          = src.name;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points    = src.hit_points;
	std::cout << "ScavTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called: " << this->name << std::endl;
}

// Class member functions

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap "                << this->name <<
				 " is in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energy_points <= 0) {
		std::cout << "ScavTrap " << this->name <<
				" is out of energy and cannot attack." << std::endl;
		return;
	}
	else if (this->hit_points <= 0) {
		std::cout << "ScavTrap " << this->name <<
				" is dead and cannot attack." << std::endl;
		return;
	}

	this->energy_points--;

	std::cout << "ScavTrap "          << this->name <<
				 " attacks "          << target <<
				 ", causing "         << this->attack_damage <<
				 " points of damage!" << std::endl;
}
