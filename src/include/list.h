#ifndef INCLUDE_LIST_H
#define INCLUDE_LIST_H

#include <type_traits>
#include <iterator>
#include <initializer_list>
#include <memory>


namespace saxion {

    //forward declarations of classes
    template<typename _T>
    class list;

    namespace detail {
        template<typename _T, typename _Nd>
        struct list_iterator;

        template<typename _T, typename _Nd>
        struct const_list_iterator;
    }

    // normally all the things that are not intended for public use are grouped in an internal namespace (often "detail")
    namespace detail {

        template<typename _T>
        struct list_node_t {
            template<typename T> friend
            class ::saxion::list;

            _T _value;
            list_node_t* _prev;
            std::unique_ptr<list_node_t> _next;

            // copying of nodes is not possible
            list_node_t(const list_node_t&) = delete;
            list_node_t& operator&(list_node_t&) = delete;

            // moving is possible
            list_node_t(list_node_t&& other) noexcept = default;
            list_node_t& operator=(list_node_t&& other) noexcept = default;

            ~list_node_t(){
                // if a node owns itself, resolve it by releasing this ownership
                // destructor is called before the automatic objects are destroyed, so
                // we can safely resolve the circular ownership before _next will be destroyed

                if (_next.get() == this){
                    _next.release();
                }
            }

            // constrcutors
            list_node_t():
                _value(),
                _prev(nullptr),
                _next(nullptr){
            }

            list_node_t(_T&& v, list_node_t* prev) :
                    list_node_t{std::move(v), prev, nullptr} {}

            list_node_t(_T const& v, list_node_t* prev) :
                    list_node_t{v, prev, nullptr} {}

            list_node_t(_T&& v, list_node_t* prev, list_node_t* next) :
                    _value{std::move(v)},
                    _prev{prev},
                    _next{next} {}

            list_node_t(_T const& v, list_node_t* prev, list_node_t* next) :
                    _value{v},
                    _prev{prev},
                    _next{next} {}

            void swap(list_node_t& other) noexcept {
                std::swap(_prev, other._prev);
                std::swap(_next, other._next);
                std::swap(_value, other._value);
            }

            _T& value() {
                return _value;
            }

            _T const& value() const {
                return _value;
            }

            // a helper function that returns a pointer to the next node
            [[nodiscard]]
            list_node_t* next() const noexcept{
                return _next.get();
            }

            // a helper function that returns a pointer to the previous node
            [[nodiscard]]
            list_node_t* prev() const noexcept{
                return _prev;
            }
        };

        // the list iterator implementation
        template<typename _T, typename _Nd = list_node_t<_T>>
        struct list_iterator {
            using difference_type = std::ptrdiff_t;
            //todo: fix the iterator category - it's wrong  ???
//            using iterator_category = std::forward_iterator_tag;
            using iterator_category = std::bidirectional_iterator_tag;
            using pointer = _T*;
            using reference = _T&;
            using value_type = _T;

            template<typename> friend
            class ::saxion::list;

            using node_t = _Nd;

            // a pointer to the current node of this iterator
            node_t* _current;

            // a convenience function to access the node
            node_t* node() {
                return _current;
            }

            const node_t* node() const {
                return _current;
            }

            // never to be used constrcutor!
            // it is only here so we can default initalize an invalid iterator
            list_iterator() noexcept:
                _current(nullptr)
            {}

            // constructor
            explicit list_iterator(node_t* element) noexcept:
                    _current(element) {}

            // conversion from the constant iterator
            explicit list_iterator(const const_list_iterator<_T, _Nd>& iter) noexcept:
                    _current(const_cast<node_t*>(iter._current)) {
            }

            // dereferencing
            reference operator*() const {
                return _current->value();
            }

            [[nodiscard]]
            pointer operator->() const {
                return std::addressof(_current->value);
            }

            // iterating
            list_iterator& operator++() {
                _current = _current->_next.get();
                return *this;
            }

            list_iterator operator++(int) {
                list_iterator tmp(*this);
                ++(*this);
                return tmp;
            }

            list_iterator& operator--() {
                // todo: this operation needs to step back in the list  ???
                _current = _current->_prev;
                return *this;
            }

            list_iterator operator--(int) {
                list_iterator tmp(*this);
                // todo: this operation needs to step back in the list  ???
                --(*this);
                return tmp;
            }

            [[nodiscard]]
            bool operator==(const list_iterator& other) const {
                return _current == other._current;
            }

            [[nodiscard]]
            bool operator!=(const list_iterator& other) const {
                return !(*this == other);
            }
        };

