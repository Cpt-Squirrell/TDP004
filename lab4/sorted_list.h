struct Sorted_List
{
    private:
    struct Link; // Forward-declare 'Link'
    
    public:
    Sorted_List();
    Sorted_List(const Sorted_List& other);
    Sorted_List(Sorted_List&& other);

    bool is_empty() const;
    int size() const;
    void insert(int value);
    void remove(int index);
    int  fetch (int index) const;
    void clear();
    void print() const;
    bool validateOrder() const;

    Sorted_List& operator=(const Sorted_List& rhs);
    bool operator==(const Sorted_List& rhs) const;

    private:
    struct Link
    {
        Link();
        Link(int value);
        Link(Link* next, int value);
        ~Link();
        void insert(int value);

        Link* p_next = nullptr;
        int value = 0;
    };

    Link* getLink(int depth) const;
    Link* root = nullptr;
};