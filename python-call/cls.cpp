#include <string>
#include <ostream>

struct Person {
public:
    explicit Person(std::string name) : name(name) {}
    explicit Person(std::string name, int age) : name(name), age(age) {}

    const std::string name;

    std::string greet() const { return "My name is " + name; }

    int age = 0;
    void grow() { age++; }

    int getHeight() const { return m_height; }
    void setHeight(int height) { m_height = height; }

    int getWeight() const { return m_weight; }

    Person& operator+=(int age)
    {
        this->age += age;
        return *this;
    }

    Person& operator-=(int age) { return (*this += -age); }

    using iterator = std::string::const_iterator;
    auto begin() { return name.begin(); }
    auto end() { return name.end(); }

private:
    int m_height = 0;
    int m_weight = 50;
};

Person& operator+(int age, Person& p)
{
    p += age;
    return p;
}

std::ostream& operator<<(std::ostream& os, Person p)
{
    os << p.name;
    return os;
}

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(cls)
{
    class_<Person>("Person", init<std::string>())
        .def(init<std::string, int>())
        .def("greet", &Person::greet)
        .def_readwrite("age", &Person::age)
        .def("grow", &Person::grow)
        .add_property("height", &Person::getHeight, &Person::setHeight)
        .add_property("weight", &Person::getWeight)
        .def(self += int())
        .def(self -= int())
        .def(int() + self)
        .def(self_ns::str(self_ns::self))
        .def("name_string", iterator<Person>());
}
