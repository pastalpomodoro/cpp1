#ifndef INTERN_HPP
# define INTERN_HPP

#include"AForm.hpp"
class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);
		Intern &operator=(const Intern &copy);
		AForm *makeForm(std::string form, std::string target);
};
#endif