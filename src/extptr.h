
// some external pointer tools, experimental
#include <Rcpp/Lightest>

void assert_xptr_inherits(SEXP xp, const std::string& classname) {
    if (!Rf_inherits(xp, classname.c_str()))
        Rcpp::stop("Expected class '%s' not found");
}

template <typename T>
inline T* xptr_get_ptr(SEXP xp, const std::string& classname = "") {
    if (classname != "")
        assert_xptr_inherits(xp, classname);
    T* ptr = reinterpret_cast<T*>(R_ExternalPtrAddr(xp));
    if (ptr == nullptr)
        Rcpp::stop("External pointer is null");
    return ptr;
}
