#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap a;
	ScavTrap b("Second");
	ScavTrap c;
	ScavTrap d("Fourth");

	c = b;

	a.attack("Second");
	b.takeDamage(4);
	b.beRepaired(6);
	d.attack("lol");

	for (int i = 0; i < 10; i++) {
		a.attack("Something");
	}

	a.beRepaired(5);

	// Since ScavTraps have more hitpoints, these will succeed now where they
	// failed for the ClapTraps in ex00.
	c.takeDamage(10);
	c.attack("Fourth");
	c.beRepaired(3);

	// Just to demonstrate dying still works...
	c.takeDamage(9000);
	c.beRepaired(40);
	c.attack("Something");

	d.guardGate();

	return 0;
}
