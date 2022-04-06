#include "cl_base.h"
#include "cl_node.h"
#include <string>
cl_base::cl_base(cl_base* parent, string object_name)
{
	this->object_name = object_name;
	this->parent=parent;
	if (parent)
	{
		parent->add(this);
	}
}
void cl_base::name_setter(string name)
{
	this->object_name = name;
}
void cl_base::parent_setter(cl_base* parent)
{
	if (parent != nullptr)
	{
		parent->remove(object_name);
	}
	this->parent = parent;
	this->parent->add(this);
}
cl_base* cl_base::get_parent()
{
	return parent;
}
string cl_base::get_name()
{
	return object_name;
}
void cl_base::add(cl_base* children_point)
{
	if(children_point!= nullptr)
	{
		children.push_back(children_point);
	}
}
void cl_base::remove(string name)
{
	for (int i = 0; i <  children.size(); i++)
	{
		if (children[i]->get_name() == name)
		{
			children.erase(children.begin() + i);
			break;
		}
	}
}
cl_base* cl_base::get_obj_by_name(string name)
{
	cl_base* val;
	if(object_name==name)
	{
		return this;
	}
	for (int i = 0; i < this->children.size(); i++)
	{
		val = children[i]->get_obj_by_name(name);
		if (val!= nullptr)
		{
			return val;
		}
	}
	return nullptr;
}
void cl_base::print_tree()
{
	if(parent== nullptr)
	{
		cout<<object_name;
	}
	if(children.size()>0)
	{
		cout<<endl<<object_name;
		for (int i = 0; i < children.size(); i++)
		{
			cout<<" "<<children[i]->get_name();
		}
		for (int i = 0; i < children.size(); i++)
		{
			children[i]->print_tree();
		}
	}
}
cl_base::~cl_base()
{
}