#include "tree/tree.h"

#include <iostream>


using namespace behaviour_tree;

void Tree::Tick()
{
	if (root_ != nullptr)
	{
		Status status = root_->Process();
	}

}

void Tree::Attach(std::unique_ptr<Leaf>& node)
{
	root_ = std::move(node);
}

void Tree::Attach(std::unique_ptr<Sequence>& node)
{
	root_ = std::move(node);
}

void Tree::Attach(std::unique_ptr<Selector>& node)
{
	root_ = std::move(node);
}