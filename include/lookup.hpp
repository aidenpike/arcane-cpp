#ifndef LOOKUP_HPP
#define LOOKUP_HPP

#include <iostream>

namespace arcane {
    template <typename Key, typename Value>

    class lookup {
        public:
            using value_type = std::pair<Key, Value>;
            using container_type = std::vector<value_type>;
        
            using iterator = typename container_type::const_iterator;
            using const_iterator = iterator;

            lookup(std::initializer_list<value_type> init) : o_container(init){
                std::sort(o_container.begin(), o_container.end());
            }

            lookup(container_type container) : o_container(std::move(container)){
                std::sort(o_container.begin(), o_container.end());
            }

            const_iterator begin() const {
                return o_container.begin();
            }

            const_iterator end() const {
                return o_container.end();
            }

            template <typename K>
                const_iterator find(const K& key) const {
                    const_iterator it = std::lower_bound(
                        begin(),
                        end(),
                        key,
                        [](const value_type& p, const K& key){
                            return p.first < key;
                        }
                    );
                    return it != end() && it->first == key ? it : end();
                }
                
            size_t size() const {
                return o_container.size();
            }

        private:
            container_type o_container;
    };
}
#endif //LOOKUP_HPP