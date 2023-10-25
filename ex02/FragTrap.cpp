#include "FragTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

FragTrap::FragTrap() : ClapTrap() {
	this->name = this->getName();
	this->propagateStats();
	std::cout << "FragTrap default constructor called: " << this->name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	this->propagateStats();
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
	this->propagateStats();
	std::cout << "FragTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << this->name << std::endl;
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

void FragTrap::attack(const std::string& target) {
	if (this->getEnergyPoints() <= 0) {
		std::cout << "FragTrap " << this->name <<
				" is out of energy and cannot attack." << std::endl;
		return;
	}
	else if (this->getHitPoints() <= 0) {
		std::cout << "FragTrap " << this->name <<
				" is dead and cannot attack." << std::endl;
		return;
	}

	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << "FragTrap "          << this->name <<
				 " attacks "          << target <<
				 ", causing "         << this->getAttackDamage() <<
				 " points of damage!" << std::endl;
}

void FragTrap::propagateStats( void ) {
	this->setName(this->name);
	this->setHitPoints(this->hit_points);
	this->setEnergyPoints(this->energy_points);
	this->setAttackDamage(this->attack_damage);
}
