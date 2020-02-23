template <typename T> class property {
        T value;
    public:
        T & operator = (const T &i) {
            return value = i;
        }
        // This template class member function template serves the purpose to make
        // typing more strict. Assignment to this is only possible with exact identical
        // types.
        template <typename T2> T2 & operator = (const T2 &i) {
            T2 &guard = value;
            throw guard; // Never reached.
        }

        // Implicit conversion back to T. 
        operator T const & () const {
            return value;
        }
};