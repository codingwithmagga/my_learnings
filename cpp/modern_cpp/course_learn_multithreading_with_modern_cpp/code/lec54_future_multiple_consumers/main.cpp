#include <chrono>
#include <future>
#include <iostream>

using namespace std;

mutex coutMut;

void produce(std::promise<int>& px)
{

    this_thread::sleep_for(2s);
    cout << "Produced the result" << endl;

    if (false) {
        px.set_exception(std::make_exception_ptr(out_of_range("Patz")));
        return;
    }

    px.set_value(42);
}

void consumer(std::shared_future<int>& fut)
{
    cout << "try to get result" << endl;
    try {
        auto val = fut.get();

        scoped_lock lck(coutMut);
        cout << "got val " << val << endl;
    } catch (std::exception& e) {
        cout << "caught exception: " << e.what() << endl;
    }
}

int main()
{

    promise<int> px;
    std::shared_future<int> fut = px.get_future();

    jthread prod(produce, ref(px));
    jthread cons(consumer, ref(fut));
    jthread cons1(consumer, ref(fut));
    jthread cons2(consumer, ref(fut));

    return 0;
}
