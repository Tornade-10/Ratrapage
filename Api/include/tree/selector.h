#ifndef API_SELECTOR_H
#define API_SELECTOR_H

#include <iostream>

#include "node.h"

using namespace behaviour_tree;

class Selector : public NodeList
{
public:
	Status Process() override;
	~Selector() override = default;
};

inline Status Selector::Process()
{

	if (current_child_ < children_.size())
	{
		const Status status = children_[current_child_]->Process();

		if (status == Status::kFailure)
		{
			std::cout << "Next leaf !" << std::endl;

			children_[current_child_]->Reset();

			current_child_++;
			if (current_child_ >= children_.size())
			{
				current_child_ = 0;
				return Status::kFailure;
			}
			else
			{
				return Status::kRunning;
			}
		}

		return status;

	}

	return Status::kFailure;

}

#endif