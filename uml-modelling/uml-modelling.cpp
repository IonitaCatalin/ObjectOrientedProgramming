#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Contact {
public:
	string Name;
	int Type;
protected:
	Contact();
};
class Prieten :public Contact {
public:
	string Adress;
	string Mobile;
	int Day, Month, Year;
	Prieten(string newName);
};
class Cunoscut :public Contact {
public:
	string Mobile;
	Cunoscut(string newName);
};
class Coleg :public Contact {
public:
	string Adress;
	string Mobile;
	string Company;
	Coleg(string newName);
};
class Agenda {
private:
	vector<Contact*> Agenda;
public:
	void Add(Contact*newContact);
	bool Exists(string searchedByName);
	vector<Contact*> ListOfFriend();
	void Delete(string deleteByName);
	void Print();

};
int main()
{
	/**
	Prieten h("Ovidiu");
	Prieten m("George");
	Cunoscut kl("Petru");
	Coleg ll("Mircea");
	*/
	Contact* h = new Prieten("Ovidiu");
	Contact* m = new Prieten("George");
	Contact* kl = new Cunoscut("Petru");
	Contact* ll = new Coleg("Mircea");
	Agenda newAg;
	newAg.Add(h);
	newAg.Add(kl);
	newAg.Add(ll);
	newAg.Add(m);
	newAg.Print();
	cout << endl;
	vector<Contact*> list = newAg.ListOfFriend();
	for (auto it : list)
		cout << it->Name << " ";
	cout << endl;
	newAg.Delete("Petru");
	newAg.Print();
	return 0;
}

Contact::Contact()
{

}

Prieten::Prieten(string newName)
{
	this->Name = newName;
	this->Type = 1;
}

Cunoscut::Cunoscut(string newName)
{
	this->Name = newName;
	this->Type = 2;
}

Coleg::Coleg(string newName)
{
	this->Name = newName;
	this->Type = 3;
}

void Agenda::Add(Contact * newContact)
{
	Agenda.push_back(newContact);
}

bool Agenda::Exists(string searchedByName)
{
	for (auto it : Agenda)
		if (it->Name == searchedByName)
			return true;
	return false;
}

vector<Contact*> Agenda::ListOfFriend()
{
	vector<Contact*> friends;
	for (auto it : Agenda)
		if (it->Type==1)
			friends.push_back(it);
	return friends;
}

void Agenda::Delete(string deleteByName)
{
	int count = 0;
	for (auto it : Agenda)
	{
		if (it->Name == deleteByName)
			Agenda.erase(Agenda.begin() + count);
			count++;
	}	
}

void Agenda::Print()
{
	for (auto it : Agenda)
		cout << it->Name << " ";
}
