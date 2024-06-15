#include <string>

namespace loremipsum
{

class Lorem {
public:
    Lorem() = default;
    ~Lorem() = default;

    [[nodiscard]]
    std::string ipsum();
};

}    
