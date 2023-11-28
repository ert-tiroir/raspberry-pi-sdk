
#include <rpi/testing.h>

bool TestCase_Information::operator< (const TestCase_Information &other) const {
    if (group == other.group) return name < other.name;
    return group < other.group;
}

void TestCase::setup () {               }
bool TestCase::run   () { return false; }

TestCase_Information TestCase::getTestMetadata () {
    return { "NAME", "GROUP" };
}
