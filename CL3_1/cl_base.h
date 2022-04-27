#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base
{
private:
	string object_name;
	cl_base* parent;
	vector <cl_base*> children;
	int condition;
	void remove(string name);
	void add(cl_base* children_point);
public:
	cl_base(cl_base* parent, string object_name="empty");
	void name_setter(string name);
	void parent_setter(cl_base* parent);
	cl_base* get_parent();
	string get_name();
	cl_base* get_obj_by_name(string object_name);
	void print_tree(bool out_condition=false,const int lvl=0);
	void condition_setter(int condition_value);
	int condition_getter();
};
#endif