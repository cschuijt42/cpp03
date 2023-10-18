#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);

		FragTrap& operator=(const FragTrap& src);

		~FragTrap();

		void FragTrap::attack(const std::string& target);
		void highFivesGuys( void );

	private:
		void setFragTrapStats( void );
};

#endif
