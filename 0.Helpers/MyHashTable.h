#include <iostream>
#include <vector>
using namespace std;

template<class K, class V>
struct Bucket {
    K key;
    V val;
    Bucket(const K& k, const V& v) : val(v), key(k) {}
};

template<class T> class MyHashGenerator {
public:
    static size_t HashFunction(T key) {
        return hash<T>()(key);
    }
};

template<> class MyHashGenerator<string> {
public:
    static size_t HashFunction(const string& s) {
        return hash<string>()(s);
    }
};

template<> class MyHashGenerator<int> {
public:
    static size_t HashFunction(const int m) {
        return hash<int>()(m);
    }
};

template<> class MyHashGenerator<char> {
public:
    static size_t HashFunction(const char& c) {
        return hash<char>()(c);
    }
};



template<class K, class V, class HashGenerator = MyHashGenerator<K>>
class MyHashTable {
public:
    vector<vector<Bucket<K, V> > > table;

    MyHashTable(int size) {
        for (int i = 0; i < size; i++) {
            vector<Bucket<K, V> > v;
            table.push_back(v);
        }
    }
    ~MyHashTable() {}
    void set(const K& k, const V& v) {
        Bucket<K, V> b(k, v);
        for (int i = 0; i < table[hash(k)].size(); i++)
            if (table[hash(k)][i].key == k) {
                table[hash(k)][i] = b;
                return;
            }
        table[hash(k)].push_back(b);
    }
    V get(const K& k) {
        for (int i = 0; i < table[hash(k)].size(); i++)
            if (table[hash(k)][i].key == k)
                return table[hash(k)][i].val;
    }
    bool exist(const K& k) {
        for (int i = 0; i < table[hash(k)].size(); i++)
            if (table[hash(k)][i].key == k)
                return true;
        return false;
    }
    void remove(const K& k) {
        for(int i=0;i<table[hash(k)].size();i++){
            if (table[hash(k)][i].key == k)
                table.erase(table[hash(k)]);
        }
    }
    auto hash(const K& k) {
        return HashGenerator::HashFunction(k) % table.size();
    }
};


