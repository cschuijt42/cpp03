#include <string>

class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);

		ClapTrap& operator=(const ClapTrap& src);

		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	 name;
		unsigned int hit_points    = 10;
		unsigned int energy_points = 10;
		unsigned int attack_damage = 10;
};
