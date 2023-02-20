#ifndef MINA_COMPONENTS_KEYSET_HPP
#define MINA_COMPONENTS_KEYSET_HPP

#include "../pch.hpp"

#include "../Commons/Type.hpp"

namespace Mina::Component
{

template <typename T>
struct KeySet
{
	int currentIdx;
	std::vector<T> data;

	template <typename T>
	T& current()
	{
		return data[currentIdx];
	}

	/**
	 * find lower bound
	 */
	template <typename T>
	T& lowerBound(time_t time)
	{
		int size = data.size() - 1;
		for (int i = currentIdx; i < size; ++i)
		{
			if (time <= data[i + 1].time)
			{
				return data[i];
			}
		}
		// last
		return data[size];
	}

	/**
	 * find upper bound
	 */
	template <typename T>
	T& upperBound(time_t time)
	{
		int size = data.size();
		for (int i = currentIdx; i < size; ++i)
		{
			if (time <= data[i].time)
			{
				return data[i];
			}
		}
		// last
		return data[size - 1];
	}
};

}	 // namespace Mina::Component

#endif