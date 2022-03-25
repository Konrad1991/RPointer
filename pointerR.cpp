#include <tidyCpp>
// [[Rcpp::depends(tidyCpp)]]

// [[Rcpp::export]]
void change_vec(SEXP a, double value) {
  
  int na;
  double* xa;
  
  xa = R::numericPointer(a);
  na = R::length(a);
  
  for(int i = 0; i < na; i++) {
    *(xa + i) = value;
  }
  
}


#include <Rcpp.h>
using namespace Rcpp;

class Vec {
public:
  
  double* data;
  size_t size;
  
  Vec(int size) {
    this -> size = size;
    data = new double[size];
  }
  
  ~Vec() {
    delete[] data;
  }
  
  double& operator[](int i) {
    return data[i];
  }
  
  double& at(int i) {
    return data[i];
  }
  
  void set(int i, double value ) { this -> at( i ) = value; }
  
  void print() {
    for(size_t i = 0; i < size; i++) {
      Rcpp::Rcout << data[i] << std::endl;
    }
  }

};


RCPP_MODULE(vec_module) {
  class_<Vec>( "Vec" )
  .constructor<int>()
  .field( "size", &Vec::size )
  .method( "print", &Vec::print )
  .method( "[[", &Vec::at )
  .method( "[[<-", &Vec::set )
  ;
}



/*** R
a <- c(1, 2, 3)
change_vec(a, 30)
a

v <- new( Vec, 10 )
v$print()
v[[1]] <- 1
v$print()

f <- function(a) {
  for(i in 0:9) {
    a[[i]] <- i
  }
  
  return()
}


f(v)
v$print()
*/
