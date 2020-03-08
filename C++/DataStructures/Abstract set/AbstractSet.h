#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class AbstractSet
{
	vector<bool(*)(T)> conditions;
	vector<bool(*)(T)> exceptions;
	vector<T> others;
public:
	// Constructors.
	AbstractSet(){}
	AbstractSet(bool (*c)(T)) { conditions.push_back(c); }

	// Functions to add a condition/exception to the Set.
	void addCondition(bool (*c)(T)) { conditions.push_back(c); }
	void addException(bool (*c)(T)) { exceptions.push_back(c); }

	// Inserts a single value into the Set.
	void insert(T a) { others.push_back(a); }
	
	// Returns true/false depending on whether a is in the Set.
	bool contains(T a)
	{
		bool inSet = false;
		// Checking if "a" fits either condition, or is among the inserted values.
		for(int i = 0; i != conditions.size() && !inSet; i++)
			inSet = conditions[i](a);
		for(int i = 0; i != others.size() && !inSet; i++)
			inSet = (a == others[i]);
		for(int i = 0; i != exceptions.size() && inSet; i++)
			inSet = !exceptions[i](a);

		return inSet;
	}
};