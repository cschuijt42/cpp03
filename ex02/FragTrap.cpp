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
	this->name          = src.getName();
	this->attack_damage = src.getAttackDamage();
	this->energy_points = src.getEnergyPoints();
	this->hit_points    = src.getHitPoints();
	this->propagateStats();
	std::cout << "FragTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << this->name << std::endl;
}

// Class member functions

void FragTrap::attack(const std::string& target) {
	if (!this->canAct("FragTrap", "attack"))
		return;

	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << "FragTrap "          << this->getName() <<
				 " attacks "          << target <<
				 ", causing "         << this->getAttackDamage() <<
				 " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void ) {
	if (!this->canAct("FragTrap", "high five"))
		return;

	std::cout << "FragTrap " << this->getName() <<
				 " wants to high five, guys (m/f/x)!" << std::endl;
}

void FragTrap::propagateStats( void ) {
	this->setName(this->name);
	this->setHitPoints(this->hit_points);
	this->setEnergyPoints(this->energy_points);
	this->setAttackDamage(this->attack_damage);
}
