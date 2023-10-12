#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a;
	ClapTrap b("Second");
	ClapTrap c;
	ClapTrap d("Fourth");

	c = b;

	a.attack("Second");
	b.takeDamage(4);
	b.beRepaired(6);
	d.attack("lol");

	for (int i = 0; i < 10; i++) {
		a.attack("Something");
	}

	a.beRepaired(5);

	c.takeDamage(10);
	c.attack("Fourth");
	c.beRepaired(3);

	return 0;
}
