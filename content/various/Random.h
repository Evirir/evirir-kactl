/**
 * Author: Evirir
 * Description: rawr o.=.o
 * Usage: rng() to generate random number, dis(rng) to use distribution.
 */
#pragma once

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int>(1,6)(rng);
uniform_int_distribution<> dis(1,6);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Custom hash for unordered_map: unordered_map<T,T,custom_hash> mp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
