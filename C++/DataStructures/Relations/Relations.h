#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class OrderedPair
{
	T f;
	T s;
public:
	T& first () { return f;  }
	T& second() { return s; }
	OrderedPair(T a, T b)
	{
		f  = a;
		s = b;
	}
};

template <class T>
class Relation
{
	vector<bool(*)(T, T)> conditions;
	vector<OrderedPair<T>> others;
public:	
	void addCondition(bool (*c)(T, T)) { conditions.push_back(c); }
	void insert(T a, T b)
	{
		OrderedPair<T> addition(a,b);
		others.push_back(addition);
	}
	bool relates(T a, T b)
	{
		bool doesRelate = false;
		for(int i = 0; i != conditions.size() && !doesRelate; i++)
			doesRelate = conditions[i](a,b);
		for(int i = 0; i != others.size() && !doesRelate; i++)
			doesRelate = (a == others[i].first() && b == others[i].second());

		return doesRelate;
	}
	friend Relation<T> operator+(Relation<T> r1, Relation<T> r2)
	{
		for (int i = 0; i < r2.conditions.size(); i++)
			r1.conditions.push_back(r2.conditions[i]);
		for (int i = 0; i < r2.others.size(); i++)
			r1.others.push_back(r2.others[i]);
		return r1;					
	}

	friend Relation<T> operator-(Relation<T> r1, Relation<T> r2)
	{
		for (int i = 0; i < r1.conditions.size(); i++)
			for (int x = 0; x < r2.conditions.size(); x++)
				if (r1.conditions[i] == r2.conditions[x])
				{
					r1.others.erase(r1.others.begin() + i);
					break;
				}

		for (int i = 0; i < r1.others.size(); i++)
			for (int x = 0; x < r2.others.size(); x++)
				if (r1.conditions[i] == r2.conditions[x])
				{
					r1.others.erase(r1.others.begin() + i);
					break;
				}
		return r1;	
	}
};

