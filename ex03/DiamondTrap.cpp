#include "DiamondTrap.hpp"
#include <iostream>

// Constructors

DiamondTrap::DiamondTrap() :
ClapTrap(), ScavTrap(), FragTrap() {
	this->name = "Anonymous";
	// Default constructor
	this->inheritStats();
	this->propagateStats();
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->inheritStats();
	this->propagateStats();
	std::cout << "DiamondTrap named constructor called: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) :
ClapTrap(src), ScavTrap(src), FragTrap(src) {
	// Copy constructor
	*this = src;
	std::cout << "DiamondTrap copy constructor called: " << this->name << std::endl;
}

// Operators

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
	// Copy assignment operator
	this->name          = src.name;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points    = src.hit_points;
	this->propagateStats();
	std::cout << "DiamondTrap copy assignment operator called: " << this->name << std::endl;
	return *this;
}

// Destructors

DiamondTrap::~DiamondTrap() {
	// Destructor
	std::cout << "DiamondTrap destructor called: " << this->name << std::endl;
}

// Class methods

void DiamondTrap::inheritStats( void ) {
	ClapTrap::setName(this->name + "_clap_name");
	this->hit_points    = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) {
	std::cout << "My DiamondTrap name is "   << this->name      <<
			     " and my ClapTrap name is " << this->getName() << std::endl;
}

void DiamondTrap::propagateStats( void ) {
	this->setHitPoints(this->hit_points);
	this->setEnergyPoints(this->energy_points);
	this->setAttackDamage(this->attack_damage);
}
