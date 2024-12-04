#include <iostream>
#include <map>
#include <array>

// Replace `unsigned long` with `auto` where possible in pentagonal array
std::array<unsigned long, 500> pentagonal;// cannot replace unsigned long with Auto 

auto partition(unsigned long n) {
    // `auto` can be used for `memoization`, but it must be a `std::map<unsigned long, unsigned long>`
    // since `auto` cannot infer this nested structure directly from the initializer.
    static std::map<unsigned long, unsigned long> memoization = {{0, 1}, {1, 1}};
    
    // Iterator type can be `auto` in this context
    auto const it = memoization.find(n);
    
    // `it` must be checked against `memoization.cend()` using this type, so `auto` is fine here
    if (it != memoization.cend()) {
        return it->second; // cannot replace it->second with auto; it->second's type depends on the map's type
    }

    auto partitions{0l}; // auto here is okay as long as partitions is initialized as long
    for (auto k{1};; ++k) {
        auto const sign = ((k + 1) / 2) % 2 == 0 ? -1 : 1;
        
        // Use auto for `pent`
        auto const pent = pentagonal[k];
        
        if (n < pent) {
            break;
        }
        
        partitions += sign * partition(n - pent);
    }

    // modulo to keep partitions within 1,000,000
    partitions = partitions % 1'000'000;
    if (partitions < 0) {
        partitions += 1'000'000;
    }
    
    // Explicit cast is needed to return the expected unsigned long type
    memoization.emplace(n, partitions);
    return static_cast<unsigned long>(partitions);
}

auto problem() {
    // Use `auto` in `k` and `j` variables
    auto k{1};
    for (auto j{1ul}; j < pentagonal.size(); ++j) {
        pentagonal[j] = static_cast<unsigned long>(k * (3 * k - 1) / 2);
        
        // Toggle `k` between positive and negative
        if (k > 0) {
            k = -k;
        } else {
            k = -k + 1;
        }
    }

    // `n` can be auto here
    auto n{0ul};
    while (true) {
        auto const p = partition(n);
        if (p == 0) {
            return n;
        }
        ++n;
    }
}

int main() {
    // Call problem and store the result in solution using `auto`
    auto solution = problem();
    std::cout << solution << '\n';
    return 0;
}

// 12 autos are present 