        template<typename _T, typename _Nd = list_node_t<_T>>
        struct const_list_iterator {
            using difference_type = std::ptrdiff_t;
            //todo: fix the iterator category - it's wrong      ???
//            using iterator_category = std::forward_iterator_tag;
            using iterator_category = std::bidirectional_iterator_tag;
            using pointer = const _T*;
            using reference = const _T&;
            using value_type = _T;

            template<typename> friend
            class ::saxion::list;

            using node_t = _Nd;

            const node_t* _current;

            const node_t* node() const {
                return _current;
            }

            // never to be used constrcutor!
            // it is only here so we can default initalize an invalid iterator
            const_list_iterator():
                _current(nullptr)
            {}

            explicit const_list_iterator(const node_t* element) noexcept:
                    _current(element) {}

            explicit const_list_iterator(const list_iterator<_T, _Nd>& iter) noexcept:
                    _current(iter._current) {
            }

            reference operator*() const {
                return _current->value();
            }

            [[nodiscard]]
            pointer operator->() const {
                return std::addressof(_current->value);
            }

            const_list_iterator& operator++() {
                // todo: this operation needs to move forward in the list   ???
                _current = _current->_next.get();
                return *this;
            }

            const_list_iterator operator++(int) {
                const_list_iterator tmp(*this);
                // todo: this operation needs to move forward in the list   ???
                ++(*this);
                return tmp;
            }

            const_list_iterator& operator--() {
                // todo: this operation needs to step back in the list      ???
                _current = _current->_prev;
                return *this;
            }

            const_list_iterator operator--(int) {
                // todo: this operation needs to step back in the list      ???
                // and return a correct iterator
                --(*this);
                return *this;
            }

            [[nodiscard]]
            bool operator==(const const_list_iterator& other) {
                return _current == other._current;
            }

            [[nodiscard]]
            bool operator!=(const const_list_iterator& other) {
                return !(*this == other);
            }

        };

        // comparison operators
        template <typename _T, typename _Nd>
        [[nodiscard]]
        inline bool operator==(const list_iterator<_T, _Nd>& lhs, const const_list_iterator<_T, _Nd>& rhs) {
            return lhs._current == rhs._current;
        }

        template <typename _T, typename _Nd>
        [[nodiscard]]
        inline bool operator!=(const list_iterator<_T, _Nd>& lhs, const const_list_iterator<_T, _Nd>& rhs) {
            return !(lhs == rhs);
        }
    }

    // here begins the list implementation
    template<typename _T>
    class list {
    public:
        using value_type = _T;
        using reference = _T&;
        using const_reference = _T const&;
        using pointer = _T*;
        using const_pointer = _T const*;
        using size_type = std::size_t;

    private:

        // for convenience: define a node type
        using node_t = detail::list_node_t<_T>;

        // the sentinel node
        node_t _node;
        //size of the list
        size_type _size;
        // notice that there is no _tail pointer - it is not needed in a doubly-linked list with a sentinel node

        [[nodiscard]]
        node_t* head() const noexcept{
            // this is how we obtain a pointer to the head of the list
            return _node.next();
        }

        [[nodiscard]]
        node_t* tail() const noexcept{
            // todo: this should return a pointer to the last element of the list. Use the sentinel node for this.      ???

            return _node._prev;
        }

    public:

        using iterator = detail::list_iterator<_T, node_t>;
        using const_iterator = detail::const_list_iterator<_T, node_t>;

        // default ctor
        list() :
                _node{},
                _size{0} {
            //empty list has a self-referencing node!
            _node._prev = &_node;
            _node._next.reset(&_node);
        }

        template<typename _V>
        list(std::initializer_list<_V> init_list) :
                list() {
//            (void)init_list; // remove this one
            // todo: initialize the content with that of init_list  ???
            for (auto item : init_list) {
                push_back(std::move(item));
            }
        }

        // copy ctor
        list(const list& other) :
                list() {
//            (void)other; //remove this one
            // todo: copy the other list's content  ???

            for (node_t* other_next{other.head()};
                 other_next->next() != other.head();
                 other_next = other_next->next()) {

                push_back(other_next->value());
            }
        }

        // copy assignment operator
        list& operator=(const list& other) {
//            (void)other;    //remove this one!
            // todo: implement the copy assignment operator ???
            if (this != &other) {
                clear();
                for (auto current = other.begin(); current != other.end(); ++current) {
                    push_back(*current);
                }
            }
            return *this;

        }

