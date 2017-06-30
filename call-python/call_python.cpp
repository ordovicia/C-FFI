// #include <cstdlib>
#include <iostream>
#include <exception>
#include <boost/python.hpp>

int main()
{
    using namespace std;
    namespace bp = boost::python;

    try {
        // setenv("PYTHONPATH", ".", 1);
        Py_Initialize();
        bp::object py_main_module = bp::import("__main__");
        bp::dict py_main_namespace
            = bp::extract<bp::dict>(py_main_module.attr("__dict__"));

        py_main_namespace["p"] = "po";
        std::string p = bp::extract<std::string>(py_main_namespace["p"]);
        cout << "Defined 'p = \"po\"'\n"
             << "(C++) p = \"" << p << "\"\n" << endl;

        bp::object py_s2 = bp::eval("p + p", py_main_namespace);
        p = bp::extract<std::string>(py_main_namespace["p"]);
        std::string pp = bp::extract<std::string>(py_s2);
        cout << "Evaluated 'p + p'; resulting in 'pp'\n"
             << "(C++) p = \"" << p << "\"\n"
             << "(C++) pp = \"" << pp << "\"\n" << endl;

        bp::exec(R"(
def f():
    global p
    p = p + p
    return p

f()
)",
            py_main_namespace);
        p = bp::extract<std::string>(py_main_namespace["p"]);
        cout << "Executed 'p = p + p'\n"
             << "(C++) p = \"" << p << "\"\n" << endl;

        cout << "Executing 'embedding.py'" << endl;
        bp::exec_file("embedding.py", py_main_namespace);
        std::string ppp = bp::extract<std::string>(py_main_namespace["ppp"]);
        cout << "(C++) ppp = \"" << ppp << "\"\n" << endl;

        cout << "Executing '1 / 0'" << endl;
        bp::exec_file("embedding.py", py_main_namespace);
        bp::exec("1 / 0");
    } catch (const bp::error_already_set& e) {
        if (PyErr_ExceptionMatches(PyExc_ZeroDivisionError)) {
            cerr << "(C++) ZeroDivisionError" << endl;
        }
        PyErr_Print();
        return 1;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
