#include <iostream>

static void print(int x, int y)
{
    std::cout << "(" << x << ", " << y << ")\n";
}

int main()
{
    constexpr auto call_cart (
        [=] (auto fpint, auto x, auto ...rest) constexpr {
            (void)std::initializer_list<int>{
                (/*((x < rest) ? */(void)fpint(x, rest)/* 
                : (void)0)*/, 0)...
            };
        });
    
    constexpr auto cartesian ( [=](auto ...xs) constexpr {
        return [=] (auto fprint) constexpr {
            (void)std::initializer_list<int>{
                ((void) call_cart(fprint, xs, xs...), 0)...
            };
        };
    });

    constexpr auto print_cart (cartesian(1, 2, 3));

    print_cart(print);
}