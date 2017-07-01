int mult2(int x)
{
    return x * 2;
}

int sum(int x, int y = 0)
{
    return x + y;
}

int sub(int x)
{
    return x;
}

int sub(int x, int y)
{
    return x - y;
}

double sub(double x)
{
    return x;
}

double sub(double x, double y)
{
    return x - y;
}

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_FUNCTION_OVERLOADS(sum_overloads, sum, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(sub_overloads, sub, 1, 2)

BOOST_PYTHON_MODULE(fn)
{
    double (*sub_double_1)(double) = sub;
    double (*sub_double_2)(double, double) = sub;

    def("mult2", mult2);
    def("sum", sum, sum_overloads());
    def("sub", (int (*)(int, int))0, sub_overloads());
    def("sub", sub_double_1);
    def("sub", sub_double_2);
}