        // move ctor
        list(list&& other) noexcept :
                list() {
//            (void)other; //remove this one
            // todo: implement the move ctor    ???
            swap(other);
        }

        // move assignment operator
        list& operator=(list&& other) noexcept {
//            (void)other;    //remove this one
            // todo: implement the move ctor    ???
            if (this != &other) {
                clear();
                swap(other);
            }
            return *this;
        }

        template<typename _Iter, typename = std::enable_if_t<
                std::is_same_v<
                        typename std::iterator_traits<_Iter>::value_type,
                        value_type >>>
        list(_Iter begin, _Iter end):
                list() {
//            (void)begin;    //remove this one
//            (void)end;      //remove this one
            // todo: implement the constructor that takes two iterators     ???
            for (; begin != end; ++begin) {
                push_back(*begin);
            }
        }

        [[nodiscard]]
        iterator begin() noexcept {
            // todo: return the iterator to head    ???
            return iterator(_node.next());
        }

        [[nodiscard]]
        iterator end() noexcept {
            // todo: return the iterator to past-the-list element   ???
            return iterator(&_node);//   _node.prev() ?
        }

        [[nodiscard]]
        const_iterator begin() const noexcept {
            // todo: return the iterator to head    ???
            return const_iterator(_node.next());
        }

        [[nodiscard]]
        const_iterator end() const noexcept {
            // todo: return the iterator to past-the-list element   ???
            return const_iterator(&_node);//   &_node ?
        }

        [[nodiscard]]
        const_iterator cbegin() const noexcept {
            // todo: return the iterator to head    ???
            return const_iterator(_node.next());
        }

        [[nodiscard]]
        const_iterator cend() const noexcept {
            // todo: return the iterator to past-the-list element   ???
            return const_iterator(&_node);//   &_node ?
        }


        void swap(list& other) noexcept {
//            (void)other;    //remove this one!
            // todo: ! add swapping of the pointers and nodes   ???
            std::swap(head()->_prev, other.head()->_prev);
            _node.swap(other._node);
            std::swap(tail()->_next, other.tail()->_next);
            std::swap(_size, other._size);
        }

        // todo: remove this if no longer needed - it is only used as return value
        // for not implemented functions
//        value_type dummy_value = value_type();

        // accessors
        [[nodiscard]]
        reference front() {
            // todo: return the first value in the list     ???
            return *begin();
        }

        [[nodiscard]]
        const_reference front() const {
            // todo: return the first value in the list     ???
            return head()->value();
        }

        [[nodiscard]]
        reference back() {
            // todo: return the last value in the list      ???
            return tail()->value();
        }

        [[nodiscard]]
        const_reference back() const {
            // todo: return the last value in the list      ???
            return tail()->value();
        }

        [[nodiscard]]
        reference operator[](size_type index) {
//            (void)index;    //remove this one!
            // todo: return the value at index  ???
            node_t* current = head();
            while (index--) { current = current->next(); }
            return current->value();
//            return dummy_value;
        }

        [[nodiscard]]
        const_reference operator[](size_type index) const {
//            (void)index;    //remove this one!
            // todo: return the value at index      ???
            node_t* current = head();
            while (index--) { current = current->next(); }
            return current->value();
//            return dummy_value;
        }

        [[nodiscard]]
        reference at(size_type index) {
//            (void)index;    //remove this one!
            // todo: return the value at index or throw     ???
            if (index < _size) {
                node_t* current = head();
                while (index--) { current = current->next(); }
                return current->value();
            }
            throw std::length_error("index out of bounds");
//            return dummy_value;
        }

        [[nodiscard]]
        const_reference at( size_type index) const {
//            (void)index;    //remove this one!
            // todo: return the value at index or throw     ???
            if (index < _size) {
                node_t* current = head();
                while (index--) { current = current->next(); }
                return current->value();
            }
            throw std::length_error("index out of bounds");
//            return dummy_value;
        }

        void pop_front() noexcept {
            // todo: remove the first element from the list
            if (begin() != end()) {
                _node._next = std::move(_node._next->_next);
                if (--_size == 0){
                }
            }
        }

        void pop_back() noexcept {
            // todo: remove the last element from the list
            if (begin() != end()) {
                _node._prev = std::move(_node._prev->_prev);
                if (--_size == 0){
                }
            }

        }

        [[nodiscard]]
        bool empty() const {
            // todo: return something that makes sense      ???
            return _size == 0;;
        }

        [[nodiscard]]
        size_type size() const {
            return _size;
        }

