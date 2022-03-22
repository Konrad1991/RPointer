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



/*** R
a <- c(1, 2, 3)
change_vec(a, 30)
a
*/
