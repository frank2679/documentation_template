
#include <iostream>
#include <list>

using namespace std;

class AlertRule {
    long maxTps;
    long maxErrorCount;
  public:
    AlertRule(long tps, long errorCount): maxTps(tps), maxErrorCount(errorCount) {}
    long getMaxTps() {return maxTps;}
    long getMaxErrorCount() {return maxErrorCount;}
};

class Notification {
  public:
    void notify(int level) {
        if (level == 1) {
            cout << "urgent" << endl;
        } else if (level == 2) {
            cout << "fatal" << endl;
        } else {
            cout << "no level specified" << endl;
        }
    }
};

class Alert {
    list<AlertRule> rules; 

  public: 
    // Alert(AlertRule rule, Notification notification): rule(rule), notification(notification){}
    ~Alert()=default;

    void addAlertRule(AlertRule &rule) {
        rules.push_back(rule);
    }
};

struct ApiStatusInfo {
    long requestCount;
    long errorCount;
    long durationOfSecond;
    long timeOut;
};

class AlertHandler {
  protected:
    AlertRule rule;
    Notification notification;
  public:
    AlertHandler()=default;
    AlertHandler(AlertRule& rule, Notification& notification): rule(rule), notification(notification) {};
    virtual ~AlertHandler()=default;
    virtual void check(ApiStatusInfo status)=0;
};

class TpsAlertHandler: public AlertHandler {
  public:
    TpsAlertHandler(AlertRule& rule, Notification& notification): AlertHandler(rule, notification){}
    virtual void check(ApiStatusInfo status) {
        if (status.requestCount/status.durationOfSecond > rule.getMaxTps()) {
            notification.notify(1);
        }
    }
};

class ErrorAlertHandler: public AlertHandler{
  public:
    // ErrorAlertHandler()=default;
    ErrorAlertHandler(AlertRule& rule, Notification& notification): 
        AlertHandler(rule, notification){};
    virtual void check(ApiStatusInfo status) {
        if (status.errorCount > rule.getMaxErrorCount()) {
            notification.notify(2);
        }
    }
};
 
// 程序的主函数
int main()
{
    AlertRule rule(10, 100);
    Notification notification;
    Alert alert;
    alert.addAlertRule(rule);
    struct ApiStatusInfo status = {50,80,2,8};

    ErrorAlertHandler errHdl(rule, notification);
    errHdl.check(status);
    return 0;
}
