#ifndef PUSH_BACK_STREAM_HPP
#define PUSH_BACK_STREAM_HPP

#include <stack>
#include <functional>

namespace arcane {
    class push_back_stream {
        public:
            using get_character = std::function<int()>;

            push_back_stream(const get_character& input);

            int operator()();

            void push_back(int);

            size_t line_number() const;
            size_t char_index() const;
        private:
            const get_character& o_input;
            std::stack<int> o_stack;
            size_t o_line_number;
            size_t o_char_index;
    };
}

#endif //PUSH_BACK_STREAM_HPP