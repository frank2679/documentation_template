// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _TYPES_H_
#define _TYPES_H_

#include <string>
#include <utility>

class SublasException : public std::exception {
  public:
    SublasException(const std::string &msg) : _msg(msg) {}
    virtual ~SublasException() throw() {}
    virtual const char *what() const throw() { return this->_msg.c_str(); }

  private:
    std::string _msg;
};

#endif // _TYPES_H_