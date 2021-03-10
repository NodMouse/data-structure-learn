#ifndef HAD
#define HAD
class time{
    private:
        int hours;
        int mins;
    public:
        time();
        time(int h, int m = 0);
        void Addmin(int m);
        void AddHr(int h);
        void reset(int h = 0, int m = 0);
        time operator+(const time &t) const;
        void show() const;
        time operator-(const time &t) const;
};
#endif