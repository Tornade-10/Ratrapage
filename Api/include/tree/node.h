#ifndef API_NODE_H_
#define API_NODE_H_

#include <memory>
#include <vector>


namespace behaviour_tree
{
	enum class Status
	{
		kRunning,
		kFailure,
		kSuccess
	};

	class Node
	{

	public:
		Node() = default;
		virtual ~Node() = default;
		virtual Status Process() = 0;
		virtual void Reset() = 0;

	};

	class NodeList : public Node
	{

	protected:
		int current_child_ = 0;
		std::vector<Node*> children_;

	public:
		void Add(Node* node)
		{
			children_.push_back(node);
		}
		void Reset() override;

	};

}
#endif // BT_NODE_H