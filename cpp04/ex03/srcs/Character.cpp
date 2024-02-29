#include "Character.hpp"

Character::Character(std::string name) : name_(name) {
	for (int i = 0; i < Character::SLOT_CAPACITY; i++)
		slot_[i] = NULL;
	// std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& character) : name_(character.name_) {
	for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
		if (this->slot_[i] != NULL)
			delete this->slot_[i];
		this->slot_[i] = NULL;
	}
	for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
		if (character.slot_[i] != NULL)
			this->slot_[i] = character.slot_[i]->clone();
	}
	// std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(void) {
	for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
		if (slot_[i] != NULL)
			delete slot_[i];
	}
	// std::cout << "Character destructor called" << std::endl;
}

Character&	Character::operator=(const Character& character) {
	if (this != &character) {
		this->name_ = character.name_;
		for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
			if (this->slot_[i] != NULL)
				delete this->slot_[i];
			this->slot_[i] = NULL;
		}
		for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
			if (character.slot_[i] != NULL)
				this->slot_[i] = character.slot_[i]->clone();
		}
	}
	return *this;
}

std::string const&	Character::getName(void) const {
	return name_;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < Character::SLOT_CAPACITY; i++) {
		if (slot_[i] == NULL) {
			slot_[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 && Character::SLOT_CAPACITY <= idx)
		return ;
	slot_[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 && Character::SLOT_CAPACITY <= idx)
		return ;
	if (slot_[idx] == NULL)
		return ;
	slot_[idx]->use(target);
}
