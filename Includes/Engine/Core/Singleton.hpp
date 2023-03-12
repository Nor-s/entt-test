#ifndef MINA_SINGLETON_H
#define MINA_SINGLETON_H

namespace Mina
{

template <typename T>
class Singleton
{
protected:
	Singleton() = default;

public:
	Singleton(Singleton<T>&&) = delete;
	Singleton(const Singleton<T>&) = delete;

	Singleton<T>& operator=(const Singleton<T>&) = delete;
	Singleton<T>& operator=(Singleton<T>&&) = delete;

	~Singleton() = default;

	static T& get()
	{
		static T instance;
		return instance;
	}
};

}	 // namespace Mina

#endif