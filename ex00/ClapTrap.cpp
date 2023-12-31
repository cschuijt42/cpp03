#include "ClapTrap.hpp"
#include <iostream>

// Constructors, operators and destructors

ClapTrap::ClapTrap() {
	name = "Anonymous";
	std::cout << "ClapTrap default constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) {
	this->name = name;
	std::cout << "ClapTrap named constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	*this = src;
	std::cout << "ClapTrap copy constructor called: " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	this->name          = src.name;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points    = src.hit_points;
	std::cout << "ClapTrap copy assignment operator called: " << this->name << std::endl;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called: " << this->name << std::endl;
}

// Getters

const std::string& ClapTrap::getName( void ) const {
	return this->name;
}

unsigned int ClapTrap::getHitPoints( void ) const {
	return this->hit_points;
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
	return this->energy_points;
}

unsigned int ClapTrap::getAttackDamage( void ) const {
	return this->attack_damage;
}

// Setters

void ClapTrap::setName(const std::string& name) {
	this->name = name;
}

void ClapTrap::setHitPoints(const unsigned int& amount) {
	this->hit_points = amount;
}

void ClapTrap::setEnergyPoints(const unsigned int& amount) {
	this->energy_points = amount;
}

void ClapTrap::setAttackDamage(const unsigned int& amount) {
	this->attack_damage = amount;
}

// Class methods

void ClapTrap::attack(const std::string& target) {
	if (!this->canAct("ClapTrap", "attack"))
		return;

	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << "ClapTrap "          << this->name <<
				 " attacks "          << target <<
				 ", causing "         << this->getAttackDamage() <<
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
	if (!this->canAct("ClapTrap", "repair"))
		return;

	this->energy_points--;
	this->hit_points += amount;

	std::cout << "ClapTrap "                 << this->name <<
				 " has repaired itself for " << amount <<
				 " hit points, it now has "  << this->hit_points <<
				 " hit points." << std::endl;
}

void ClapTrap::printStats( void ) const {
	std::cout << "Stats for:    : " << this->getName()         << '\n' <<
	             "Hit points    : " << this->getHitPoints()    << '\n' <<
				 "Energy points : " << this->getEnergyPoints() << '\n' <<
				 "Attack damage : " << this->getAttackDamage() << std::endl;
}

bool ClapTrap::canAct(const std::string& type, const std::string& action) const {
	if (this->getEnergyPoints() == 0) {
		std::cout << type << " " << this->getName() <<
				" is out of energy and cannot " << action << "." << std::endl;
		return false;
	}
	else if (this->getHitPoints() == 0) {
		std::cout << type << " " << this->getName() <<
				" is dead and cannot " << action << "." << std::endl;
		return false;
	}
	return true;
}
