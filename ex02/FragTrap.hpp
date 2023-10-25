#ifndef FragTrap_H
#define FragTrap_H
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);

		FragTrap& operator=(const FragTrap& src);

		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys( void );

	protected:
		std::string  name;
		unsigned int hit_points    = 100;
		unsigned int energy_points = 100;
		unsigned int attack_damage = 30;

	private:
		void propagateStats( void );
};

#endif
