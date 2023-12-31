#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <string>

class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);

		ClapTrap& operator=(const ClapTrap& src);

		~ClapTrap();

		const std::string& getName( void ) const;
		const std::string& getType( void ) const;
		unsigned int getHitPoints( void ) const;
		unsigned int getEnergyPoints( void ) const;
		unsigned int getAttackDamage( void ) const;

		void setName(const std::string& name);
		void setHitPoints(const unsigned int& amount);
		void setEnergyPoints(const unsigned int& amount);
		void setAttackDamage(const unsigned int& amount);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void printStats( void ) const;

	protected:
		bool canAct(const std::string& type, const std::string& action) const;

	private:
		std::string	 name;
		unsigned int hit_points    = 10;
		unsigned int energy_points = 10;
		unsigned int attack_damage = 0;
};

#endif
