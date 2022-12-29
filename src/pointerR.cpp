#include <Rcpp.h>
// [[Rcpp::depends(tidyCpp)]]
#include <tidyCpp>

template<typename T>
class Pointer {
  
public:

  T* data;
  size_t size;

  Pointer(int size) {
    this -> size = static_cast<size_t>(size);
    data = new T[size];
    if(std::is_integral<T>::value) {
      for(size_t i = 0; i < size; i++) data[i] = 0;  
    } else if(std::is_floating_point<T>::value) {
      for(size_t i = 0; i < size; i++) data[i] = 0.0;
    } else {
      Rcpp::stop("Error: unknown type");
    }
  }

  ~Pointer() {
    if(data != nullptr) delete[] data; else Rcpp::stop("Error deleting");
    size = 0;
    data = nullptr;
  }
  
  void deleteit() {
    if(data != nullptr) delete[] data; else Rcpp::stop("Error deleting");
    size = 0;
    data = nullptr;
  }
  
  void resize(int new_size) {
    this -> size = static_cast<size_t>(new_size);
    if(data != nullptr) delete[] data; else Rcpp::stop("Error deleting");
    data = nullptr;
    data = new T[new_size];
    if(std::is_integral<T>::value) {
      for(size_t i = 0; i < size; i++) data[i] = 0;  
    } else if(std::is_floating_point<T>::value) {
      for(size_t i = 0; i < size; i++) data[i] = 0.0;
    } else {
      Rcpp::stop("Error: unknown type");
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
RCPP_MODULE(bools) {
  Rcpp::class_<Pointer<bool> >( "bools" )
  .constructor<int>()
  .field( "size", &Pointer<bool>::size )
  .method( "print", &Pointer<bool>::print )
  .method( "[[", &Pointer<bool>::at )
  .method( "[[<-", &Pointer<bool>::set )
  .method( "resize", &Pointer<bool>::resize )
  .method( "delete", &Pointer<bool>::deleteit )
  ;
}

// logical, integer, real, string (or character)
RCPP_MODULE(numeric) {
  Rcpp::class_<Pointer<double> >( "numeric" )
  .constructor<int>()
  .field( "size", &Pointer<double>::size )
  .method( "print", &Pointer<double>::print )
  .method( "[[", &Pointer<double>::at )
  .method( "[[<-", &Pointer<double>::set )
  .method( "resize", &Pointer<double>::resize )
  .method( "delete", &Pointer<double>::deleteit )
  ;
}





class P {
  
  public:
    double* data;
    size_t size;
    
    P(SEXP obj) {
      data = REAL(obj);
      size = Rf_length(obj);
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

// logical, integer, real, string (or character)
RCPP_MODULE(num_p) {
  Rcpp::class_<P>( "num_p" )
  .constructor<SEXP>()
  .field( "size", &P::size )
  .method( "print", &P::print )
  .method( "[[", &P::at )
  .method( "[[<-", &P::set )
  ;
}