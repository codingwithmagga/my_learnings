#include <chrono>
#include <iostream>
#include <functional>

using namespace std::chrono;
using namespace std::literals;
using namespace std::placeholders;

using Time = steady_clock::time_point;
enum class Sound
{
    Beep,
    Siren,
    Whistle
};
using Duration = steady_clock::duration;

enum class Volume
{
    Normal,
    Loud,
    LoudPlusPlus
};

void setAlarm(Time t, Sound s, Duration d)
{
    std::cout << "Alarm set for " << duration_cast<seconds>(t.time_since_epoch()).count() << " seconds, sound: " << static_cast<int>(s) << ", duration: " << duration_cast<seconds>(d).count() << " seconds\n";
}

void setAlarm(Time t, Sound s, Duration d, Volume v)
{
    std::cout << "Alarm set for " << duration_cast<seconds>(t.time_since_epoch()).count() << " seconds, sound: " << static_cast<int>(s) << ", duration: " << duration_cast<seconds>(d).count() << " seconds, volume: " << static_cast<int>(v) << "\n";
}

auto setSoundL = [](Sound s)
{
    setAlarm(steady_clock::now() + 1h, s, 30s);
};

using SetAlarm3ParamType = void (*)(Time t, Sound s, Duration d);
auto setSoundB = std::bind(static_cast<SetAlarm3ParamType>(setAlarm), std::bind(std::plus<>(), steady_clock::now(), 1h), _1, 30s);

int main()
{
    std::cout << "Using lambda:\n";
    setSoundL(Sound::Siren);

    std::cout << "\nUsing std::bind:\n";
    setSoundB(Sound::Whistle);

    std::cout << "\n";

    const int lowVal = 10;
    const int highVal = 20;

    auto betweenL = [lowVal, highVal](const auto &val)
    {
        return lowVal <= val && val <= highVal;
    };

    auto betweenB = std::bind(
        std::logical_and<>(),
        std::bind(std::less_equal<>(), lowVal, _1),
        std::bind(std::less_equal<>(), _1, highVal));

    std::cout << "Using lambda: \n";
    std::cout << std::boolalpha << "Result: " << betweenL(14) << "\n\n";

    std::cout << "Using std::bind:\n";
    std::cout << std::boolalpha << "Result: " << betweenB(14) << "\n";

    return 0;
}