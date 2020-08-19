#include <iostream>
#include <list>
#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include <random>
using namespace std;

class Person;

class Character {

public:

Person *is_attached_to;

virtual string get_character_type (Person &p);

virtual void attack(Person &p){};

void lower_hp();

void convert(){
}

void setIs_attached_to(Person *p);

virtual ~Character(){};

};

class Person{
private:
	bool is_dead;
	int hitpoints;

public:
	Character *has_character;

	Person(){
		this->hitpoints=100;
		this->is_dead=false;
		has_character=NULL;
	}

void setHas_character(Character *p){
	this->has_character=p;
	}

int getHitpoints(){
	return hitpoints;
}
void setHitpoints(int b){
	hitpoints=b;
}
bool Is_dead(){
	if(hitpoints==0){
		is_dead= true;
	}
	else{
		is_dead= false;}
	return is_dead;
}

void minus_hp(Person &p){
	p.has_character->lower_hp();
}

void hit(Person *p){

	this->has_character->attack(*p);
}
};

void Character::setIs_attached_to(Person* p){
	(this->is_attached_to)=p;
}

string Character::get_character_type(Person &p) {
return typeid(*p.has_character).name();
}

void Character::lower_hp(){
		this->is_attached_to->setHitpoints((is_attached_to->getHitpoints())-10);
		}

class Bad : public Character{
public:


	void lower_hp(){
		is_attached_to->setHitpoints((is_attached_to->getHitpoints())-10);
		}
		string get_character_type (Person &p){
			return typeid(*p.has_character).name();
		}

	void attack(Person &p){

		int a;
		a=is_attached_to->getHitpoints();

		if(a>0){
		p.minus_hp(p);}

	}

};

class Zombie;

class Good : public Character{

public:



	void lower_hp(){
	is_attached_to->setHitpoints((is_attached_to->getHitpoints())-10);
	}
	string get_character_type (Person &p){
		return typeid(*p.has_character).name();
	}

void attack(Person &p){
	string a;
	int x;
	int b;

			b=this->is_attached_to->getHitpoints();

			if(b>0){
		a=get_character_type(p);
		if(a=="6Zombie"){

			x = rand() % 100;
			if(x<20){
				if(x<8){
				convert(1,p);}
				else {
					convert(2,p);}
			}

			else{
				p.minus_hp(p);
			}
		}
		else{
			p.minus_hp(p);
		}
	}

}
void convert(int k, Person &p){
 		int g;
		g=p.getHitpoints();
		Character *c=new Character;
		if (k==1) {
			delete p.has_character;
			c=new Good;
			p.has_character=c;
			c->setIs_attached_to(&p);
			p.setHitpoints(g);

   			 }
	    else if (k==2) {
	    	c=new Bad;
	    	delete p.has_character;
	    	p.has_character= c;
	    	c->setIs_attached_to(&p);
	    	p.setHitpoints(g);

    		 }
    	}

};


class Zombie : public Character{
public:


	void lower_hp(){
		is_attached_to->setHitpoints((is_attached_to->getHitpoints())-10);

		}
		string get_character_type (Person &p){
			return (typeid(*(p.has_character)).name());
		}

	void attack(Person &p){
			int x;
			x = rand() % 100;

			int a;
					a=this->is_attached_to->getHitpoints();

					if(a>0){
			if(x<10){
				convert(3,&p);
				}
			else{
				p.minus_hp(p);
			}
		}

	}
	void convert(int k,Person *p){
		int g;
		g=p->getHitpoints();
		if (k==1) {
			delete p->has_character;
		   	 p->has_character= new Good;
		   	p->setHitpoints(g);
	 			 }
		 else if (k==2) {
			delete p->has_character;
			 p->has_character= new Bad;
			 p->setHitpoints(g);
		   		 }
		 else if (k==3) {
			 Character *c=new Character;
			 c=new Zombie;
			delete p->has_character;
		  	p->has_character= c;
		  	c->setIs_attached_to(p);
		  	p->setHitpoints(g);
		   		 }

	}
};

