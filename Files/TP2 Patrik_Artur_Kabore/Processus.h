#ifndef PROCESSUS_H
#define	PROCESSUS_H
#include <string>

class Processus{
	private:
		std::string id;
		int temps;
		
	public:
		Processus(const std::string &_id="",int _temps=1):id(_id), temps(_temps < 1 ? 1:_temps){}//un processus ne peut pas exister sans temps d'executions
		
		//surcharges
		friend std::ostream& operator<<(std::ostream&, const Processus&);
		
		//setters
		const void setIdentite(const std::string &newId){id=newId;};
		const void setTemps(int newTemps){temps=newTemps;};
		
		//getters
		const std::string &getIdentite()const{return id;};
		const int getTemps()const{return temps;};
		
};
#endif // PROCESSUS_H
