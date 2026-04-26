#ifndef _NOTFOUND_EXCEP_H_
#define _NOTFOUND_EXCEP_H_

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundExcep : public exception {
    public :
        NotFoundExcep(const string& message = "");
}; // end NotFoundExcep

#endif