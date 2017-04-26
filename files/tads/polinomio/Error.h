#include <string>

using namespace std;

#ifndef ERROR_H_
#define ERROR_H_

class Error{
	private:
		string message;

	public:
		Error(string m){message = m;}
		string getMessage(){return message;}
};

#endif /* ERROR_H_ */
