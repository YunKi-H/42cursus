#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string	name;
public:
	void			announce() const;
	void			setName(std::string name);
	static Zombie*	zombieHorde(int N, std::string name);
	Zombie(std::string name);
	Zombie();
	~Zombie();
};

#endif
