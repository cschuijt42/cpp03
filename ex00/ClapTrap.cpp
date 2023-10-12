#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	name = "Anonymous";
	std::cout << "Default constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) {
	this->name = name;
	std::cout << "Named constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	*this = src;
	std::cout << "Copy constructor called: " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	this->name          = src.name;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points    = src.hit_points;
	std::cout << "Copy assignment operator called: " << this->name << std::endl;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called: " << this->name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energy_points <= 0) {
		std::cout << "ClapTrap " << this->name <<
					 " is out of energy and cannot attack." << std::endl;
		return;
	}
	else if (this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name <<
					 " is dead and cannot attack." << std::endl;
		return;
	}

	this->energy_points--;

	std::cout << "ClapTrap "          << this->name <<
				 " attacks "          << target <<
				 ", causing "         << this->attack_damage <<
				 " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;

	std::cout << "ClapTrap "                      << this->name <<
				 " has taken "                    << amount <<
				 " points of damage, it now has " << this->hit_points <<
				 " hit points."                   << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points == 0) {
		std::cout << "ClapTrap " << this->name <<
					 " is out of energy and cannot repair." << std::endl;
		return;
	}
	else if (this->hit_points == 0) {
		std::cout << "ClapTrap " << this->name <<
					 " is dead and cannot repair." << std::endl;
		return;
	}

	this->energy_points--;
	this->hit_points += amount;

	std::cout << "ClapTrap "                 << this->name <<
				 " has repaired itself for " << amount <<
				 " hit points."              << std::endl;
}
