#ifndef FIBO_UTILS_HPP
#define FIBO_UTILS_HPP

#include <chrono>
#include <string>
#include <list>
#include <stdexcept>

typedef std::list<u_char> numberType;

static u_char sumc(const u_char a, const u_char b , u_char &c)
{
    if (a > 9 || b > 9)
    {
        throw std::invalid_argument("[sumc]inputs are invalid, a and b should be between 0 to 9!");
    }
    if (c > 1)
    {
        throw std::invalid_argument("[sumc] inputs are invalid, carrier cannot be higher than 1");
    }

    int temp = a + b + c;
    c = 0;
    if(temp >= 10) {
        c= temp/10;
        temp %=10;
    }
    return temp;
}

static numberType add(const numberType &a, const numberType &b)
{
    std::list<u_char> ret;
    auto ait = a.rbegin();
    auto bit = b.rbegin();
    
    u_char temp, c =0;
    while (ait != a.rend() || bit != b.rend())
    {
        temp = sumc((ait != a.rend()? *ait : 0),
                    (bit != b.rend()? *bit : 0),
                    c);
                    
        ret.push_front(temp);
            
        if (ait != a.rend()) 
            ait++;
            
        if (bit != b.rend()) 
            bit++;
    }

    if(c != 0)
        ret.push_front(c);
    
    if(!ret.size()) 
            ret.push_front(0);

    return ret;
    
}

class TimeMeasure
{
    public:
    TimeMeasure()
    {

    }
    void start()
    {
        mStartTime = std::chrono::system_clock::now();
    }
    std::string stop()
    {
        mEndTime = std::chrono::system_clock::now();
        return  "Took " + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(mEndTime - mStartTime).count()) + " (uS)";
    }

private:
	std::chrono::_V2::high_resolution_clock::time_point mStartTime;
	std::chrono::_V2::high_resolution_clock::time_point mEndTime;
};

#endif // FIBO_UTILS_HPP
