#include "ScavTrap.hpp"
#include <iostream>

// Constructors, destructors and assignment operators

ScavTrap::ScavTrap() : ClapTrap() {
	this->name = this->getName();
	this->propagateStats();
	std::cout << "ScavTrap default constructor called: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	this->propagateStats();
	std::cout << "ScavTrap named constructor called: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap copy constructor called: " << this->name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	this->name          = src.getName();
	this->attack_damage = src.getAttackDamage();
	this->energy_points = src.getEnergyPoints();
	this->hit_points    = src.getHitPoints();
	this->propagateStats();
	std::cout << "ScavTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called: " << this->name << std::endl;
}

// Class member functions

void ScavTrap::attack(const std::string& target) {
	if (!this->canAct("ScavTrap", "attack"))
		return;

	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << "ScavTrap "          << this->getName() <<
				 " attacks "          << target <<
				 ", causing "         << this->getAttackDamage() <<
				 " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void ) {
	if (!this->canAct("ScavTrap", "enter Gate Keeper mode"))
		return;

	std::cout << "ScavTrap "                << this->name <<
				 " is in Gate Keeper mode." << std::endl;
}

void ScavTrap::propagateStats( void ) {
	this->setName(this->name);
	this->setHitPoints(this->hit_points);
	this->setEnergyPoints(this->energy_points);
	this->setAttackDamage(this->attack_damage);
}
