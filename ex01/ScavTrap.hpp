#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);

		ScavTrap& operator=(const ScavTrap& src);

		~ScavTrap();

		void attack(const std::string& target);
		void guardGate( void );

	protected:
		std::string  name;
		unsigned int hit_points    = 100;
		unsigned int energy_points = 50;
		unsigned int attack_damage = 20;

	private:
		void propagateStats( void );
};

#endif
