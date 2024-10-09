struct Stack {

    private:
        int* _pValues;

    public:
        int _size;

        Stack(int size) {
            _pValues = new int[size];
            _size = size;
        }

        Stack(const Stack& other) {
            _pValues = new int[other.size];
            _size = other.size;
            for (int i =0; i < size; i++) {
                _pValues[i] = other._pValues[i];
            }
        }

        ~Stack(){
            delete[] _pValues;
        }

        Stack& operator=(const Stack& other) {
            if(this == &other) {
                return this;
            }

            delete[] _pValues;
            _pValues = new int[other.size];
            _size = other.size;
            for (int i =0; i < size; i++) {
                _pValues[i] = other._pValues[i];
            }
        }

        void push(int value) {

        }

        bool isEmpty() const {
            return true;
        }
};