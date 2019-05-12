#include<utility>
#include<iostream>

template<class T>
T gen(T ex) {
    return ex;
}

template<class T, class Fn = decltype(gen<T>)>
std::pair<T, T> get2(T ex, const Fn & gn = gen<T>) {
    return std::make_pair(gn(ex), gn(ex));
}

int main() {
    auto t = get2(2, [](int x) {return x * x;});
    std::cout << t.first << ' ' << t.second;
}
