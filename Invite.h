#ifndef INVITE_H
#define INVITE_H
#include <string>
using namespace std;

class Invite {
    private:
        string date;
        string time;
        double duration;
        string people[20]; // FIXME

    public:
        string subject;
        string organizer;

        Invite();
        Invite(string Date, string Time);

        ~Invite() {
            delete[] people;
        }

        void setDuration(double d) {
            if (d >= 0) {
                duration = d;
            }
        }

        double getDuration() {
            return duration;
        }
};

#endif