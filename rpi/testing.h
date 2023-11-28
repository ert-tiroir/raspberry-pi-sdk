
#include <vector>
#include <string>

struct TestCase_Information {
    std::string name;
    std::string group;

    bool operator< (const TestCase_Information &other) const;
};

struct TestCase {
    virtual void setup ();
    virtual bool run   ();

    virtual TestCase_Information getTestMetadata ();
};

struct TestRunner {
private:
    std::vector<TestCase*> test_cases;
public:
    void register_test (TestCase* test);
    void run_all       ();
};

typedef TestRunner* (*construct_runner) ();

void run_all (construct_runner test_runner_builder);
