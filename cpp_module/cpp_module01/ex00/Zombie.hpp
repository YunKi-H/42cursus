#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string	name;
public:
	void			announce() const;
	static Zombie*	newZombie(std::string name);
	static void		randomChump(std::string name);
	Zombie(std::string name);
	Zombie();
	~Zombie();
};

#endif
