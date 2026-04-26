#include "NotFoundException.h"

NotFoundExcep::NotFoundExcep(const string& message) : exception("Not Found Exception: " + message){
} // end constructor
