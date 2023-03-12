#ifndef MINA_KEYSET_HPP
#define MINA_KEYSET_HPP

#include "entt-test/Includes/Engine/pch.hpp"

#include "entt-test/Includes/Engine/Commons/Type.hpp"

namespace Mina
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

}	 // namespace Mina

#endif