#include <boost/python.hpp>

int main()
{
    namespace bp = boost::python;

    try {
        Py_Initialize();
        bp::object py_main_module = bp::import("__main__");
        bp::dict py_main_namespace
            = bp::extract<bp::dict>(py_main_module.attr("__dict__"));
        py_main_namespace["s"] = "World";
        bp::exec_file("embedding.py", py_main_namespace, py_main_namespace);
    } catch (const bp::error_already_set& e) {
        PyErr_PrintEx(0);
        return 1;
    }

    return 0;
}
