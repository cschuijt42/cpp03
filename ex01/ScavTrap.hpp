#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);

		ScavTrap& operator=(const ScavTrap& src);

		~ScavTrap();

		void guardGate( void );

	private:
		void setScavTrapStats( void );
};

#endif
