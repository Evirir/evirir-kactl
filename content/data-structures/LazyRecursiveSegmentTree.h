#pragma once

class LazySegmentTree {
private:
    int size_;
    vector<ll> v, lazy;

    void update(int s, int e, ll val, int k, int l, int r)
    {
        push(k, l, r);
        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            lazy[k] = val;
            push(k, l, r);
        }
        else
        {
            update(s, e, val, k * 2, l, (l + r) >> 1);
            update(s, e, val, k * 2 + 1, ((l + r) >> 1) + 1, r);
            v[k] = merge(v[k * 2], v[k * 2 + 1]);
        }
    }

    ll query(int s, int e, int k, int l, int r)
    {
        push(k, l, r);
        if (r < s || e < l)
            return 0; // dummy value
        if (s <= l && r <= e)
            return v[k];
        ll lc = query(s, e, k * 2, l, (l + r) >> 1);
        ll rc = query(s, e, k * 2 + 1, ((l + r) >> 1) + 1, r);
        return merge(lc, rc);
    }

public:
    LazySegmentTree() : v(vector<ll>()), lazy(vector<ll>()) {}
    LazySegmentTree(int n)
    {
        for (size_ = 1; size_ < n;)
            size_ <<= 1;
        v.resize(size_ * 4);
        lazy.resize(size_ * 4);
    }
    void reset()
    {
        v.assign(size_ * 4, 0);
        lazy.assign(size_ * 4, 0);
    }
    inline void push(int k, int l, int r)
    {
        if (lazy[k] != 0)
        {
            v[k] += (r - l + 1) * lazy[k]; // remember to consider the range!
            if (l != r)
            {
                lazy[k * 2] += lazy[k];
                lazy[k * 2 + 1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    inline ll merge(ll x, ll y)
    {
        return x + y;
    }
    inline void update(int l, int r, ll val)
    {
        update(l, r, val, 1, 0, size_ - 1);
    }
    inline ll query(int l, int r)
    {
        return query(l, r, 1, 0, size_ - 1);
    }
};