class World{
private:
int number;
list<Person*> first;
	void create(){
		int x;
		list<Person*> first;
		for (int i = 0; i < number; i++){

			x = (rand() % 3)+1;

		Person* ObjectPerson=new Person;
		Character* c = new Character;
		if (x==1){
		c=new Good;

		}
		else if(x==2){
		 c=new Bad;

		}
		else if(x==3){
		c=new Zombie;

		 }
		ObjectPerson->setHas_character(c);
		c->setIs_attached_to(ObjectPerson);
		c->is_attached_to->setHitpoints(100);
		first.push_front(ObjectPerson);
	}
		std::list<Person*>::iterator j;
				int b,r=0;
				b=0;
				Print(first);

				int telos=0;
				std::list<Person*>::iterator it2;
				std::list<Person*>::iterator it;

				while((b<100)&&(telos==0)){
					telos=1;

					it2=first.end();
					it=first.begin();
					j=it++;

				while(it != it2){

					string sp;
					string sp1;
					int ab;

					ab=((*j)->getHitpoints());
					if(ab!=0){
					sp=((*it)->has_character->get_character_type(*(*it)));
					sp1=((*(j))->has_character->get_character_type(*(*j)));

					if((sp)!=(sp1)){
					 (*(j))->hit((*it));

					 telos=0;
					}}

						j++;
						it++;
				}
				b=b+1;
				it2=first.end();
				it=first.begin();
				it2--;
				j=it2;
				string sp;
				string sp1;
				int ab;
				ab=((*j)->getHitpoints());
				if(ab!=0){
				sp=((*it)->has_character->get_character_type(*(*it)));
				sp1=((*(j))->has_character->get_character_type(*(*j)));

				if(j!=it){
				if((sp)!=(sp1)){
 				  (*(j))->hit((*it));
 				  telos=0;
				}}
				}

				for (std::list<Person*>::iterator it3=first.begin(); it3 != first.end(); ++it3){
					int l;
					l=(*it3)->getHitpoints();
					if(l==0){
					delete (*it3)->has_character;
					it3=first.erase((it3));
					it3--;
					}
				}
				if(telos==0){
					Print(first);}
				r=Print1(first);
				if((r==1)||(r==2)||(r==3)){
					telos=1;
				}
				}
				if(r==1){
					cout<<"Goods won the game."<<endl;
				}
				if(r==2){
					cout<<"Bads won the game."<<endl;
				}
				if(r==3){
					cout<<"Zombies won the game."<<endl;
				}
				if(r==4){
					cout<<"Draw,Nobody won."<<endl;
			}

	}






public:

void setNumber(int a){
	number=a;
	create();
}

void Print(list<Person*> &first){
	int g;

	for (std::list<Person*>::iterator it=first.begin(); it != first.end(); ++it){
		string sp1;
		int k;
				k=((*it)->getHitpoints());

		sp1=((*it)->has_character->get_character_type(*(*it)));
		if((sp1)=="4Good"){
			g=1;
		}
		if((sp1)=="3Bad"){
			g=2;
			}
		if((sp1)=="6Zombie"){
			g=3;
			}

		if(g==1){
		cout<<"Good"<<"-"<<k<<" ";
		}
		if(g==2){
			cout<<"Bad"<<"-"<<k<<" ";
		}
		if(g==3){
			cout<<"Zombie"<<"-"<<k<<" ";
		}
	}
	cout<<endl;

}

int Print1(list<Person*> &first){
	int g;
	int m1,m2,m3;
			m1=0;
			m2=0;
			m3=0;
	for (std::list<Person*>::iterator it=first.begin(); it != first.end(); ++it){
		string sp1;
		int a;
		a=(*it)->getHitpoints();
		if(a>0){
		sp1=((*it)->has_character->get_character_type(*(*it)));
		if((sp1)=="4Good"){
					g=1;
				}
		if((sp1)=="3Bad"){
					g=2;
					}
		if((sp1)=="6Zombie"){
					g=3;
					}
		if(g==1){
		m1=m1+1;
	    }
		if(g==2){
		m2=m2+1;
		}
		if(g==3){
		m3=m3+1;
		}
	}
	}
	int kl;
if((m2==0)&&(m3==0)) {
	kl= 1;
}
else if((m3==0)&&(m1==0)){
	kl= 2;
}
else if((m1==0)&&(m2==0)){
	kl= 3;
}
else{
	kl= 4;
}
return kl;
}


};

int main(void){
	int seed=time(NULL);
	srand(seed);
		int number;
	cout<<"Enter Number"<<endl;
cin>>number;
World *WorldObject=new World();
WorldObject->setNumber(number);
delete WorldObject;
return 0;
}

