#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <variant>
#include <array>
#include <iterator>

namespace core
{
	template<typename T, size_t N>
	class BasicVector
	{
		using StackArray = std::array<T, N>;
		using HeapVector = std::vector<T>;

		std::variant<StackArray, HeapVector> data_;

	public:
		
	};

	template<typename T, size_t N>
	class SmallVector
	{
		int size_ = 0;

	public:
		SmallVector() = default;

		SmallVector(std::initializer_list<T> list)
		{
			const auto size = list.size();
			if(size > N)
			{
				std::terminate();
			}
			std::copy(list.begin(), list.end(), underlyingContainer_.begin());
			size_ = size;
		}

		auto begin()
		{
			return data_.begin();
		}
		auto end()
		{
			return data_.begin() + size_;
		}

		void push_back(const T& value)
		{
			if (size_ == Capacity)
			{
				std::terminate();
			}
			underlyingContainer_[size_] = value;
			size_++;
		}

		void push_back(T&& value)
		{
			if (size_ == Capacity)
			{
				// Over-capacity leads to a crash
				std::terminate();
			}
			underlyingContainer_[size_] = std::move(value);
			size_++;
		}

		void Clear()
		{
			if constexpr (std::is_destructible_v<T>)
			{
				for (int i = 0; i < size_; i++)
				{
					underlyingContainer_[i].~T();
				}
			}
			size_ = 0;
		}

		auto erase(std::array<T, Capacity>::iterator pos)
		{
			std::move(pos + 1, end(), pos);
			size_--;
			return pos;
		}

		auto erase(std::array<T, Capacity>::const_iterator pos)
		{
			const auto index = std::distance(cbegin(), pos);
			for (auto i = index; i < size_ - 1; i++)
			{
				underlyingContainer_[i] = std::move(underlyingContainer_[i + 1]);
			}
			size_--;
			return pos;
		}

		constexpr auto capacity() const
		{
			return Capacity;
		}
		constexpr auto size() const
		{
			return size_;
		}
	};
}

#endif //VECTOR_H