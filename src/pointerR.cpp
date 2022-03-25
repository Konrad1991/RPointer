#include <Rcpp.h>
// [[Rcpp::depends(tidyCpp)]]
#include <tidyCpp>


template<typename T>
class Pointer {
public:

  T* data;
  size_t size;
  int del;

  Pointer(int size) {
    this -> size = size;
    data = new T[size];
    del = 1;
  }

  Pointer(SEXP obj) {
    del = 2;
    data = R::logicalPointer(obj);
  }

  ~Pointer() {
    if(del == 1) {
        delete[] data;
    }
  }

  T& operator[](int i) {
    return data[i];
  }

  T& at(int i) {
    return data[i];
  }

  void set(int i, T value ) { this -> at( i ) = value; }

  void print() {
    for(size_t i = 0; i < size; i++) {
      Rcpp::Rcout << data[i] << std::endl;
    }
  }

};

// logical, integer, real, string (or character)
RCPP_MODULE(pointer_module) {
  Rcpp::class_<Pointer<bool> >( "Pointer" )
  .constructor<int>()
  .field( "size", &Pointer<bool>::size )
  .method( "print", &Pointer<bool>::print )
  .method( "[[", &Pointer<bool>::at )
  .method( "[[<-", &Pointer<bool>::set )
  ;
}
