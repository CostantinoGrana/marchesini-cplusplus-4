#include <cassert>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <iterator>
#include <string>
#include <print>

#include <map>
#include <unordered_map>

/*
template<typename T>
class vector {
    size_t capacity_;
    size_t size_;
    T* array_;
public:
    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() { std::cout << "begin()\n"; return array_; }
    const_iterator begin() const { std::cout << "begin() const\n"; return array_; }
    iterator end() { std::cout << "end()\n"; return array_ + size_; }
    const_iterator end() const { std::cout << "end() const\n"; return array_ + size_; }

    vector() { // default constructor
        std::cout << "vector()\n";
        capacity_ = 16;
        size_ = 0;
        array_ = new T[capacity_];
    }
    vector(const vector& other) { // copy constructor
        std::cout << "vector(const vector& other)\n";
        capacity_ = other.capacity_;
        size_ = other.size_;
        array_ = new T[capacity_];
        std::copy_n(other.array_, size_, array_);
    }
    vector(vector&& other) noexcept { // move constructor
        std::cout << "vector(vector&& other)\n";
        capacity_ = other.capacity_;
        size_ = other.size_;
        array_ = other.array_;
        other.array_ = nullptr;
    }
    // Copy and Swap Idiom
    vector& operator=(vector rhs) { // assignment/move assignment operator
        swap(*this, rhs);
        return *this;
    }
    ~vector() { // destructor
        std::cout << "~vector()\n";
        delete[] array_;
    }
    void push_back(const T& val) {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            T *new_array = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_array[i] = array_[i];
            }
            delete[] array_;
            array_ = new_array;
        }
        array_[size_++] = val;
    }
    size_t size() const {
        return this->size_;
    }    

    T& operator[](size_t pos) {
        return const_cast<T&>(
            static_cast<const vector*>(this)->operator[](pos)
        );
    }
    const T& operator[](size_t pos) const {
        return array_[pos];
    }

    T& at(size_t pos) {
        assert(pos < size_);
        return array_[pos];
    }
    const T& at(size_t pos) const {
        assert(pos < size_);
        return array_[pos];
    }

    template<typename T>
    friend void swap(vector<T>& a, vector<T>& b) {
        using std::swap; // Enables ADL
        swap(a.capacity_, b.capacity_);
        swap(a.size_, b.size_);
        swap(a.array_, b.array_);
    }
};
*/

template<typename T>
std::vector<T> leggi(const char* filename) 
{
    std::vector<T> x;
    std::ifstream is(filename /*, std::ios::binary*/);
    if (is) {
        T temp;
        while (is >> temp) {
            x.push_back(temp);
        }
    }
    return x;
}

template<typename T>
void scrivi(const std::vector<T>& x, std::ostream& os) {
    using std::dec, std::hex;
    using std::setfill, std::setw;
    /*
    for (auto it = x.begin(), stop = x.end(); it != stop; ++it) {
        const auto& val = *it;
        os << dec << val << '\t' << hex << setfill('0') << setw(8) << val << '\n';
    }
    */
    for (const auto& val : x) {
        os << dec << val << '\t' << hex << setfill('0') << setw(8) << val << '\n';
    }

}

bool confronta(double a, double b) {
    return a > b;
}

// primo(6.5,7.6)
// secondo(8.1, 3.456)
// prova(91.82, 5)
struct namedpoint {
    std::string name_;
    double x_, y_;
};

std::ostream& operator<<(std::ostream& os, const namedpoint& p) {
    return os << p.name_ << '(' << p.x_ << ',' << p.y_ << ')';
}

std::istream& operator>>(std::istream& is, namedpoint& p) {
    char ap, v, cp;
    is >> std::ws;
    p.name_.clear();    
    if (!std::getline(is, p.name_, '(')) {
        return is;
    }
    is >> p.x_ >> v >> p.y_ >> cp;
    if (!is || v != ',' || cp != ')') {
        is.setf(std::ios::failbit);
    }
    return is;
}

int main(int argc, char *argv[]) 
{
    namedpoint uno("primo", 6.5, 7.6);

    std::cout << uno << "\n";

    std::vector<namedpoint> a;
    a.push_back(namedpoint("primo", 6.5, 7.6));
    a.push_back({"secondo", 8.1, 3.456});
    a.push_back(namedpoint("prova", 91.82, 5));
    a.push_back(namedpoint{"prova", 91.82, 5});
    a.push_back({"prova", 91.82});
    a.emplace_back("prova", 91.82, 5);

    std::copy(a.begin(), a.end(), std::ostream_iterator<namedpoint>(std::cout, "\n"));

    std::stringstream ss(R"(primo(6.5,7.6)
secondo(8.1, 3.456)
prova(91.82, 5))");
    ss >> uno;
    ss >> uno;
    ss >> uno;
    ss >> uno;

    /*
    int a = 54, b = 23;
    std::println("Il prodotto di {:x} per {:^10} fa {}.", a, b, a*b);
    */

    std::unordered_map<std::string, int> dict;
    dict["prova"] = 34;
    dict["test"] = 78;
    dict["altro"] = 23;

    for (const auto& x : dict) {
        std::cout << x.first << '\t' << x.second << '\n';
    }

    auto it = dict.find("prova");
    if (it != dict.end()) {
        std::cout << it->second << '\n';
    }
    else {
        dict["prova"] = 0;
    }





    // Controllo del numero di argomenti da linea di comando
    if (argc != 3) {
        return 1;
    }

    std::ifstream is(argv[1] /*, std::ios::binary*/);
    if (!is) {
        return 1;
    }
    // std::vector<int> v( std::istream_iterator<int>(is) , std::istream_iterator<int>() );
    // The most vexing parse
    std::vector<int> v{ std::istream_iterator<int>(is) , std::istream_iterator<int>() };

    // Ordinamento in ordine crescente
    //qsort(v.array_, v.size(), sizeof(double), compare<double>);
    std::sort(v.begin(), v.end(), confronta);

    // Apertura (o sovrascrittura) del file di output
    std::ofstream os(argv[2] /*, std::ios::binary*/);
    if (!os) {
        return 1;
    }
    scrivi(v, os); // ADL = Argument Dependant Lookup
    scrivi(v, std::cout); 
       
    return 0;
}
