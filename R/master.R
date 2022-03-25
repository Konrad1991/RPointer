



#' @export
Pointer <- R6::R6Class("Pointer",
                   
        public = list(
        data = NULL,
        
        initialize = function(sexp_obj) {
          p <- Module("pointer_module", inline::getDynLib("RPointer"), mustStart = TRUE)
          p <- p$Pointer
          v <- new(p, sexp_obj)
          self$data <- v
        },
        
        '[' = function(index) {
          return(self$data[[index]])
        }
        
        )
        
)