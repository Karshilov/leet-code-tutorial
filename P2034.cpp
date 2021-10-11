class StockPrice {
public:
    map<int, int> mp;
    multiset<int> st;
    StockPrice() {
        mp = map<int, int>();
        st = multiset<int>();
    }
    
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            st.erase(st.lower_bound(mp[timestamp]));
            st.insert(price);
            mp[timestamp] = price;
        } else {
            st.insert(price);
            mp[timestamp] = price;
        }
    }
    
    int current() {
        auto it = mp.end();
        return (*(--it)).second;
    }
    
    int maximum() {
        auto it = st.end();
        return (*(--it));
    }
    
    int minimum() {
        return (*st.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */