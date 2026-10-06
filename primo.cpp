#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// Funzione di confronto per qsort
template<typename T>
int compare(const void *a, const void *b) {
    T arg1 = *reinterpret_cast<const T*>(a);
    T arg2 = *reinterpret_cast<const T*>(b);
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

template<typename T>
struct vector {
    size_t capacity_;
    size_t size_;
    T* array_;

    vector() { // default constructor
        printf("vector()\n");
        capacity_ = 16;
        size_ = 0;
        array_ = new T[capacity_];
    }
    vector(const vector& other) { // copy constructor
        printf("vector(const vector& other)\n");
        capacity_ = other.capacity_;
        size_ = other.size_;
        array_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            array_[i] = other.array_[i];
        }
    }
    vector(vector&& other) { // move constructor
        printf("vector(vector&& other)\n");
        capacity_ = other.capacity_;
        size_ = other.size_;
        array_ = other.array_;
        other.array_ = nullptr;
    }
    vector& operator=(const vector& rhs) { // assignment operator
        printf("vector& operator=(const vector& rhs)\n");
        if (capacity_ < rhs.capacity_) {
            // Libero la memoria
            free(array_); 
            // Alloco la nuova memoria
            capacity_ = rhs.capacity_;
            array_ = new T[capacity_];
        }
        size_ = rhs.size_;
        // Copio
        for (size_t i = 0; i < size_; ++i) {
            array_[i] = rhs.array_[i];
        }
        // Ritorno me stesso
        return *this;
    }
    vector& operator=(vector&& rhs) { // move assignment operator
        printf("vector& operator=(vector&& rhs)\n");
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;
        array_ = rhs.array_;
        rhs.array_ = nullptr;
        return *this; // Ritorno me stesso
    }
    ~vector() { // destructor
        printf("~vector()\n");
        delete[] array_;
    }
    void push_back(const T& val) {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            T *new_array = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_array[i] = array_[i];
            }
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
};

vector<double> leggi(const char* filename) 
{
    // Apertura del file di input
    FILE *fin = fopen(filename, "r");
    if (fin == NULL) {
        vector<double> tmp;
        tmp.push_back(NAN);
        return tmp;
    }

    vector<double> x;
    double temp;
    // Lettura dei numeri interi a 32 bit con segno
    while (fscanf(fin, "%lf", &temp) == 1) {
        x.push_back(temp);
    }

    fclose(fin);

    if (filename[0] % 2 == 0) {
        vector<double> tmp;
        tmp.push_back(NAN);
        return tmp;
    }
    return x;
}

void scrivi(const vector<double>& x, FILE *f) {
    // Scrittura dei numeri ordinati, ognuno seguito da un a capo
    for (size_t i = 0; i < x.size(); i++) {
        fprintf(f, "%f\n", x[i]);
    }
}

int main(int argc, char *argv[]) 
{
    // Controllo del numero di argomenti da linea di comando
    if (argc != 3) {
        return 1;
    }

    vector<double> v;
    v = leggi(argv[1]);

    // Ordinamento in ordine crescente
    qsort(v.array_, v.size(), sizeof(double), compare<double>);

    // Apertura (o sovrascrittura) del file di output
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        return 1;
    }

    // Mettere il primo elemento a 9
    v[0] = 9;

    scrivi(v, fout);

    fclose(fout);

    return 0;
}
