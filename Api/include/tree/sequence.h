#ifndef API_SEQUENCE_H
#define API_SEQUENCE_H

#include <iostream>

#include "node.h"

using namespace behaviour_tree;

class Sequence : public NodeList
{
public:
	~Sequence() override = default;


	Status Process() override;

};

inline Status Sequence::Process()
{

	if (current_child_ < children_.size())
	{
		const Status status = children_[current_child_]->Process();

		if (status == Status::kSuccess)
		{
			std::cout << "Next sequence !" << std::endl;

			children_[current_child_]->Reset();

			current_child_++;
			if (current_child_ >= children_.size())
			{
				current_child_ = 0;
				return Status::kSuccess;
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