#include <functional>
#include <memory>

#include "base/base.h"

class ConvfwdCrossDirect {
  public:
    ConvfwdCrossDirect(){};
    ~ConvfwdCrossDirect(){};

    // used to instantiate an op
    static std::shared_ptr<ConvfwdCrossDirect> Instance() {
        static std::shared_ptr<ConvfwdCrossDirect> ptr;
        if (!ptr.get()) {
            ptr = std::make_shared<ConvfwdCrossDirect>();
        }
        return ptr;
    }

  public:
    std::function<sublasStatus_t(int a)> Compute(); // TBD, transfer param
};