#include "ObjectFactory.h"
#include <iostream>

enum Type
{
    fooType,
    barType,
    maskedType,
    unknownType,
    firstType = fooType,
    lastType = maskedType,
};

enum FigureTypes {
	square = 1,
	circle = 2,
	unknown = 3,
	anc = 4,
	polygon = 5,
	polygon_line = 6,
	unknown_type = 28
};


std::ostream & operator << (std::ostream & strm, const Type & type)
{	
    const char * names[] = {"foo", "bar", "masked"};
    if (type < firstType || type > lastType)
        return strm << "unknown type(" << int(type) << ")";	
    return strm << names[type];	
};

class Base
{
public:
    virtual ~Base() {}
    virtual Type type() const = 0;
};

class Foo : public Base
{
public:
    virtual Type type() const { return fooType; }
};

class Bar : public Foo
{
public:
    virtual Type type() const { return barType; }
};

class MaskedFoo : public Foo
{
public:
    virtual Type type() const { return barType; }
};

typedef ObjectFactory<Base, Type> TypeFactory;

void checkType(TypeFactory & factory, Type type)
{
    std::auto_ptr<Base> p;
	
    p.reset(factory.create(type));
    std::cout << "Object with type : " << type;
    if (p.get())
    {
        if (type == p->type())	
            std::cout << " - successfully created\n";
        else
            std::cout << " - created, but type mismatch\n";
    }
    else
        std::cout << " - create failed\n";
}

int main()
{
	TypeFactory factory;
	factory.add<Foo>(fooType);
	factory.add<Bar>(barType);
	factory.add<MaskedFoo>(maskedType);

	checkType(factory, fooType);
	checkType(factory, barType);
	checkType(factory, maskedType);
	checkType(factory, unknownType);

	return 0;

}