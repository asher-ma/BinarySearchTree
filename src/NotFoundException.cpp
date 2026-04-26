#include "NotFoundException.h"

NotFoundExcep::NotFoundExcep(const string& message) : runtime_error("Not Found Exception: " + message){
} // end constructor
