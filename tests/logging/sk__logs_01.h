
#include <rpi/testing.h>

#include <rpi/iostream.h>

struct SK__LOGS_01 : public TestCase {
private:
    std::string expected_buffer = "EASY PRINTF\nPRINTF INTEGERS 5, 6\nPRINTF CHARACTER c\n";
public:
    void setup () override {}
    bool run   () override {
        printf("EASY PRINTF\n");
        printf("PRINTF INTEGERS %d, %lld\n", 5, (long long) 6);
        printf("PRINTF CHARACTER %c\n", 'c');

        std::string result = get_buffer(); clear_buffer();

        if (result != expected_buffer) {
            printf("Error, virtual printf did not have the expected behavior\n\n");
            printf("/****************** result ******************/\n%s\n", result.c_str());
            printf("/***************** expected *****************/\n%s\n", expected_buffer.c_str());
            
            return false;
        }

        return true;
    }

    TestCase_Information getTestMetadata () override {
        return { "SK__LOGS_01", "SDK Logging" };
    }
};
