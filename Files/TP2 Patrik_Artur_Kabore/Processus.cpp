#include "Processus.h"
#include <iostream>

std::ostream& operator<<(std::ostream& flux, const Processus& p) {
	return flux <<p.id<<"("<<p.temps<<")";
} 
