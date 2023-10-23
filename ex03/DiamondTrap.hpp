#ifndef H_DiamondTrap
#define H_DiamondTrap
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap( void );
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);

		DiamondTrap& operator=(const DiamondTrap& src);

		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI( void );

	protected:
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	private:
		void inherit_values( void );
		std::string	 name;
};

#endif
