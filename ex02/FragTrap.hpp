#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);

		FragTrap& operator=(const FragTrap& src);

		~FragTrap();

		void highFivesGuys( void );

	private:
		void setFragTrapStats( void );
};

#endif