        void clear() noexcept {
           // todo: remove all the elemenets from the list  ???
            if (begin() != end()) {
                // unlink the nodes iteratively
                while (head() != &_node) {
                    _node._next = std::move(_node._next->_next);
                    --_size;
                }
                _size = 0;
            }
        }

        ~list() noexcept {
            _node._prev->_next.release();
          // todo: implement the removal of all the nodes (is it really needed?)
        }

        // modifiers
        iterator push_back(_T&& value) {
//            (void)value;    //remove this one!
            // todo: implement adding an element to the end of the list     ???

            tail()->_next = std::make_unique<node_t>(std::move(value), tail(), tail()->_next.release());
            _node._prev = tail()->next();
            ++_size;
            return iterator(tail());
        }

        iterator push_back(const_reference value) {
//            (void)value;    //remove this one!
            // todo: implement adding an element to the end of the list     ???
            tail()->_next = std::make_unique<node_t>(value, tail(), tail()->_next.release());
            _node._prev = tail()->next();
            ++_size;
            return iterator(tail());
        }

        template<typename... Args>
        iterator emplace_back([[maybe_unused]]Args&& ... args) {
            // todo: ! implement constructing a node in-place at the end    ???

            tail()->_next = std::make_unique<node_t>(_T(std::forward<Args>(args)...), tail() ,tail()->_next.release());
            _node._prev = tail()->next();
            ++_size;
            return iterator(tail());
        }

        template<typename V>
        iterator push_front(V&& value) {
//            (void)value;    //remove this one!
            // todo: implement adding an element at the front of the list   ???
            auto* first_node = head();
            _node._next = std::make_unique<node_t>(std::forward<V>(value), &_node, _node._next.release());
            //_node.next()->next()->_prev = tail()->next()->next(); //head()->prev();
            first_node->_prev = head();
            ++_size;
            // notice that this function template takes a forwarding reference
            return iterator(head());
        }

        iterator erase(iterator pos) {
//            (void)pos;    //remove this one!
            // todo: !! implement a function that removes an element pointed to by pos iterator
            // this function should return an iterator to the next element after the one that was removed
            if (begin()!=end()) {
                auto* iter_Pos = pos.node()->next();
                pos.node()->_next->_prev = pos.node()->_prev;
                pos.node()->_prev->_next = std::move(pos.node()->_next);
                --_size;
                return iterator(iter_Pos);
            }
            return end();
        }

        // insert element before pos
        // returns iterator to inserted element
        iterator insert(iterator pos, const_reference value) {
//            (void)pos;    //remove this one!
//            (void)value;    //remove this one!
            // todo: !! implement inserting an element begore the element pointed to by pos iterator
            // this function returns an iterator to the inserted element
            pos.node()->_prev->_next = std::make_unique<node_t>(value, pos.node()->_prev, pos.node()->_next.release());
            pos.node()->_prev = pos.node()->_prev->next();
            ++_size;
            return iterator(pos.node()->_prev);
//            return iterator();
        }

        // r-value reference overload
        iterator insert(iterator pos, _T&& value) {
//            (void)pos;    //remove this one!
//            (void)value;    //remove this one!
            // todo: !! implement inserting an element before the element pointed to by pos iterator
            // this function returns an iterator to the inserted element
            pos.node()->_prev->_next = std::make_unique<node_t>(std::move(value) , pos.node()->_prev, pos.node()->_next.release());
            pos.node()->_prev = pos.node()->_prev->next();
            ++_size;
            return iterator(pos.node()->_prev);
//            return iterator();
        }

        template<typename... Args>
        iterator emplace(iterator pos, [[maybe_unused]] Args&& ... args) {
//            (void)pos;    //remove this one!
            // todo: !! implement emplacing an element before the element pointed to by pos iterator
            // this function returns an iterator to the inserted element
            // this function constructs element in-place

//            auto* new_node = pos.node()._prev;


            pos.node()->_prev->_next = std::make_unique<node_t>(_T(std::forward<Args>(args)...), pos.node()->_prev, pos.node()->_next.release());
            if(_size++ == 0){
                pos.node()->_prev = pos.node()->_prev->next();
            }
            return iterator(_node.next());
        }

    };

    template<typename _Iter>
    list(_Iter b, _Iter e) -> list<typename std::iterator_traits<_Iter>::value_type>;

    template<typename _V>
    list(std::initializer_list<_V>) -> list<_V>;

    list(std::initializer_list<const char*>) -> list<std::string>;

}

namespace std{
    template<typename _T>
    inline void swap(saxion::list<_T>& x, saxion::list <_T>& y) noexcept {
        x.swap(y);
    }
}


#endif
