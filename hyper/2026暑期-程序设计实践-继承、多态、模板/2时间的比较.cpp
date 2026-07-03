class TIME {
private:
    int hour, minute, second;
    
    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour >= 24) {
            hour %= 24;
        }
    }
    
    // 转换为总秒数，便于比较
    int toSeconds() const {
        return hour * 3600 + minute * 60 + second;
    }
    
public:
    TIME(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        normalize();
    }
    
    // 输出运算符
    friend ostream& operator<<(ostream& os, const TIME& t) {
        os << setw(2) << setfill('0') << t.hour << ":"
           << setw(2) << setfill('0') << t.minute << ":"
           << setw(2) << setfill('0') << t.second;
        return os;
    }
    
    // 输入运算符
    friend istream& operator>>(istream& is, TIME& t) {
        char ch1, ch2;
        is >> t.hour >> ch1 >> t.minute >> ch2 >> t.second;
        t.normalize();
        return is;
    }
    
    // TIME > TIME
    bool operator>(const TIME& t) const {
        return toSeconds() > t.toSeconds();
    }
    
    // TIME > int
    bool operator>(int h) const {
        return toSeconds() > TIME(h).toSeconds();
    }
    
    // int > TIME（友元函数）
    friend bool operator>(int h, const TIME& t) {
        return TIME(h) > t;
    }
    
    // 为了更完整的比较，还可以添加 <, >=, <=, ==, !=
    bool operator<(const TIME& t) const {
        return toSeconds() < t.toSeconds();
    }
    
    bool operator==(const TIME& t) const {
        return toSeconds() == t.toSeconds();
    }
    
    bool operator>=(const TIME& t) const {
        return !(*this < t);
    }
    
    bool operator<=(const TIME& t) const {
        return !(*this > t);
    }
    
    bool operator!=(const TIME& t) const {
        return !(*this == t);
    }
};