
#include <iostream>
 
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
    AlertRule rule;
    Notification notification; 

  public: 
    Alert(AlertRule rule, Notification notification): rule(rule), notification(notification){}
    ~Alert()=default;

    void check(long requestCount, long errorCount, long durationOfSeconds) {
        long tps = requestCount / durationOfSeconds;
        if (tps > rule.getMaxTps()) {
            notification.notify(1);
        }
        if (errorCount > rule.getMaxErrorCount()) {
            notification.notify(2);
        }
    }
};
 
// 程序的主函数
int main( )
{
    AlertRule rule(10, 100);
    Notification notification;
    Alert alert(rule, notification);
    alert.check(50, 80, 2);
    return 0;
}
