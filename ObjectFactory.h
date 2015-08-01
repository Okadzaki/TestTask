#pragma once
#include <map>
#include <string>
#include <memory>
#include <sstream>
	template <class Base>
	class AbstractCreator
	{
	public:
		AbstractCreator()
		{
		}

		virtual ~AbstractCreator()
		{
		}

		virtual Base* create() const = 0;

	private:
		AbstractCreator(const AbstractCreator&);
		AbstractCreator& operator = (const AbstractCreator&);
	};


	template <class C, class Base>
	class Creator : public AbstractCreator<Base>
	{
	public:
		Creator()
		{
		}

		virtual ~Creator()
		{
		}

		Base * create() const
		{
			return new C();
		}
	};

	
	template <class Base, class IdType = int>
	class ObjectFactory
	{
	protected:
		typedef AbstractCreator<Base> AbstractFactory;
		typedef std::map<IdType, AbstractFactory*> FactoryMap;

	public:
		ObjectFactory()
		{
		}

		virtual ~ObjectFactory()
		{
			for (typename FactoryMap::iterator it = _map.begin(), endIt = _map.end(); it != endIt; ++it)
				delete it->second;
		}

		Base * create(const IdType & id) const
		{
			typename FactoryMap::const_iterator it = _map.find(id);
			if (it != _map.end())
				return it->second->create();
			return nullptr;
		}

		template <class C>
		void add(const IdType & id)
		{
			registerClass(id, new Creator<C, Base>);
		}

		void remove(const IdType & id)
		{
			typename FactoryMap::iterator it = _map.find(id);
			if (it != _map.end())
			{
				delete it->second;
				_map.erase(it);
			}
			else
				return;
		}

		bool isRegistered(const IdType & id) const
		{
			return _map.find(id) != _map.end();
		}

		size_t size() const
		{
			return _map.size();
		}


	protected:
		void registerClass(const IdType & id, AbstractFactory * pAbstractFactory)
		{
			std::auto_ptr<AbstractFactory> ptr(pAbstractFactory);
			typename FactoryMap::iterator it = _map.find(id);
			if (it == _map.end())
				_map[id] = ptr.release();
			else
				return;
		}

	private:
		ObjectFactory(const ObjectFactory&);
		ObjectFactory& operator = (const ObjectFactory&);

		FactoryMap _map;
	};