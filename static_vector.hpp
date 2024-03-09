#include <array>
#include <format>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

namespace hw
{

using hw_size = long long;

template <typename T, hw_size Cap>
class static_vector
{
    std::array<T, Cap> m_data;
    hw_size m_size;

 public:
    static_vector() : m_size{0} {}

    static_vector(std::initializer_list<T> list) : m_size{std::ssize(list)}
    {
        if (list.size() > Cap) {
            throw std::invalid_argument(
                "Can't initialize static_vector with more arguments than its "
                "capacity");
        }

        for (int i = 0; const T& t : list) {
            m_data[i] = t;

            ++i;
        }
    }

    [[nodiscard]] constexpr T& operator[](hw_size i) const
    {
        static_assert(i < m_size);
        return m_data[i];
    }

    [[nodiscard]] T& operator[](hw_size i) { return m_data[i]; }

    [[nodiscard]] constexpr T& at(hw_size i) const
    {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range(std::format(
                "Invalid index access of static_vector (index = {}, size = {})",
                i, m_size));
        }

        return m_data[i];
    }

    [[nodiscard]] T& at(hw_size i)
    {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range(std::format(
                "Invalid index access of static_vector (index = {}, size = {})",
                i, m_size));
        }

        return m_data[i];
    }

    void push_back(T&& t)
    {
        if (m_size == Cap) { throw std::out_of_range("static_vector is full"); }
        m_data[m_size++] = std::move(t);
    }

    void push_back(const T& t)
    {
        if (m_size == Cap) { throw std::out_of_range("static_vector is full"); }
        m_data[m_size++] = t;
    }

    [[nodiscard]] constexpr hw_size size() const { return m_size; }

    [[nodiscard]] constexpr hw_size cap() { return Cap; }

    void pop_back() { --m_size; }

    [[nodiscard]] constexpr bool empty() { return m_size == 0; }

    [[nodiscard]] constexpr T* begin() { return m_data.begin(); }

    [[nodiscard]] constexpr T* end() { return std::next(begin(), m_size); }
};

template <typename T, typename... U>
static_vector(T, U...) -> static_vector<T, 1 + sizeof...(U)>;

} // namespace hw
